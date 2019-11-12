#ifndef OLED_H_
#define OLED_H_

#include <avr/io.h>
#define	ASCII_SPACE 32

void oled_init(void);
void oled_print_arrow();
void oled_reset();


void oled_home();
void oled_gotoLine(uint8_t page);
void oled_gotoColumn(uint8_t column);
void oled_clearLine(uint8_t page);

void oled_print(char*);

#endif