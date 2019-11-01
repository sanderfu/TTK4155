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
uint8_t timerFlag = 0;

ISR (TIMER3_COMPB_vect) {
	
	
	timerFlag = 1;
	
	
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
	printf("\n\r---------------------------------------\n\n\n\n\n\n\r");


	//test_SRAM();
	volatile CAN_message_t message;
	message.ID = 0b10101010111;
	message.data_length = 3;
	message.data[0] = 13;
	message.data[1] = 22;
	message.data[2] = 33;
	
	_delay_ms(2000);
	pwm_setPulseWidth(2);
    //CAN_controller_setMode(MODE_NORMAL);
    
	while (1) {
		

		//Put microcontroller to sleep until next interrupt. 

		sleep_now();
		if (CANFlag) {
			
			cli();
			printf("Message received");
			CANFlag=0;
			CAN_receiveMessage();
			//joystick_readPositionOverCAN();
			joystick_printPosition();
			joystick_setServo();
			uint8_t mask = 0b11; 
			
			CAN_controller_bitModify(mask, CANINTF, 0b00);
			sei();
			
		}
		if (timerFlag) {
			TCNT3 = 0x00;
			//printf("Analog value: %d\n\r", ADC_read());
		}
	

		
		
	}
}
