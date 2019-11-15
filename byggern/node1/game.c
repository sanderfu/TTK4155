/*
 * game.c
 *
 * Created: 12.11.2019 16:35:20
 *  Author: sanderfu
 */ 

#include "game.h"
#include "menu.h"
#include "CAN.h"
#include "touchButton.h"
#define F_CPU 4915200
#include <avr/delay.h>
#include <avr/interrupt.h>
#define TIMELIMIT 120
#define INITSCORE 10
void game_init()
{
	gameActive=0;
}

void game_countdown() {
	char num[1];
	itoa(3,num,10);
	oled_reset();
	oled_home();
	oled_print(currentMenu.currentMenuItem->name);
	oled_gotoLine(3);
	oled_print(num);
	_delay_ms(1000);
	itoa(2,num,10);
	oled_reset();
	oled_home();
	oled_print(currentMenu.currentMenuItem->name);
	oled_gotoLine(3);
	oled_print(num);
	_delay_ms(1000);

	itoa(1,num,10);
	oled_reset();
	oled_home();
	oled_print(currentMenu.currentMenuItem->name);
	oled_gotoLine(3);
	oled_print(num);
	_delay_ms(1000);
	oled_reset();
	oled_home();
	oled_print(currentMenu.currentMenuItem->name);
	oled_gotoLine(3);
	oled_print("Go");
	_delay_ms(1000);
}

void game_newgame()
{
	cli();
	game_countdown();
	gameActive=1;
	gameData.score=INITSCORE;
	gameData.playtime=0;
	gameData.timeLimit=TIMELIMIT;
	sei();
}

void game_sendUserInput()
{
	//Send control data over can
	CAN_sendInputData();
}

void game_recieveGameData()
{
	//Recieve score and time data over CAN
	if (flag) {
		//Handle the message
		cli();
		printf("Message received");
		flag=0;
		CAN_receiveMessage(&received_message);
		//Clear interrupt
		CAN_clearInterrupt();
		//Update gamedata
		gameData.score = received_message.data[0];
		gameData.playtime = received_message.data[1];
		sei();
	}
	
}

void game_updateOled()
{
	//Print the game name
	printf("Game oled");
	oled_reset();
	oled_home();
	oled_print(currentMenu.currentMenuItem->name);
	oled_gotoLine(3);
	oled_print("Score: ");
	char score_string[2];
	itoa(gameData.score,score_string,10);
	oled_print(score_string);
	oled_gotoLine(5);
	oled_print("Time: ");
	char time_string[2];
	itoa(gameData.playtime,time_string,10);

	oled_print(time_string);
}

void game_play(uint8_t gameID)
{
	if(gameActive==0)
	{
		game_newgame();	
	}
	if (buttons.right_button) {
		gameActive = 0;
		this_init();
	}
	game_sendUserInput();
	
	
}
