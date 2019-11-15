/*
 * byggern.c
 *
 * Created: 30.08.2019 15:12:42
 *  Author: torsteoe
 */ 
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>

#define F_CPU 16000000
#include <avr/interrupt.h>
#include <util/delay.h>
#include "setup.h"

#include <stdlib.h>
#include "uart.h"
#include "avr/interrupt.h"
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
	//cli();
	CANFlag= 1;
	
	
	
	//sei();
	
}



int main(void)
//p.23 for can read instructions
{
	
	setupInit();
	printf("------------------------6---------------\n\n\n\n\n\n\r");
/*
	DDRE  |= (1 << PE5);
	PORTE &= ~(1 << PE5);
	
	_delay_ms(2000);
	PORTE |= (1 << PE5);
		_delay_ms(2000);
*/
	//pwm_setPulseWidth(2);
	while (1) {
		_delay_ms(5);
		//Put microcontroller to sleep until next interrupt. 

		sleep_now();
		if (CANFlag) {
			
			cli();
			//printf("Message received");
			CANFlag=0;
			CAN_receiveMessage();
			
			if (gameActive) {
				//printf("slider left%i", slider_pos.left_pos);
				if (slider_pos.left_pos>0) {
					//printf("reg on2");
					regulatorOn = 1;
					} else {
					motor_setSpeed(0);
					regulatorOn = 0;
				}
				
				joystick_setServo();
			}
			
			uint8_t mask = 0b11; 

			CAN_controller_bitModify(mask, CANINTF, 0b00);
			sei();
			
		}
		
		if (timerFlag) {
			cli();
			//printf("joystick x:%i\n\rslider left: %i\n\r, button left: %i\n\r", joystick_pos.x_pos, slider_pos.left_pos, buttons.left_button);
			
			//printf("in timer");
			//printf("shooting VALUE: %i\n\r", shooting);
			if (buttons.left_button && !(shooting)) {
				//printf("shooting");
				solenoid_setPulse();
			}
			TCNT3 = 0x00;
			encoder_readValues();
			//printf("Converted: %i\n\r", converted_encoderValue);
			if (regulatorOn) {
				motor_control();
			}
			//printf("ADC-value: %i", ADC_read());
			if (gameActive) {
				game_play();
			}
			
			sei();
		}
	
		
		
	}
}
