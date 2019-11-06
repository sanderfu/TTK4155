/*
 * touchButton.h
 *
 * Created: 06.11.2019 12:59:06
 *  Author: torsteoe
 */ 


#ifndef TOUCHBUTTON_H_
#define TOUCHBUTTON_H_
#include <avr/io.h>
#include "CAN.h"

typedef struct {
	uint8_t left_button;
	uint8_t right_button;
} buttonValues_t;
buttonValues_t buttons;

void touchButton_readButtonsOverCAN(CAN_message_t mess);


#endif /* TOUCHBUTTON_H_ */