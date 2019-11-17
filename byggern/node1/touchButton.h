#ifndef TOUCHBUTTON_H_
#define TOUCHBUTTON_H_

#include <avr/io.h>

typedef struct {
	uint8_t left_button;
	uint8_t right_button;
} buttonValues_t;
buttonValues_t buttons;

//Initialize touchButton values
void touchButton_init();

//Read the P1000 touchbuttons
void touchButton_readButtons();

//Send the touchbutton values stored over CAN to node 2
void touchButton_sendButtonsOverCAN();
#endif
