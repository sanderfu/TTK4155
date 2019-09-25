#ifndef TOUCHBUTTON_H_
#define TOUCHBUTTON_H_

#define BUTTON_LEFT (PINB & (1 << PB1))
#define BUTTON_RIGHT (PINB & (1 << PB2))

#include <avr/io.h>

typedef struct {
	uint8_t left_button;
	uint8_t right_button;
} buttonValues_t;

void touchButton_init();
void touchButton_readButtons(buttonValues_t * buttons);

#endif
