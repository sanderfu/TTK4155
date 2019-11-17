/*
 * game.c
 *
 * Created: 12.11.2019 16:35:20
 *  Author: sanderfu
 */ 

#include "game.h"
#define F_CPU 4915200
#include <util/delay.h>
#include "menu.h"
#include "CAN.h"
#include "touchButton.h"
#include "music.h"
#include "notes.h"
#include "oled.h"
#include <stdio.h>
#define TIMELIMIT 30
#define INITSCORE 10


void game_init()
{
	gameActive=0;
	highScoresActive = 0;
	for (int i = 0; i<5; i++) {
			highScores[i] = 0;
			highScores2[i] = 0;
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
	music_playNote(NOTE_C4);
	_delay_ms(500);
	music_playNote(0);
	_delay_ms(500);
	
	itoa(2,num,10);
	oled_reset();
	oled_home();
	oled_print(currentMenu.currentMenuItem->name);
	oled_gotoLine(3);
	oled_print(num);
	music_playNote(NOTE_C4);
	_delay_ms(500);
	music_playNote(0);
	_delay_ms(500);
	itoa(1,num,10);
	oled_reset();
	oled_home();
	oled_print(currentMenu.currentMenuItem->name);
	oled_gotoLine(3);
	oled_print(num);
	music_playNote(NOTE_C4);
	_delay_ms(500);
	music_playNote(0);
	_delay_ms(500);
	oled_reset();
	oled_home();
	oled_print(currentMenu.currentMenuItem->name);
	oled_gotoLine(3);
	oled_print("Go");
	music_playNote(NOTE_C6);
	_delay_ms(500);
	music_playNote(0);
	_delay_ms(500);
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
		//printf("Message received");
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

void game_updateOled(uint8_t gameID)
{
	//Print the game name
	oled_reset();
	oled_home();
	oled_print(currentMenu.currentMenuItem->name);
	char score_string[2];
	char time_string[2];
	
	oled_gotoLine(3);
	switch(gameID) {
		case 1:
			oled_print("Score: ");
			itoa(gameData.score,score_string,10);
			oled_print(score_string);
			oled_gotoLine(5);
			oled_print("Time: ");
			itoa(gameData.playtime,time_string,10);
			oled_print(time_string);
			break;
		case 2:
			oled_print("Air time: ");
			itoa(gameData.playtime,time_string,10);
			oled_print(time_string);
			break;

	}
	
}

void game_sendStop() {
	CAN_message_t mess;
	mess.ID = 0x3;
	mess.data_length=0;
	CAN_transmit_message(&mess);
}
void game_finished(uint8_t gameID) {
	cli();
	game_sendStop();
	oled_reset();
	oled_home();
	oled_gotoLine(3);
	oled_print("Game over");
	oled_gotoLine(4);
	oled_print("Maybe HS?");
	music_gameOver();
	
	gameActive=0;
	sei();
	menu_init();
	//menu_printCurrentMenu();
	switch (gameID) {
		case 1:
			for (int i = 0; i<5; i++) {
				if (gameData.score > highScores[i]) {
					for (int a = 4; a>i; a--) {
						highScores[a] = highScores[a-1];
					}
					highScores[i] = gameData.score;
					break;
				}
			}
			break;
		case 2:
			for (int i = 0; i<5; i++) {
				if (gameData.playtime > highScores2[i]) {
					for (int a = 4; a>i; a--) {
						highScores2[a] = highScores2[a-1];
					}
					highScores2[i] = gameData.playtime;
					break;
				}
			}
			break;
		
	}
	
	
	
}
void game_play(uint8_t gameID)
{
	if(gameActive==0)
	{
		game_sendStop();
		_delay_ms(100);
		game_newgame();	
	}
	if (buttons.right_button) {
		gameActive = 0;
		menu_init();
	}
	game_sendUserInput();
	game_recieveGameData();
	game_updateOled(gameID);
	switch (gameID) {
		case 1:
			if (gameData.playtime==TIMELIMIT) {
				game_finished(gameID);
			}
			break;
		case 2:
			if (gameData.score < INITSCORE) {
				game_finished(gameID);
			}
			break;
	}
	
	
}

void game_displayHighscores(uint8_t gameID) {
	highScoresActive= 1;
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
		switch (gameID) {
			case 1:
				itoa(highScores[i],num,10);
				break;
			case 2:
				itoa(highScores2[i],num,10);
				break;
		}
		oled_print(num);
	}
}
