/*
 * joystick.h
 *
 * Created: 11.10.2019 15:39:13
 *  Author: torsteoe
 */ 


#ifndef JOYSTICK_H_
#define JOYSTICK_H_
#include <avr/io.h>
#include "CAN.h"
typedef struct {
	int8_t x_pos;
	int8_t y_pos;
	int16_t angle;
} joystick_position_t;

typedef enum DIRECTION {
	LEFT,
	RIGHT,
	UP,
	DOWN,
	NEUTRAL
} DIRECTION_t ;

volatile joystick_position_t joystick_pos;
void joystick_printPosition();
void joystick_setServo();

#endif /* JOYSTICK_H_ */