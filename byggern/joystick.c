#include "joystick.h"
#include "adc.h"
#include <stdlib.h>
#define X_POS_CHANNEL 0
#define Y_POS_CHANNEL 1

uint8_t joystickOffsetX;
uint8_t joystickOffsetY;


void joystickInit() {
	joystickOffsetX = readAdc(X_POS_CHANNEL);
	joystickOffsetY = readAdc(Y_POS_CHANNEL);
}
void joystick_readPosition(position_t * pos) {
	uint8_t x_pos = readAdc(X_POS_CHANNEL);
	uint8_t y_pos = readAdc(Y_POS_CHANNEL);
	if (x_pos < joystickOffsetX) {
		pos->x_pos = ((x_pos - joystickOffsetX)*100)/(joystickOffsetX);
	} else {
		pos->x_pos = ((x_pos - joystickOffsetX)*100)/(255-joystickOffsetX);
	}
	if (y_pos < joystickOffsetY) {
		pos->y_pos = ((y_pos - joystickOffsetY)*100)/(joystickOffsetY);
	} else {
		pos->y_pos = ((y_pos - joystickOffsetY)*100)/(255-joystickOffsetY);
	}
	}

DIRECTION_t joystick_getDirection(position_t * pos) {
	if (abs(pos->x_pos) < 5 && abs(pos->y_pos) <5) {
		return NEUTRAL;
	}
	if (pos->x_pos >= 5 && abs(pos->y_pos) < 50) {
		return RIGHT;
	}
	if (pos->x_pos <= -5 && abs(pos->y_pos) < 50) {
		return LEFT;
	}
	
	if (pos->y_pos <= -5) {
		return DOWN;
	}
	else {
		return UP;
	}
	
} 
void joystick_printDirection(DIRECTION_t dir) {
	printf("Direction:\t");
	switch(dir) {
		case NEUTRAL:
			printf("Neutral\n\r");
			return;
		case LEFT:
			printf("Left\n\r");
			return;
		case RIGHT:
			printf("Right\n\r");
			return;
		case UP:
			printf("Up\n\r");
			return;
		case DOWN:
			printf("Down\n\r");
			return;
		
	}
}