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

joystick_position_t joystick_pos;

//Initialize joystick
void joystick_init();

//Read joystick position
void joystick_readPosition();

//Get direction (up, left, right, down, neutral), given position in x,y
DIRECTION_t joystick_getDirection(joystick_position_t * pos);

//Send the joystick direction to terminal over USART
void joystick_printDirection(DIRECTION_t dir);

//Send the joystick position over CAN
void joystick_sendPositionOverCAN();

#endif