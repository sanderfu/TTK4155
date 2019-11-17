#ifndef TOUCHBUTTON_H_
#define TOUCHBUTTON_H_

#include <avr/io.h>

typedef struct {
	uint8_t left_button;
	uint8_t right_button;
} buttonValues_t;
buttonValues_t buttons;
void touchButton_init();
void touchButton_readButtons();
void touchButton_sendButtonsOverCAN();
#endif
