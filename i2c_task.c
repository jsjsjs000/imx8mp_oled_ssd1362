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

	/* Board config */
#include "board_cfg/board.h"
#include "board_cfg/clock_config.h"
#include "board_cfg/pin_mux.h"

#include "common.h"
#include "i2c_task.h"
#include "ssd1362_i2c_driver.h"
#include "image_pco.h"
#include "image_ostatnia_wieczerza.h"
#include "font.h"
#include "fonts7x8.h"
#include "fonts_ubuntu_11pts.h"
#include "fonts_tahoma_10pts.h"
#include "fonts_tahoma_10pts_bold.h"

static uint8_t i2c_buffor[I2C_BUFFOR_SIZE];
static i2c_master_handle_t *i2c_master_handle;

static i2c_rtos_handle_t master_rtos_handle;
static i2c_master_config_t masterConfig;
static i2c_master_transfer_t masterXfer;
static uint32_t sourceClock;

void i2c_task_initialize(void)
{
	CLOCK_SetRootMux(I2C_OLED_CLK_ROOT, I2C_OLED_ROOT_MUX_SYS_PLL_DIV); /* Set I2C source to SysPLL1 Div5 160MHZ */
	CLOCK_SetRootDivider(I2C_OLED_CLK_ROOT, 1U, 10U);                   /* Set root clock to 160MHZ / 10 = 16MHZ */
	NVIC_SetPriority(I2C_OLED_IRQN, 3);

	/*
		masterConfig.baudRate_Bps = 100000U;
		masterConfig.enableStopHold = false;
		masterConfig.glitchFilterWidth = 0U;
		masterConfig.enableMaster = true;
	*/
	I2C_MasterGetDefaultConfig(&masterConfig);
	masterConfig.baudRate_Bps = I2C_BAUDRATE;
	sourceClock = I2C_OLED_CLK_FREQ;

	status_t status = I2C_RTOS_Init(&master_rtos_handle, I2C_OLED, &masterConfig, sourceClock);
	if (status != kStatus_Success)
	{
		PRINTF("I2C master: error during init, 0x%x\r\n", status);
	}

	i2c_master_handle = &master_rtos_handle.drv_handle;

	memset(&masterXfer, 0, sizeof(masterXfer));
	masterXfer.slaveAddress   = I2C_OLED_SLAVE_ADDR_7BIT;
	masterXfer.direction      = kI2C_Write;
	masterXfer.data           = i2c_buffor;
	masterXfer.dataSize       = 0;
	masterXfer.flags          = kI2C_TransferDefaultFlag;
}

