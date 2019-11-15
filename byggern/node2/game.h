/*
 * game.h
 *
 * Created: 15.11.2019 09:20:37
 *  Author: torsteoe
 */ 


#ifndef GAME_H_
#define GAME_H_

#define  INITSCORE 10
#define TIMELIMIT 99
#include "timer.h"

#define F_CPU 16000000

#include <stdlib.h>
#include <avr/io.h>
#include <string.h>
#include <stdio.h>

typedef struct{
	uint8_t score;
	uint8_t timeLimit;
	uint8_t playtime;
} gameData_t;

//Create global game data
gameData_t gameData;
uint8_t gameActive;
volatile int numOf5ms;
void game_init();
void game_play();
void game_stop();
void game_sendGameData();

#endif /* GAME_H_ */