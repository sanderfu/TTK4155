/*
 * slider.h
 *
 * Created: 01.11.2019 10:48:23
 *  Author: sanderfu
 */ 


#ifndef SLIDER_H_
#define SLIDER_H_
#include <avr/io.h>
#include "CAN.h"
typedef struct {
	uint8_t left_pos;
	uint8_t right_pos;
} slider_position_t;
volatile slider_position_t slider_pos;

void slider_readPositionOverCAN(CAN_message_t mess);





#endif /* SLIDER_H_ */