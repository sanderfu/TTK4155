/*
 * menu.c
 *
 * Created: 20.09.2019 10:31:16
 *  Author: torsteoe
 */ 
#include "menu.h"


#define MAXCHILDREN 3


MenuNode* mainMenuInit (void){
	MenuNode* ptr = (MenuNode*) malloc(sizeof(MenuNode));
	strcpy(ptr->name, "Main menu");
	ptr->parent = NULL;
	for (int i = 0; i< 3; i++) {
		ptr->children[i] = NULL;
	}

	return ptr;
}

void addChild(MenuNode* parent, char* child_name)
{
	MenuNode* childPtr = (MenuNode*) malloc(sizeof(MenuNode));
	strcpy(childPtr->name, child_name);
	childPtr->parent = parent;
	for (int i=0; i<MAXCHILDREN; i++)
	{
		if (parent->children[i]==NULL)
		{
			parent->children[i]=childPtr;
			return;
		}
	}
	return;
}

MenuNode* menuInit(void)
{
	MenuNode* mainMenu = mainMenuInit();
	addChild(mainMenu,"Play game");
	return mainMenu;
}
