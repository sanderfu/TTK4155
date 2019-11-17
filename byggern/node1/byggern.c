

/**
 * @mainpage Node 1 Documentation - TTK4155 - Group 46
 * @section intro_sec Introduction
 * This page contains the documentation for node 1 of the term project in TTK4155
 * 
 * @section summary Implementation summary
 *
 * @subsection drivers Drivers
 * The interfacing functions have been implemented according to the official data sheet of the ATmega162 
 * and the relevant additional IC's used, but details regarding the use of these data sheets are not documented in this node documentation.
 * We therefore recommend having the relevant data sheets of the IC's open when studying this documentation to get a complete
 * understanding of the choices that has been taken along the way regarding operation modes, timer settings etc. It is not considered essential
 * if the main purpose is to get a general overview of the node functionality.
 *
 * @subsection game Game Logic
 * The node introduces two game modes. In Game 1, the player starts with 10 points and have to keep as many points as possible within a given time frame. 
 * One point is lost every time the ball passes the "goal line". In Game 2, points are given for every second the player keeps the ball away from the goal.
 *
 * @section pcb PCB
 * During the project term, a PCB has been designed to remove the need for breadboard usage for the node itself. 
 * The PCB Schematic was designed based on the breadboard layout, designed in KiCAD and produced by JLCPCB in Shenzhen, China. 
 * A separate repository for the PCB designed this term can be found at <a href="https://github.com/sanderfu/ttk4155-pcb">https://github.com/sanderfu/ttk4155-pcb</a> 
 * @subsection schematic Schematic
 * \htmlonly <style>div.image img[src="schematic.png"]{width:1000px;}</style> \endhtmlonly
 * @image html schematic.png
 * @subsection pcb_render PCB Render
 * \htmlonly <style>div.image img[src="pcb_render.png"]{width:1000px;}</style> \endhtmlonly
 * @image html pcb_render.png
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
		_delay_ms(5);
		
		if (timerFlag)
		{
			cli();
			TCNT1 = 0x00;
			joystick_readPosition();
			slider_readPosition(&slider_pos);
			touchButton_readButtons();
			
			timerFlag=0;
			TCNT1 = 0x00;

			sei();
		}
		switch(currentMenu.currentMenuItem->nodeID){
			case MAIN_MENU:
				break;
			case PLAY_GAME:
				break;
			case HIGH_SCORE:
				highScoresActive = 0;
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
		if (gameActive == 0) {
					navigateMenu(&joystick_pos);

		}
		if(gameActive==0 & highScoresActive == 0) {
			
			menu_printCurrentMenu();
			TCNT1 = 0x00;
		}
		//Put microcontroller to sleep until next interrupt.

		sleep_now();
		
	}
}
