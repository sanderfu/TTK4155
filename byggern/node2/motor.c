/*
 * motor.c
 *
 * Created: 01.11.2019 13:25:32
 *  Author: sanderfu
 */ 
#include "motor.h"
#include <avr/io.h>
#include "TWI_Master.h"
#include <stdio.h>
#include "slider.h"
#include "timer.h"
#include "encoder.h"

float summed_error;
float prev_error; 

void motor_init() {
	//configure PH1 (DIR) and PH4 (EN) as output
	DDRH |= (1 << PH1);
	DDRH |= (1 << PH4);
	
	motor_setSpeed(0);
	motor_enable();
	summed_error = 0;
	prev_error = 0;
}

void motor_enable() {
	PORTH |= (1 << PH4);
}
void motor_disable() {
	PORTH &= ~(1 << PH4);
}

void motor_setDirection(uint8_t dir) {
	
	//right
	if (dir) {
		PORTH |= (1 << PH1);
		
	}
	else {
		PORTH &= ~(1 << PH1);
	}
}

void motor_setSpeed(uint8_t speed) {
	uint8_t data[3];
	uint8_t address = 0x50;
	uint8_t command_byte = 0x00;
	data[0] = address;  //this address contains a low byte at end signifying a transmission.
	data[1] = command_byte;
	data[2] = speed;
	TWI_Start_Transceiver_With_Data(data, 3);
}

void motor_control() {
	
	
	int32_t reference_position = slider_pos.right_pos;
	float K_p = 0.5;
	float K_i = 0.2;
	float K_d = 0.06;//0.01;// 0.001;
	int error = reference_position - converted_encoderValue;
	summed_error += error*TIMER3_SECONDS;
	float derivative_error = (error-prev_error)/TIMER3_SECONDS;
	prev_error = error;
	int u =  K_p*error + K_i*summed_error + K_d*derivative_error;
	//printf("Summed error %d\n\r", summed_error);
	//printf("sumE %d\n\r",  summed_error);
	//printf("U %d\n\r",  u);
	//attempting to get u varying between -100 and 100;
	
	if (u>0)
	{
		motor_setDirection(1);
		u = (u*255)/100;
		
	} else {
		motor_setDirection(0);
		u = -(u*255)/100;
		
	}
	int offset = 25;
	u = u+offset;

	if (u>255) {
		u = 255;
		summed_error -= error; // anti-windup (Regtek for life)
	}
	
	//printf("Reference position: %i\n\r", reference_position);
	//printf("u: %i\n\r", u);
	motor_setSpeed((uint8_t) u);
	
	

}

