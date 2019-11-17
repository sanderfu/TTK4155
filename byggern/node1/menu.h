/**
 * @file
 * @brief Menu interface
 */

#ifndef MENU_H_
#define MENU_H_

///////////////////////////////////////////////
// Includes
///////////////////////////////////////////////

#include <avr/io.h>
#include "joystick.h"

///////////////////////////////////////////////
// Defines
///////////////////////////////////////////////
#define MAXCHILDREN 6
#define MAX_OLED_STRING 16

///////////////////////////////////////////////
// Enumerations
///////////////////////////////////////////////
typedef enum MENU_ID {
	MAIN_MENU,
	PLAY_GAME,
	HIGH_SCORE,
	MUSIC,
	GAME_1,
	GAME_2,
	HS1,
	HS2
} MENU_ID_t ;

///////////////////////////////////////////////
// Structures
///////////////////////////////////////////////
struct MenuNode 
{
	MENU_ID_t nodeID;
	uint8_t isAction;
	char name[MAX_OLED_STRING];
	struct MenuNode* parent;
	struct MenuNode* children[MAXCHILDREN];
	uint8_t numChildren;
};

typedef struct MenuNode MenuNode;

typedef struct{
	MenuNode * currentMenuItem;
	uint8_t childIndex;
	DIRECTION_t lastDir;
} menu;

///////////////////////////////////////////////
// Global variables
///////////////////////////////////////////////
menu currentMenu;

///////////////////////////////////////////////
// Function declarations
///////////////////////////////////////////////

/**
 * @brief Initialize the menu interface 
 * 
 */
void menu_init();

/**
 * @brief Navigate the menu
 * 
 * @param[in] joystick_position_p The Current Joystick position
 */
void navigateMenu(joystick_position_t * joystick_position_p);


/**
 * @brief Print menu on OLED display
 * 
 */
void menu_printCurrentMenu();


#endif /* !MENU_HEADER */