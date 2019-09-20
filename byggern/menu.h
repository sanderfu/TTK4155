/*
 * menu.h
 *
 * Created: 20.09.2019 11:05:19
 *  Author: torsteoe
 */ 
#include <stdlib.h>
#include <avr/io.h>
#include <string.h>
struct MenuNode
{
	char name[10];
	struct MenuNode* parent;
	struct MenuNode* children[3];
};

typedef struct MenuNode MenuNode;

MenuNode* mainMenuInit(void);
void addChild(MenuNode* parent, char* child_name);
MenuNode* menuInit(void);
