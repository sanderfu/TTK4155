#ifndef OLED_H_
#define OLED_H_

#include <avr/io.h>

//Initialize OLED
void oled_init(void);

//Print a left-facing arrow on the screen
void oled_print_arrow();

//Clear the screen
void oled_reset();

//Go to position (0,0)
void oled_home();

//Go to a specific page
void oled_gotoLine(uint8_t page);

//Go to a specific column
void oled_gotoColumn(uint8_t column);

//Clear a specific line
void oled_clearLine(uint8_t page);

//Print char array to oled screen.
void oled_print(char*);

#endif