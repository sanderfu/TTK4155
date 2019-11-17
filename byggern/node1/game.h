/*
 * game.h
 *
 * Created: 12.11.2019 16:35:33
 *  Author: sanderfu
 */ 


#ifndef GAME_H_
#define GAME_H_

#include <avr/interrupt.h>
#include <stdlib.h>
#include <avr/io.h>
#include <string.h>

typedef struct{
	uint8_t score;
	uint8_t timeLimit;
	uint8_t playtime;
} gameData_t;

//Create global game data
gameData_t gameData; 
uint8_t gameActive;
uint8_t highScores[5];
uint8_t highScores2[5];
void game_init();
void game_play(uint8_t gameID);
void game_displayHighscores(uint8_t gameID);

#endif /* GAME_H_ */