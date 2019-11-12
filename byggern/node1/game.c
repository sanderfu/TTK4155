/*
 * game.c
 *
 * Created: 12.11.2019 16:35:20
 *  Author: sanderfu
 */ 

#include "game.h"
#include "menu.h"
#include "CAN.h"

#define TIMELIMIT 120
#define INITSCORE 10
void game_init()
{
	gameActive=0;
}

void game_newgame()
{
	gameActive=1;
	gameData.score=INITSCORE;
	gameData.playtime=0;
	gameData.timeLimit=TIMELIMIT;
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
	char score_string[2];
	itoa(gameData.score,score_string,10);
	oled_print();
}

void game_play(uint8_t gameID)
{
	if(gameActive==0)
	{
		game_newgame();	
	}
	game_sendUserInput();
	
	
}