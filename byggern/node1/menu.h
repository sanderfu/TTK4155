/*
 * menu.h
 *
 * Created: 20.09.2019 11:05:19
 *  Author: torsteoe
 */ 

#ifndef MENU_H_
#define MENU_H_
#include <avr/io.h>
#include "joystick.h"
#define MAXCHILDREN 6
#define MAX_OLED_STRING 16
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

menu currentMenu;

//uses joystick position to change current menu.
void navigateMenu(joystick_position_t * joystick_position_p);

//Print menu on OLED.
void menu_printCurrentMenu();

//Initialize menu
void menu_init();

#endif /* !MENU_HEADER */