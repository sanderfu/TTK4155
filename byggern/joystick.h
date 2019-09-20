#ifndef JOYSTICK_H_
#define  JOYSTICK_H_
#include <avr/io.h>

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
	
void joystick_readPosition(joystick_position_t * pos);
DIRECTION_t joystick_getDirection(joystick_position_t * pos);
void joystick_printDirection(DIRECTION_t dir);

#endif