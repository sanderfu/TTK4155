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

ISR (INT0_vect) {
	flag= 1;
}

int main(void)
//p.23 for can read instructions
{

	setupInit();
	
	//test_SRAM();
	volatile CAN_message_t message;
	message.ID = 0b10101010111;
	message.data_length = 3;
	message.data[0] = 13;
	message.data[1] = 22;
	message.data[2] = 33;
	
	printf("Starting program\n\r");
	printf("---------------------------------------\n\r");
	_delay_ms(500);
	
	CAN_controller_setMode(MODE_NORMAL);

	//test_SRAM();            
	while (1) {
		
		//Put microcontroller to sleep until next interrupt. 
		sleep_now();
		
		switch(currentMenu.currentMenuItem->nodeID){
			case MAIN_MENU:
				break;
			case HIGH_SCORE:
				break;
			case MUSIC:
				break;
			case GAME_1:
				game_play(1);
				break;
			case GAME_2:
				game_play(2);
				break;
			case HS1:
				game_displayHighscores(1);
				break;
			case HS2:
				game_displayHighscores(2);
				break;
			
		}
	}
}
