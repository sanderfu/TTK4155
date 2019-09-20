/*
 * menu.c
 *
 * Created: 20.09.2019 10:31:16
 *  Author: torsteoe
 */ 
#include "menu.h"




MenuNode* mainMenuInit (void){
	MenuNode* ptr = (MenuNode*) malloc(sizeof(MenuNode));
	ptr->numChildren = 0;
	strcpy(ptr->name, "Main menu");
	ptr->parent = NULL;
	/*
	for (int i = 0; i< MAXCHILDREN; i++) {
		ptr->children[i] = NULL;
	}
	*/
	return ptr;
}

MenuNode * addChild(MenuNode* parent, char* child_name)
{
	MenuNode* childPtr = (MenuNode*) malloc(sizeof(MenuNode));
	
	parent->numChildren++;
	strcpy(childPtr->name, child_name);
	childPtr->parent = parent;
	
	if (parent->numChildren > MAXCHILDREN) {
		return NULL;
	} 
	parent->children[parent->numChildren-1]=childPtr;
	parent->children[parent->numChildren-1]->numChildren = 0;
	return childPtr;
}

MenuNode* menuInit(void)
{
	MenuNode* mainMenu = mainMenuInit();
		
	MenuNode * childPlayGame = addChild(mainMenu,"Play game");
	addChild(childPlayGame,"GAME 1");
	addChild(childPlayGame,"GAME 2");
	
	
	MenuNode * childHighscore = addChild(mainMenu,"Highscore");
	//childHighscore->numChildren = 5;
	
	for (int i = 0; i< 5; i++) {
		addChild(childHighscore, "High: 1");
	}
	
	MenuNode* childSettings = addChild(mainMenu,"Settings");
	//childSettings->numChildren = 1;
	addChild(childSettings, "No sett");
	currentMenu.currentMenuItem = mainMenu;
	currentMenu.childIndex = 0;
	currentMenu.lastDir = NEUTRAL;
	

	return mainMenu;
}

void navigateMenu(joystick_position_t * joystick_position_p) {
	DIRECTION_t dir = joystick_getDirection(joystick_position_p);
	if (currentMenu.lastDir == NEUTRAL) {
			switch (dir) {
			case DOWN:
				if (currentMenu.childIndex < currentMenu.currentMenuItem->numChildren -1 ) {
					currentMenu.childIndex++;
				} else {
					currentMenu.childIndex = 0;
				}
				break;
			case UP:
				if (currentMenu.childIndex > 0 ) {
					currentMenu.childIndex--;
				} else {
					currentMenu.childIndex = currentMenu.currentMenuItem->numChildren-1;
				}
				break;
			case LEFT:
				if (currentMenu.currentMenuItem->parent != NULL) {
					currentMenu.currentMenuItem = currentMenu.currentMenuItem->parent;
					currentMenu.childIndex = 0;
				}
				
				break;
			case RIGHT:
				if (currentMenu.currentMenuItem->children[currentMenu.childIndex]->numChildren != 0) {
					currentMenu.currentMenuItem = currentMenu.currentMenuItem->children[currentMenu.childIndex];
					currentMenu.childIndex = 0;
				}
				break;
			default:
				break;
		
		}
	}
	
	currentMenu.lastDir = dir;
	
}

void menu_printCurrentMenu() {
	oled_reset();
	oled_home();
	oled_print(currentMenu.currentMenuItem->name);
	
	for (int i = 0; i<currentMenu.currentMenuItem->numChildren; i++) {
		oled_gotoLine(i+2);
		oled_print(((currentMenu.currentMenuItem->children)[i])->name);
		if (currentMenu.childIndex == i) {
			oled_print_arrow();
		}
	}
	
}