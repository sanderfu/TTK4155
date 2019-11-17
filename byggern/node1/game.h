/**
 * @file
 * @brief Game Interface
 */

#ifndef GAME_H_
#define GAME_H_

///////////////////////////////////////////////
// Includes
///////////////////////////////////////////////

#include <avr/interrupt.h>
#include <stdlib.h>
#include <avr/io.h>
#include <string.h>

///////////////////////////////////////////////
// Structures
///////////////////////////////////////////////

typedef struct{
	uint8_t score;
	uint8_t timeLimit;
	uint8_t playtime;
} gameData_t;

///////////////////////////////////////////////
// Global variables
///////////////////////////////////////////////
gameData_t gameData; 
uint8_t gameActive;
uint8_t highScoresActive;

uint8_t highScores[5];
uint8_t highScores2[5];

///////////////////////////////////////////////
// Function Declarations
///////////////////////////////////////////////

/**
 * @brief Initialize Game Interface
 * 
 */
void game_init();

/**
 * @brief Play game, starts connection between Node 1 and 2
 * 
 * @param[in] gameID The ID of the requested game mode.
 */
void game_play(uint8_t gameID);

/**
 * @brief Show highscores for a given game mode
 * 
 * @param[in] gameID The ID of the requested game mode.
 */
void game_displayHighscores(uint8_t gameID);

#endif /* GAME_H_ */