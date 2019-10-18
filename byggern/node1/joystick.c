#include "joystick.h"
#include "adc.h"
#include "CAN.h"

#include <stdlib.h>
#include <math.h>
#define X_POS_CHANNEL 0
#define Y_POS_CHANNEL 1

uint8_t joystickOffsetX;
uint8_t joystickOffsetY;


void joystickInit() {
	joystickOffsetX = readAdc(X_POS_CHANNEL);
	joystickOffsetY = readAdc(Y_POS_CHANNEL);
}
void joystick_readPosition() {
	uint8_t x_pos = readAdc(X_POS_CHANNEL);
	uint8_t y_pos = readAdc(Y_POS_CHANNEL);
	if (x_pos < joystickOffsetX) {
		joystick_pos.x_pos = ((x_pos - joystickOffsetX)*100)/(joystickOffsetX);
	} else {
		joystick_pos.x_pos = ((x_pos - joystickOffsetX)*100)/(255-joystickOffsetX);
	}
	if (y_pos < joystickOffsetY) {
		joystick_pos.y_pos = ((y_pos - joystickOffsetY)*100)/(joystickOffsetY);
	} else {
		joystick_pos.y_pos = ((y_pos - joystickOffsetY)*100)/(255-joystickOffsetY);
	}
	joystick_pos.angle = atan2(joystick_pos.y_pos, joystick_pos.x_pos)*360/2.0/3.14;
}

DIRECTION_t joystick_getDirection(joystick_position_t * pos) {
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

void joystick_sendPositionOverCAN() {
		printf("sending");

	CAN_message_t message;
	
	message.ID = 0x01;
	message.data_length = 2;
	
	message.data[0] = joystick_pos.x_pos;
	message.data[1] = joystick_pos.y_pos;

	
	CAN_transmit_message(&message);
}