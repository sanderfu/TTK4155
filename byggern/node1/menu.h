/*
 * menu.h
 *
 * Created: 20.09.2019 11:05:19
 *  Author: torsteoe
 */ 

#ifndef MENU_H_
#define MENU_H_
#include <stdlib.h>
#include <avr/io.h>
#include <string.h>

#include "joystick.h"
#define MAXCHILDREN 6
#define MAX_OLED_STRING 16
struct MenuNode 
{
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

MenuNode* mainMenuInit(void);
MenuNode* addChild(MenuNode* parent, char* child_name);
MenuNode* menuInit(void);
void navigateMenu(joystick_position_t * joystick_position_p);
void menu_printCurrentMenu();


#endif /* !MENU_HEADER */