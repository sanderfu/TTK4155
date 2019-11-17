/**
 * @file
 * @brief A library for keeping the joystick-values and steering the Servo accordingly on Node 2. 
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

/**
 * @brief Set servo motor voltage according to joystick position.
 */
void joystick_setServo();

#endif /* JOYSTICK_H_ */