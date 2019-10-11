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
volatile CAN_message_t received_message;
volatile uint8_t flag = 0;
ISR (INT4_vect) {
	//cli();
	flag= 1;
	
	
	
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
	
	
	//CAN_controller_setMode(MODE_NORMAL);
	

	//test_SRAM();
	//pwm_testPlayNote();
	//pwm_init();
	//music_playLisaGikk();                 
	while (1) {
		//
		_delay_ms(500);
		//Put microcontroller to sleep until next interrupt. 

		
		if (flag) {
			printf("Message received");
			flag=0;
			CAN_receiveMessage(&received_message);
			//printf("This is the data: %i", received_message.data);
			uint8_t mask = 0b11; 
			CAN_controller_bitModify(mask, CANINTF, 0b00);
			
		}
		_delay_ms(500);	
	
		CAN_transmit_message(&message);
		printf("\n\r-------------------------------------------\n\r");

		/*
		//test_outputControllers(joystick_pos, slider_pos, buttons);
				
		_delay_ms(500);	
	
		CAN_transmit_message(&message);
		_delay_ms(500);	
		
		//CAN_controller_setMode(MODE_LOOPBACK);
		*/
	}
}
