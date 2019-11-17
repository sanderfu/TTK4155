/**
 * @file
 * @brief The music interface
 */

#ifndef MUSIC_H_
#define MUSIC_H_

/**
 * @brief Play Rick Rolled
 * 
 */
void music_playRick();

/**
 * @brief Play Game Over Tune
 * 
 */
void music_gameOver();

/**
 * @brief Play specified note
 * 
 */
void music_playNote(uint16_t note);
#endif
