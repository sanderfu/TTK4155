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
#define TIMELIMIT 99
#define INITSCORE 10


void game_init()
{
	gameActive=0;
	for (int i = 0; i<5; i++) {
			highScores[i] = 0;
	}
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
void game_initialCANMessage() {
	CAN_message_t initMessage;
	initMessage.ID = 0x02;
	initMessage.data_length = 0;
	CAN_transmit_message(&initMessage);
}

void game_newgame()
{
	cli();
	game_countdown();
	gameActive=1;
	gameData.score=INITSCORE;
	gameData.playtime=0;
	gameData.timeLimit=TIMELIMIT;
	game_initialCANMessage();
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
	printf(time_string);
	oled_print(time_string);
}
void game_finished() {
	cli();
	oled_reset();
	oled_home();
	oled_gotoLine(3);
	oled_print("time up");
	oled_gotoLine(4);
	oled_print("Maybe HS?");
	_delay_ms(3000);
	gameActive=0;
	
	menu_init();
	
	for (int i = 0; i<5; i++) {
		if (gameData.score > highScores[i]) {
			for (int a = 4; a>i; a--) {
				highScores[a] = highScores[a-1];
			}
			highScores[i] = gameData.score;
			break;
		}
	}
	sei();
}
void game_play(uint8_t gameID)
{
	if(gameActive==0)
	{
		game_newgame();	
	}
	if (buttons.right_button) {
		gameActive = 0;
		menu_init();
	}
	game_sendUserInput();
	game_recieveGameData();
	
	if (gameData.playtime==10) {
		game_finished();
	}
	
}

void game_displayHighscores() {
	oled_reset();
	oled_home();
	oled_print(currentMenu.currentMenuItem->name);
	
	for (int i=0;i<5;i++)
	{
		oled_gotoLine(3+i);
		oled_print("Score ");
		char num[2];
		itoa(i+1,num,10);
		oled_print(num);
		oled_print(": ");
		itoa(highScores[i],num,10);
		oled_print(num);
	}
}
