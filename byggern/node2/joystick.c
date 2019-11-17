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
#include "TWI_Master.h"
void joystick_readPositionOverCAN(CAN_message_t mess) {
	
	if (mess.ID == 1) {
		joystick_pos.x_pos = mess.data[0];
		joystick_pos.y_pos = mess.data[1];
		joystick_pos.angle = atan2(joystick_pos.y_pos, joystick_pos.x_pos)*360/2.0/3.14;
	}
}

void joystick_printPosition() {
	printf("X: %i\tY: %i\n\rAngle: %i\n\r", joystick_pos.x_pos, joystick_pos.y_pos, joystick_pos.angle);
}

void joystick_setServo() {
		float var = 3-(((float)joystick_pos.x_pos+100.0)/200.0*(2.1-0.9)+0.9);
		//printf("servo value: %i\n\r",(int)(var*100));
		pwm_setPulseWidth(var);
	
}
/*
void joystick_setMotor() {
	
	//open loop controller
	uint8_t msg[]
	TWI_Start_Transceiver_With_Data()
}
*/