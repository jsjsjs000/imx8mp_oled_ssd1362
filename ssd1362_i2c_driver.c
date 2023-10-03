	/* Freescale includes. */
#include <fsl_device_registers.h>
#include <fsl_debug_console.h>
#include <fsl_i2c.h>
#include <fsl_i2c_freertos.h>

	/* FreeRTOS kernel includes. */
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <timers.h>
#include <semphr.h>

#include "common.h"
#include "font.h"
#include "ssd1362_i2c_driver.h"
#include "i2c_task.h"

static uint16_t last_string_x1 = 0;
static uint16_t last_string_y1 = 0;
static uint16_t last_string_x2 = 0;
static uint16_t last_string_y2 = 0;

static uint8_t oled_buffer[OLED_WIDTH * OLED_HEIGHT * OLED_COLOR_BITS / 8] = { 0 };

static const uint8_t Init_ssd1362_registers[] =
{
	2, 0xfd, 0x12,        /// Set Command Lock (12H=Unlock,16H=Lock)
	1, 0xae,              /// Display OFF(Sleep Mode)
	3, 0x15, 0x00, 0x7f,  /// Set column Address, Start column Address, End column Address
	3, 0x75, 0x00, 0x7f,  /// Set Row Address, Start Row Address, End Row Address
	2, 0x81, 0x2f,        /// Set contrast
	// 2, 0xa0, 0xc3,     /// Set Remap - normal
	// 2, 0xa0, 0xd0,     /// Set Remap - rotated 180 degrees
	2, 0xa1, 0x00,        /// Set Display Start Line
	2, 0xa2, 0x00,        /// Set Display Offset
	1, 0xa4,              /// Normal Display
	2, 0xa8, 0x3f,        /// Set Multiplex Ratio
	2, 0xab, 0x01,        /// Set VDD regulator, Regulator Enable
	2, 0xad, 0x8e,        /// External /Internal IREF Selection
	2, 0xb1, 0x22,        /// Set Phase Length
	2, 0xb3, 0xa0,        /// Display clock Divider
	2, 0xb6, 0x04,        /// Set Second pre-charge Period
	1, 0xb9,              /// Set Linear LUT
	2, 0xbc, 0x04,        /// Set pre-charge voltage level, 0.15*Vcc
	2, 0xbd, 0x01,        /// Pre-charge voltage capacitor Selection
	2, 0xbe, 0x07,        /// Set COM deselect voltage level, 0.82*Vcc
};

static bool ssd1362_i2c_driver_write_command(uint8_t *data, size_t data_size);

bool ssd1362_i2c_driver_initialize(bool rotate_display_180)
{
	uint b = 0;
	uint8_t command[64];
	while (b < sizeof(Init_ssd1362_registers))
	{
		size_t count = Init_ssd1362_registers[b++];
		for (uint i = 0; i < count; i++)
			command[i] = Init_ssd1362_registers[b++];

		if (!ssd1362_i2c_driver_write_command(command, count))
			return false;
	}

	command[0] = 0xa0;											/// Set Remap
	command[1] = rotate_display_180 ? 0xd0 : 0xc3;
	if (!ssd1362_i2c_driver_write_command(command, 2))
		return false;

	vTaskDelay(pdMS_TO_TICKS(OLED_TAF_DELAY_MS));

	return true;
}

bool ssd1362_i2c_driver_turn_on_off(bool on)
{
	uint8_t command = on ? 0xaf : 0xae;
	return ssd1362_i2c_driver_write_command(&command, 1);
}

static bool ssd1362_i2c_driver_write_command(uint8_t *data, size_t data_size)
{
	size_t b = 0;
	uint8_t buffer[64];
	for (uint i = 0; i < data_size; i++)
	{
		buffer[b++] = (i == data_size - 1) ? 0 : OLED_CONTROL_BYTE_CONTINUATION_BIT;
		buffer[b++] = data[i];
	}
	return i2c_task_write_command(buffer, b);
}

