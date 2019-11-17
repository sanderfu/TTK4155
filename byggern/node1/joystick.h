/**
 * @file
 * @brief Joystick interface
 */

#ifndef JOYSTICK_H_
#define  JOYSTICK_H_

///////////////////////////////////////////////
// Includes
///////////////////////////////////////////////
#include <avr/io.h>

///////////////////////////////////////////////
// Structures
///////////////////////////////////////////////
typedef struct {
	int8_t x_pos;
	int8_t y_pos;
	int16_t angle;
} joystick_position_t;

///////////////////////////////////////////////
// Enumerations
///////////////////////////////////////////////

typedef enum DIRECTION {
	LEFT, 
	RIGHT, 
	UP, 
	DOWN, 
	NEUTRAL
} DIRECTION_t ;


///////////////////////////////////////////////
// Global variables
///////////////////////////////////////////////
joystick_position_t joystick_pos;

///////////////////////////////////////////////
// Function declarations
///////////////////////////////////////////////

/**
 * @brief Initialize Joystick Interface
 * 
 */
void joystick_init();

/**
 * @brief Read position of the Joystick
 * 
 */
void joystick_readPosition();

/**
 * @brief get direction (up, left, right, down, neutral), given position in x,y
 * 
 * @param[out] dir The joystick direction as an enum
 * @param[in] *pos The joystick position as x,y value pair
 */
DIRECTION_t joystick_getDirection(joystick_position_t * pos);

/**
 * @brief Print the Joystick position 
 * 
 * @param[in] dir Joystick position in enum type
 */
void joystick_printDirection(DIRECTION_t dir);

/**
 * @brief Send the current joystick position over CAN.
 * 
 */
void joystick_sendPositionOverCAN();

#endif