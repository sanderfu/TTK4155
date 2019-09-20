/*
 * menu.h
 *
 * Created: 20.09.2019 11:05:19
 *  Author: torsteoe
 */ 

#ifndef MENU_HEADER
#define  MENU_HEADER
#include <stdlib.h>
#include <avr/io.h>
#include <string.h>

#include "joystick.h"
#define MAXCHILDREN 6
struct MenuNode 
{
	char name[10];
	struct MenuNode* parent;
	struct MenuNode* children[MAXCHILDREN];
	uint8_t numChildren;
};

typedef struct MenuNode MenuNode;

MenuNode* mainMenuInit(void);
MenuNode* addChild(MenuNode* parent, char* child_name);
MenuNode* menuInit(void);
void navigateMenu(joystick_position_t * joystick_position_p);
void menu_printCurrentMenu();


#endif /* !MENU_HEADER */