#include "oled.h"
#define OLED_COMMAND_BASE_ADDRESS 0x1000
#define OLED_DATA_BASE_ADDRESS 0x1200
void oled_write_c(uint8_t data) {
	volatile char *ext_mem = (char *) OLED_COMMAND_BASE_ADDRESS;
	*ext_mem = data;
}
void oled_write_d(uint8_t data) {
	volatile char *ext_mem = (char *) OLED_DATA_BASE_ADDRESS;
	*ext_mem = data;
}

void oled_pos(uint8_t page, uint8_t col) {
	oled_write_c(0xB0 + page);
	
	
	oled_write_c(col & 0x0F);
	oled_write_c((col >> 4) & 0x1F);
	
	
}
void oled_init(void) {
	oled_write_c(0xae); // display off
	oled_write_c(0xa1); //segment remap
	oled_write_c(0xda); //common pads hardware: alternative
	oled_write_c(0x12);
	oled_write_c(0xc8); //common output scan direction:com63~com0
	oled_write_c(0xa8); //multiplex ration mode:63
	oled_write_c(0x3f);
	oled_write_c(0xd5); //display divide ratio/osc. freq. mode
	oled_write_c(0x80);
	oled_write_c(0x81); //contrast control
	oled_write_c(0x50);
	oled_write_c(0xd9); //set pre-charge period
	oled_write_c(0x21);
	oled_write_c(0x20); //Set Memory Addressing Mode, paging mode
	oled_write_c(0x02);
	oled_write_c(0xdb); //VCOM deselect level mode
	oled_write_c(0x30);
	oled_write_c(0xad); //master configuration
	oled_write_c(0x00);
	oled_write_c(0xa4); //out follows RAM content
	oled_write_c(0xa6); //set normal display
	oled_write_c(0xaf); // display on
}

void oled_print_arrow(uint8_t row, uint8_t col)
{
	oled_pos(row, col);
	oled_write_d(0b00011000);
	oled_write_d(0b00011000);
	oled_write_d(0b01111110);
	oled_write_d(0b00111100);
	oled_write_d(0b00011000);
}