void i2c_task_task(void *pvParameters)
{
	PRINTF("I2C task started.\r\n");

	ssd1362_i2c_driver_initialize(true);

	ssd1362_i2c_driver_clear();
	ssd1362_i2c_driver_update_all_screen();
	ssd1362_i2c_driver_turn_on_off(true);

		/// draw PCO logo
	// uint16_t imgx = ROUND_TO_2(OLED_WIDTH / 2 - Image_pco_width / 2);
	// uint16_t imgy = OLED_HEIGHT / 2 - Image_pco_height / 2;
	// for (float opacity = 0.0; opacity <= 1.0 + 0.0001; opacity += 0.125)
	// {
	// 	ssd1362_i2c_driver_draw_image_opacity((uint8_t*)Image_pco, Image_pco_width, Image_pco_height,
	// 			0, Image_pco_width - 1, 0, Image_pco_height - 1, imgx, imgy, opacity);
	// 	ssd1362_i2c_driver_update_screen(imgx, imgx + Image_pco_width - 1, imgy, imgy + Image_pco_height - 1);
	// 	vTaskDelay(pdMS_TO_TICKS(50));
	// }
	// vTaskDelay(pdMS_TO_TICKS(1500));
	// ssd1362_i2c_driver_clear();
	// ssd1362_i2c_driver_update_all_screen();

		/// draw some text
	ssd1362_i2c_driver_draw_string(&Font7x8, 0, 0, 0x0f, 0, "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz ąćęłńóśżź");
	ssd1362_i2c_driver_draw_string(&Font_Tahoma10pts, 0, 18, 0x0f, 0,
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz ąćęłńóśżźĄĆĘŁŃÓŚŻŹ 0123456789");
	// ssd1362_i2c_driver_draw_string(&Font_Tahoma10pts_bold, 0, 18, 0x0f, 0,
	// 		"ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz ąćęłńóśżźĄĆĘŁŃÓŚŻŹ 0123456789");
	// ssd1362_i2c_driver_draw_string(&Font_Ubuntu11pts, 0, 18, 0x0f, 0,
	// 		"ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz ąćęłńóśżźĄĆĘŁŃÓŚŻŹ 0123456789");
	ssd1362_i2c_driver_update_all_screen();

		/// draw and fast update text
	// int i = 25;
	// float u = 12;
	// int t = 25;
	// char s[64];
	// while (true)
	// {
	// 	sprintf(s, "I=%dmA", i++);
	// 	ssd1362_i2c_driver_draw_string(&Font7x8, 24, 34, 0x0f, 0, s);
	// 	ssd1362_i2c_driver_update_screen_for_last_string();

	// 	sprintf(s, "U=%.1fV", u);
	// 	u += 0.1;
	// 	ssd1362_i2c_driver_draw_string(&Font7x8, 96, 34, 0x0f, 0, s);
	// 	ssd1362_i2c_driver_update_screen_for_last_string();

	// 	sprintf(s, "T=%dC", t++);
	// 	ssd1362_i2c_driver_draw_string(&Font7x8, 164, 34, 0x0f, 0, s);
	// 	ssd1362_i2c_driver_update_screen_for_last_string();

	// 	vTaskDelay(pdMS_TO_TICKS(500));
	// }


	// ssd1362_i2c_driver_fill_color(0x07);

	// ssd1362_i2c_driver_draw_greyscale(0, 128 - 1, 0, 32 - 1);
	// ssd1362_i2c_driver_draw_greyscale(128, 128 + 64 - 1, 32, 32 + 16 - 1);

	// ssd1362_i2c_driver_draw_image((uint8_t*)Image_ostatnia_wieczerza, Image_ostatnia_wieczerza_width, Image_ostatnia_wieczerza_height, 0, Image_ostatnia_wieczerza_width - 1, 0, Image_ostatnia_wieczerza_height - 1, 0, 0);
	// ssd1362_i2c_driver_draw_image((uint8_t*)Image_ostatnia_wieczerza, Image_ostatnia_wieczerza_width, Image_ostatnia_wieczerza_height, 128, 128 + 128 - 1, 32, 32 + 32 - 1, 64, 16);
	// ssd1362_i2c_driver_draw_image_opacity((uint8_t*)Image_ostatnia_wieczerza, Image_ostatnia_wieczerza_width, Image_ostatnia_wieczerza_height, 0, Image_ostatnia_wieczerza_width - 1, 0, Image_ostatnia_wieczerza_height - 1, 0, 0, 0.8);

	// ssd1362_i2c_driver_draw_line(OLED_WIDTH - 1, 0, 0, OLED_HEIGHT - 1, 0x0f);
	// ssd1362_i2c_driver_draw_line(0, OLED_WIDTH - 1, 0, OLED_HEIGHT - 1, 0x0f);
	// ssd1362_i2c_driver_draw_line(32 - 1, 0, 0, OLED_HEIGHT - 1, 0x0f);
	// ssd1362_i2c_driver_draw_line(0, 32 - 1, 0, OLED_HEIGHT - 1, 0x0f);
	// ssd1362_i2c_driver_draw_rectangle(0, OLED_WIDTH - 1, 0, OLED_HEIGHT - 1, 0x0f);

	// ssd1362_i2c_driver_clear();
	// ssd1362_i2c_driver_update_all_screen();
	// ssd1362_i2c_driver_update_screen(0, OLED_WIDTH - 1, 0, OLED_HEIGHT - 1);

	PRINTF("I2C task: Finish draw on OLED.\r\n");

	while (true) ;

	vTaskSuspend(NULL);
}

bool i2c_task_write_data(uint8_t *data, size_t data_size)
{
	memcpy(i2c_buffor, data, data_size);
	
	masterXfer.direction = kI2C_Write;
	masterXfer.dataSize = data_size;

// PRINTF("I2C master: before write %d %x %x\r\n", j, i2c_buffor[0], i2c_buffor[1]);

	status_t status = I2C_RTOS_Transfer(&master_rtos_handle, &masterXfer);
	if (status != kStatus_Success)
	{
		PRINTF("I2C master: error during write transaction, 0x%x\r\n", status);
		return false;
	}

	return true;
}