void ssd1362_i2c_driver_clear(void)
{
	memset(oled_buffer, 0, sizeof(oled_buffer));
}

void ssd1362_i2c_driver_fill_color(uint8_t color)
{
	uint8_t color_out = (color << 4) | color;
	memset(oled_buffer, color_out, sizeof(oled_buffer));
}

bool ssd1362_i2c_driver_set_display_area(uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2)
{
		/// Set column Address, Start column Address, End column Address
	uint8_t cmd_x[] = { 0x15, (uint8_t)(x1 * OLED_COLOR_BITS / 8), (uint8_t)(x2 * OLED_COLOR_BITS / 8)};
	if (!ssd1362_i2c_driver_write_command(cmd_x, sizeof(cmd_x)))
		return false;
	
		/// Set Row Address, Start Row Address, End Row Address
	uint8_t cmd_y[] = { 0x75, (uint8_t)y1, (uint8_t)y2 };
	return ssd1362_i2c_driver_write_command(cmd_y, sizeof(cmd_y));
}

bool ssd1362_i2c_driver_update_all_screen(void)
{
	return ssd1362_i2c_driver_update_screen(0, OLED_WIDTH - 1, 0, OLED_HEIGHT - 1);
}

void ssd1362_i2c_driver_normalize_xy(uint16_t *x1, uint16_t *x2, uint16_t *y1, uint16_t *y2)
{
	*x1 = (*x1 / 2) * 2;
	*y1 = (*y1 / 2) * 2;
	*x2 = (*x2 / 2) * 2 + 1;
	*y2 = (*y2 / 2) * 2 + 1;
	*x2 = min(*x2, OLED_WIDTH);
	*y2 = min(*y2, OLED_HEIGHT);
}

bool ssd1362_i2c_driver_update_screen(uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2)
{
	ssd1362_i2c_driver_normalize_xy(&x1, &x2, &y1, &y2);

	if (!ssd1362_i2c_driver_set_display_area(x1, x2, y1, y2))
		return false;

	uint in, out;
	uint8_t buffer[1 + OLED_WIDTH];
	size_t size = (x2 - x1 + 1) * OLED_COLOR_BITS / 8;
	for (int y = y1; y <= y2; y++)
	{
		in = y * OLED_WIDTH * OLED_COLOR_BITS / 8 + x1 * OLED_COLOR_BITS / 8;
		out = 0;
		buffer[out++] = OLED_CONTROL_BYTE_DATA_BIT;
		memcpy(&buffer[out], &oled_buffer[in], size);
		out += size;

		if (!i2c_task_write_command(buffer, out))
			return false;
	}

	return true;
}

void ssd1362_i2c_driver_put_pixel(uint16_t x, uint16_t y, uint8_t color)
{
	color = color & 0x0f;
	uint16_t i = y * OLED_WIDTH  * OLED_COLOR_BITS / 8 + x * OLED_COLOR_BITS / 8;
	if (i >= sizeof(oled_buffer))
		return;

	if ((x % 2) == 0)
		oled_buffer[i] = (oled_buffer[i] & 0x0f) | (color << 4);
	else
		oled_buffer[i] = (oled_buffer[i] & 0xf0) | color;
}

