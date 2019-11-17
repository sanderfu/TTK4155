/*
 * byggern.c
 *
 * Created: 30.08.2019 15:12:42
 *  Author: torsteoe
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
	printf("------------------------6---------------\n\n\n\n\n\n\r");

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
