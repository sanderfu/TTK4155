/*
 * joystick.c
 *
 * Created: 11.10.2019 15:39:00
 *  Author: torsteoe
 */ 
#include "joystick.h"
#include "CAN.h"
#include "pwm.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
}

void joystick_setServo() {
		float var = ((float)joystick_pos.x_pos+100.0)/200.0*(2.1-0.9)+0.9;
		printf("servo value: %.6f\n\r",(var));
		pwm_setPulseWidth((joystick_pos.x_pos+100.0)/200.0*(2.1-0.9)+0.9);
	
}