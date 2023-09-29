#define OLED_WIDTH       256
#define OLED_HEIGHT      64
#define OLED_COLOR_BITS  4

#define OLED_TAF_DELAY_MS                   200   /// tAF - from display on to send data
#define OLED_CONTROL_BYTE_DATA_BIT          0x40  /// control byte - data bit
#define OLED_CONTROL_BYTE_CONTINUATION_BIT  0x80  /// control byte - continuation bit

extern bool ssd1362_i2c_driver_initialize(bool rotate_display_180);
extern bool ssd1362_i2c_driver_turn_on_off(bool on);
extern void ssd1362_i2c_driver_clear(void);
extern void ssd1362_i2c_driver_fill_color(uint8_t color);
extern bool ssd1362_i2c_driver_update_all_screen(void);
extern bool ssd1362_i2c_driver_update_screen(uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2);
extern void ssd1362_i2c_driver_draw_line(uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2, uint8_t color);
extern void ssd1362_i2c_driver_draw_rectangle(uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2, uint8_t color);
extern void ssd1362_i2c_driver_draw_image(uint8_t *image, size_t image_width, size_t image_height,
		uint16_t img_x1, uint16_t img_x2, uint16_t img_y1, uint16_t img_y2, uint16_t to_x, uint16_t to_y);
extern void ssd1362_i2c_driver_draw_greyscale(uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2);
