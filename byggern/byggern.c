/*
 * byggern.c
 *
 * Created: 30.08.2019 15:12:42
 *  Author: torsteoe
 */ 
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>

#define F_CPU 4915200
#include <avr/interrupt.h>
#include "menu.h"
#include <util/delay.h>
#include "setup.h"

#include <stdlib.h>
#include "uart.h"
#include "xmem.h"
#include "adc.h"
#include "joystick.h"
#include "slider.h"
#include "touchButton.h"
#include "oled.h"
#include "avr/interrupt.h"
#include "menu.h"
#include "timer.h"
#include "test.h"
#include "SPI.h"
#include "CAN_controller.h"
#include "MCP2515.h"
#include "pwm.h"
#include "music.h"
#include "CAN.h"
CAN_message_t received_message;
volatile uint8_t flag = 0;
ISR (INT0_vect) {
	//cli();
	flag= 1;
	
	
	
	//sei();
	
}


int main(void)
//p.23 for can read instructions
{
	setupInit();
	
	//test_SRAM();
	CAN_message_t message;
	message.ID = 3;
	message.data_length = 1;
	message.data[0] = (uint8_t) 8;
	CAN_transmit_message(&message);
	

	

	printf("Starting program\n\n\n\n\n\n\n\n\n\n\r");
	printf("---------------------------------------\n\r");
	//test_SRAM();
	//pwm_testPlayNote();
	//pwm_init();
	//music_playLisaGikk();                 
	while (1) {
		//Put microcontroller to sleep until next interrupt. 

		sleep_now();
		if (!strcmp(currentMenu.currentMenuItem->children[currentMenu.childIndex]->name, "Rick")) {
		}
		if (flag) {
			//printf("Message received");
			CAN_receiveMessage(&received_message);
			//printf("This is the data: %i", received_message.data);
			uint8_t mask = 0b11; 
			CAN_controller_bitModify(mask, CANINTF, 0b00);
			flag=0;
		}
		//test_resetMenu();
		//test_outputControllers(joystick_pos, slider_pos, buttons);		
		/*
		CAN_transmit_message(&message);
		_delay_ms(500);	
		_delay_ms(500);	
		*/

		
	}
}
