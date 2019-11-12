/*
 * menu.c
 *
 * Created: 20.09.2019 10:31:16
 *  Author: torsteoe
 */ 
#include "menu.h"
#include <avr/interrupt.h>



MenuNode nodes[11];

void this_init() {
	
	//printf("this_init initiating");
	//Setting the name of the main menu
	strcpy(nodes[0].name, "Main menu");
	//Setting the names of the subm
	strcpy(nodes[1].name, "Play game");
	strcpy(nodes[2].name, "High scores");
	strcpy(nodes[3].name, "Music");
	//Setting the names of the actions
	strcpy(nodes[4].name, "Game 1");
	strcpy(nodes[5].name, "Game 2");
	strcpy(nodes[6].name, "Score 1");
	strcpy(nodes[7].name, "Score 2");
	strcpy(nodes[8].name, "Score 3");
	strcpy(nodes[9].name, "Score 4");
	strcpy(nodes[10].name, "Score 5");
	
	for(int i = 0;i<11; i++)
	{
		//This could be done way better and more general with hashing taking in the node name as input.
		nodes[i].nodeID=i;
		//Chooses if the child is sub or action (this is not dynamic)
		if(i>=4){
			nodes[i].isAction=1;
		}
		else{
			nodes[i].isAction=0;
		}
	}
	
	
	nodes[0].numChildren = 3;
	nodes[1].numChildren = 2;
	nodes[2].numChildren = 5;
	nodes[3].numChildren = 0;
	nodes[4].numChildren = 0;
	nodes[5].numChildren = 0;
	nodes[6].numChildren = 0;
	nodes[7].numChildren = 0;
	nodes[8].numChildren = 0;
	nodes[9].numChildren = 0;
	nodes[10].numChildren = 0;
	
	uint8_t currentChildIdx = 1;
	
	nodes[0].parent = NULL;
	for (int i = 0; i< 11; i++) {
		for (int childIdx = 0; childIdx< nodes[i].numChildren; childIdx++) {
			nodes[i].children[childIdx] = nodes+currentChildIdx;
			(nodes+currentChildIdx)->parent = nodes+i;
			currentChildIdx++;
		}
	}
	navigateMenu(&joystick_pos);
	currentMenu.currentMenuItem = nodes; //set main menu as current
	currentMenu.childIndex = 0;
	currentMenu.lastDir = NEUTRAL;
	//printf("MENU INITIATED\n\r");
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
				if ((currentMenu.currentMenuItem->children[currentMenu.childIndex]->numChildren != 0) || (currentMenu.currentMenuItem->children[currentMenu.childIndex]->isAction)) {
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
		oled_print(currentMenu.currentMenuItem->children[i]->name);
		if (currentMenu.childIndex == i) {
			oled_print_arrow();
		}
	}
	
}