void ssd1362_i2c_driver_draw_line(uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2, uint8_t color)
{
	if (x1 == x2 && y1 == y2)									/// one pixel
	{
		ssd1362_i2c_driver_put_pixel(x1, y1, color);
	}
	else if (abs(x2 - x1) >= abs(y2 - y1))		/// horizontal line
	{
		int y;
		if (x2 < x1)
		{
			uint16_t tmp;
			xchange(x1, x2, tmp);
			xchange(y1, y2, tmp);
		}
		float dxy = (x1 == x2) ? 0 : (y2 - y1) / (float)(x2 - x1);
		for (int x = x1; x <= x2; x++)
		{
			y = y1 + (x - x1) * dxy;
			ssd1362_i2c_driver_put_pixel(x, y, color);
		}
	}
	else																			/// vertical line
	{
		int x;
		if (y2 < y1)
		{
			uint16_t tmp;
			xchange(x1, x2, tmp);
			xchange(y1, y2, tmp);
		}
		float dyx = (y1 == y2) ? 0 : (x2 - x1) / (float)(y2 - y1);
		for (int y = y1; y <= y2; y++)
		{
			x = x1 + (y - y1) * dyx;
			ssd1362_i2c_driver_put_pixel(x, y, color);
		}
	}
}

void ssd1362_i2c_driver_draw_rectangle(uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2, uint8_t color)
{
	ssd1362_i2c_driver_draw_line(x1, x2, y1, y1, color);
	ssd1362_i2c_driver_draw_line(x1, x2, y2, y2, color);
	ssd1362_i2c_driver_draw_line(x1, x1, y1, y2, color);
	ssd1362_i2c_driver_draw_line(x2, x2, y1, y2, color);
}

void ssd1362_i2c_driver_draw_image(uint8_t *image, size_t image_width, size_t image_height,
		uint16_t img_x1, uint16_t img_x2, uint16_t img_y1, uint16_t img_y2, uint16_t to_x, uint16_t to_y)
{
	uint in, out;
	size_t size = (img_x2 - img_x1 + 1) * OLED_COLOR_BITS / 8;
	size_t image_size = image_width * image_height * OLED_COLOR_BITS / 8;

	for (int y = img_y1; y <= img_y2; y++)
	{
		in = y * image_width * OLED_COLOR_BITS / 8 + img_x1 * OLED_COLOR_BITS / 8;
		if (in + size > image_size)
			return;

		out = (to_y + y - img_y1) * OLED_WIDTH * OLED_COLOR_BITS / 8 + to_x * OLED_COLOR_BITS / 8;
		if (out + size > sizeof(oled_buffer))
			return;

		memcpy(&oled_buffer[out], &image[in], size);
	}
}

void ssd1362_i2c_driver_draw_image_opacity(uint8_t *image, size_t image_width, size_t image_height,
		uint16_t img_x1, uint16_t img_x2, uint16_t img_y1, uint16_t img_y2, uint16_t to_x, uint16_t to_y, float opacity)
{
	uint8_t opacity_ = opacity * 16;
	uint8_t c1, c2;
	uint in, out;
	size_t size = (img_x2 - img_x1 + 1) * OLED_COLOR_BITS / 8;
	size_t image_size = image_width * image_height * OLED_COLOR_BITS / 8;

	for (int y = img_y1; y <= img_y2; y++)
	{
		in = y * image_width * OLED_COLOR_BITS / 8 + img_x1 * OLED_COLOR_BITS / 8;
		if (in + size > image_size)
			return;

		out = (to_y + y - img_y1) * OLED_WIDTH * OLED_COLOR_BITS / 8 + to_x * OLED_COLOR_BITS / 8;
		if (out + size > sizeof(oled_buffer))
			return;

		for (int x = 0; x < size; x++)
		{
			c1 = image[in] >> 4;
			c2 = image[in++] & 0x0f;
			c1 = c1 * opacity_ / 16;
			c2 = c2 * opacity_ / 16;
			oled_buffer[out++] = (c1 << 4) | c2;
		}
	}
}

void ssd1362_i2c_driver_draw_greyscale(uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2)
{
	uint out;
	for (int y = y1; y <= y2; y++)
	{
		out = y * OLED_WIDTH * OLED_COLOR_BITS / 8 + x1 * OLED_COLOR_BITS / 8;
		for (int x = x1 * OLED_COLOR_BITS / 8; x <= x2 * OLED_COLOR_BITS / 8; x++)
			oled_buffer[out++] = (((x * 2) % 16) << 4) | (((x * 2) + 1) % 16);
	}
}

