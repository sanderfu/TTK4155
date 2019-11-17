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
#include <util/delay.h>
#include "setup.h"

#include "menu.h"
#include "timer.h"
#include "CAN_controller.h"
#include "MCP2515.h"
#include "CAN.h"
#include "game.h"
#include "music.h"
#include "sleep.h"
#include "slider.h"
#include "joystick.h"
#include "touchButton.h"

ISR (INT0_vect) {
	flag= 1;
}

int main(void)
{

	setupInit();
	
	//Send initialize message to Node 2
	CAN_message_t message;
	message.ID = 0x10;
	message.data_length = 0;
	CAN_transmit_message(&message);
	
	printf("Starting program\n\r");
	printf("---------------------------------------\n\r");
	_delay_ms(500);    
	while (1) {
		if (timerFlag)
		{
			cli();
			TCNT1 = 0x00;
			joystick_readPosition();
			slider_readPosition(&slider_pos);
			touchButton_readButtons();
			if(gameActive==0){
				navigateMenu(&joystick_pos);
				menu_printCurrentMenu();
			}
			timerFlag=0;
			sei();
		}
		switch(currentMenu.currentMenuItem->nodeID){
			case MAIN_MENU:
				break;
			case PLAY_GAME:
				break;
			case HIGH_SCORE:
				break;
			case MUSIC:
				music_playRick();
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
		//Put microcontroller to sleep until next interrupt.
		sleep_now();
	}
}
