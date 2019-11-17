/**
 * @file
 * @brief A library for playing the 2 games on Node 2.
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

/**
 * @brief Initiate game module and sets game as active. This function will be triggered by a specific CAN message from Node 1. 
 */
void game_init();

/**
 * @brief Update score and time and call sendGameData() every second. 
 */
void game_play();

/**
 * @brief Disable game, sets game as inactive.
 */
void game_stop();

/**
 * @brief Send score and time over CAN. 
 */
void game_sendGameData();

#endif /* GAME_H_ */