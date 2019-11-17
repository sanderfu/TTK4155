/**
 * @mainpage Node 2 Documentation - TTK4155 - Group 46
 * @section intro_sec Introduction
 * This page contains the documentation for node 2 of the term project in TTK4155. The main purpose of this node is to control
 * the motor based on user input in node 1 and send information back regarding playtime and score. The communication between nodes is done using the CAN protocol.
 * 
 * @section summary Implementation summary
 *
 * @subsection drivers Drivers
 * The interfacing functions have been implemented according to the official data sheet of the ATmega2560 
 * and the relevant additional IC's used, but details regarding the use of these data sheets are not documented in this node documentation.
 * We therefore recommend having the relevant data sheets of the IC's open when studying this documentation to get a complete
 * understanding of the choices that has been taken along the way regarding operation modes, timer settings etc. It is not considered essential
 * if the main purpose is to get a general overview of the node functionality.
 *
 * @subsection game Game Logic
 * The node introduces two game modes. In Game 1, the player starts with 10 points and have to keep as many points as possible within a given time frame. 
 * One point is lost every time the ball passes the "goal line". In Game 2, points are given for every second the player keeps the ball away from the goal.
 *
*/
#include <avr/io.h>
#include <stdio.h>

#define F_CPU 16000000
#include <avr/interrupt.h>
#include <util/delay.h>
#include "setup.h"

#include <stdlib.h>
#include "uart.h"
#include "timer.h"

#include "SPI.h"
#include "CAN_controller.h"
#include "MCP2515.h"
#include "CAN.h"
#include "joystick.h"
#include "pwm.h"
#include "ADC.h"
#include "sleep.h"
#include "TWI_Master.h"
#include "motor.h"
#include "encoder.h"
#include "slider.h"
#include "touchbutton.h"
#include "solenoid.h"
#include "game.h"
uint8_t timerFlag = 0;
uint8_t regulatorOn = 0;
ISR (TIMER3_COMPB_vect) {
	
	timerFlag = 1;
	numOf5ms++;
	
}

volatile CAN_message_t received_message;
volatile uint8_t CANFlag = 0;
ISR (INT4_vect) {
	CANFlag= 1;
	
	
}



int main(void)
{
	
	setupInit();
	printf("---------------------------------------\n\n\n\n\n\n\r");

	while (1) {
		_delay_ms(5);
		//Put microcontroller to sleep until next interrupt.
		sleep_now();
			
		if (CANFlag) {
			
			cli();
			CANFlag=0;
			CAN_receiveMessage();
			
			if (gameActive) {
				if (buttons.left_button && !(shooting)) {
					solenoid_setPulse();
				}
				if (slider_pos.left_pos>0) {
					regulatorOn = 1;
					} 
				else {
					motor_setSpeed(0);
					regulatorOn = 0;
				}
				
				joystick_setServo();
			}
			
			
			CAN_clearInterrupt();
			sei();
			
		}
		
		if (timerFlag) {
			cli();
			timerFlag = 0;
			
			TCNT3 = 0x00;
			encoder_readValues();
			
			if (gameActive) {
				game_play();
				if (regulatorOn) {
					motor_control();
				}
			}
			sei();
			
		}
	
	
	}
}
