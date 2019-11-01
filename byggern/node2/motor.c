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
#include "joystick.h"
void motor_init() {
	//configure PH1 (DIR) and PH4 (EN) as output
	DDRH |= (1 << PH1);
	DDRH |= (1 << PH4);
	
	motor_setSpeed(0);
	motor_enable();

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
	
	uint32_t speed;
	if (joystick_pos.x_pos>0)
	{
		motor_setDirection(1);
		speed = (joystick_pos.x_pos*255)/100;
	} else {
		motor_setDirection(0);

		speed = -(joystick_pos.x_pos*255)/100;
	}
	printf("Speed: %i\n\r",  speed);
	if (speed < 256 && speed >= 0) {
		motor_setSpeed((uint8_t) speed/2);
	}
}

