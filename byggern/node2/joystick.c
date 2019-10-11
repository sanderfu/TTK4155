/*
 * joystick.c
 *
 * Created: 11.10.2019 15:39:00
 *  Author: torsteoe
 */ 
#include "joystick.h"
#include "CAN.h"

void joystick_readPositionOverCAN() {
	CAN_message_t mess;
	CAN_receiveMessage(&mess);
	
	if (mess.ID = 0x01) {
		joystick_pos.x_pos = mess.data[0];
		joystick_pos.y_pos = mess.data[1];
		joystick_pos.angle = atan2(joystick_pos.y_pos, joystick_pos.x_pos)*360/2.0/3.14;
	}
}

void joystick_printPosition() {
	printf("X: %i\tY: %i\n\rAngle: %i\n\r", joystick_pos.x_pos, joystick_pos.y_pos, joystick_pos.angle);
};