/*
 * game.c
 *
 * Created: 15.11.2019 09:20:26
 *  Author: torsteoe
 */ 
#include "game.h"
#include "CAN.h"
#include "IR.h"
#include "solenoid.h"
#include "touchbutton.h"
void game_init() {
	
	gameActive = 1;
	
	//Initialize gameData
	numOf5ms = 0;
	gameData.playtime = numOf5ms*TIMER3_SECONDS;
	gameData.score = INITSCORE;
	gameData.timeLimit = TIMELIMIT;
	
}


void game_sendGameData() {
	CAN_message_t score;
	score.ID = 0x01;
	score.data_length = 2;
	score.data[0] = gameData.score;
	score.data[1] = gameData.playtime;
	CAN_transmit_message(&score);
}

void game_play() {
	
	IR_detectGoal();
	gameData.playtime = numOf5ms*TIMER3_SECONDS;
	float timeFloat = gameData.playtime;
	if (!(numOf5ms*TIMER3_SECONDS > timeFloat)) {
		cli();
		game_sendGameData();
		sei();
	}

}

void game_stop() {
		gameData.playtime = numOf5ms*TIMER3_SECONDS;
		gameData.score = INITSCORE;
		gameActive = 0;
}