static uint16_t ssd1362_i2c_driver_get_char_bytes(Font *font)
{
	return font->FontWidthBytesAtEndOfLine ? font->Height + 1 : font->Height;
}

static uint16_t ssd1362_i2c_driver_get_char_width(Font *font, char c)
{
	uint16_t char_bytes = ssd1362_i2c_driver_get_char_bytes(font);
	return font->FontWidthBytesAtEndOfLine ? font->FontTable[(c + 1 - 32) * char_bytes - 1] : font->RealWidth;
}

void ssd1362_i2c_driver_draw_char(Font *font, uint16_t x, uint16_t y, uint8_t color, uint8_t background_color, char c)
{
	uint16_t char_bytes = ssd1362_i2c_driver_get_char_bytes(font);
	uint16_t char_width = ssd1362_i2c_driver_get_char_width(font, c);
	uint16_t y0 = (c - 32) * char_bytes;

	for (int y_ = 0; y_ < font->Height; y_++)
	{
		for (int x_ = 0; x_ < char_width; x_++)
		{
			uint8_t pixel;
			if (font->Mirror)
				pixel = GET_BIT(font->FontTable[y0 + y_], x_);
			else
				pixel = GET_BIT(font->FontTable[y0 + y_], font->Width - 1 - x_);
			uint8_t pixel_color = (pixel) ? color : background_color;
			ssd1362_i2c_driver_put_pixel(x + x_, y + y_, pixel_color);
		}
	}
}

void ssd1362_i2c_driver_draw_string(Font *font, uint16_t x, uint16_t y, uint8_t color, uint8_t background_color, const char *text)
{
	uint16_t char_width;
	uint16_t x_ = x;
	uint16_t y_ = y;
	last_string_x1 = x;
	last_string_y1 = y;

	for (int i = 0; i < strlen(text); i++)
	{
		char_width = ssd1362_i2c_driver_get_char_width(font, text[i]);
		if (x_ + char_width >= OLED_WIDTH - 1)
		{
			x_ = 0;
			y_ += font->Height + 1;
		}

		ssd1362_i2c_driver_draw_char(font, x_, y_, color, background_color, text[i]);
		x_ += char_width + font->XSpacing;
	}

	last_string_x2 = x_;
	last_string_y2 = y_ + font->Height;
}

void ssd1362_i2c_driver_update_screen_for_last_string(void)
{
	ssd1362_i2c_driver_update_screen(last_string_x1, last_string_x2, last_string_y1, last_string_y2);
}

/*
		todo: $$
	g_master_buff
	czcionka średnia
	generator obrazków PHP - github
	wysyłanie I2C blokujące - DMA lub task z niskim priorytetem
	działanie razem z Linuxem - nie bootować Linuxa, bo używa I2C4 - pozostawać w U-boot (PCO devboard i.MX8MP)

		Shop:
	REX025664AWAP3N00000 256x64x4bit
	https://www.mouser.pl/ProductDetail/Microtips-Technology/REX025664AWAP3N00000?qs=DuoOggApuK%2FEyZbZ3T80hg%3D%3D

		Datasheets:
	https://www.mouser.pl/datasheet/2/271/REX025664AWAP3N00000_V_E_20191218-1888866.pdf
	https://www.crystalfontz.com/controllers/SolomonSystech/SSD1362

		Driver examples:
	https://github.com/adafruit/Adafruit-GFX-Library/blob/master/Adafruit_GrayOLED.cpp
	https://github.com/adafruit/Adafruit_SSD1306/blob/master/Adafruit_SSD1306.cpp
	https://robojax.com/learn/arduino/?vid=robojax-SSD1306-OLED
	https://github.com/Matiasus/SSD1306/blob/master/lib/ssd1306.c#L351
	https://github.com/olikraus/u8g2/tree/master/csrc
*/
