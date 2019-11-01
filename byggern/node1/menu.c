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
	
	printf("this_init initiating");
	
	strcpy(nodes[0].name, "Main menu");
	strcpy(nodes[1].name, "Play game");
	strcpy(nodes[2].name, "High scores");
	strcpy(nodes[3].name, "Music");
	strcpy(nodes[4].name, "Game 1");
	strcpy(nodes[5].name, "Game 2");
	strcpy(nodes[6].name, "Score 1");
	strcpy(nodes[7].name, "Score 2");
	strcpy(nodes[8].name, "Score 3");
	strcpy(nodes[9].name, "Score 4");
	strcpy(nodes[10].name, "Score 5");

	
	
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
	
	/*
	nodes[0].children = {nodes+1, nodes+2, nodes+3}; 
	nodes[1].children = {nodes+4, nodes+5};
	nodes[2].children = {nodes+6, nodes+7, nodes+8, nodes+9, nodes+10};

	nodes[1].parent = nodes;
	nodes[2].parent = nodes;
	nodes[3].parent = nodes;
	nodes[4].parent = nodes+1;
	nodes[5].parent = nodes+1;
	nodes[6].parent = nodes+2;
	nodes[7].parent = nodes+2;
	nodes[8].parent = nodes+2;
	nodes[9].parent = nodes+2;
	nodes[10].parent = nodes+2;
	*/
	/*
	for (int i = 0; i<11; i++) {
		printf("Node %i\n\r", i);
		printf( nodes[i].name);
		for (int childIdx=0; childIdx<nodes[i].numChildren; childIdx++) {
			printf("child: ");
			printf(nodes[i].children[childIdx]->name);
			printf("\n\r");

		}
		if (i != 0) {
			printf("Parent");
			printf(nodes[i].parent->name);
			printf("\n\r");

		}
		
	}
	*/
	currentMenu.currentMenuItem = nodes; //set main menu as current
	currentMenu.childIndex = 0;
	currentMenu.lastDir = NEUTRAL;
	//printf("MENU INITIATED\n\r");
}




/*

MenuNode* mainMenuInit (void){
	MenuNode* ptr = (MenuNode*) malloc(sizeof(MenuNode));
	ptr->numChildren = 0;
	strcpy(ptr->name, "Main menu");
	ptr->parent = NULL;
	
	return ptr;
}
*/
/*
MenuNode * addChild(MenuNode* parent, char* child_name)
{
	MenuNode* childPtr = (MenuNode*) malloc(sizeof(MenuNode));
	
	parent->numChildren++;
	strcpy(childPtr->name, child_name);
	childPtr->parent = parent;
	//printf("Added child: %s\n\r", childPtr->name);

	if (parent->numChildren > MAXCHILDREN) {
		printf("REached max: \n\r");
		return NULL;
	} 
	parent->children[parent->numChildren-1]=childPtr;
	parent->children[parent->numChildren-1]->numChildren = 0;
	return childPtr;
}
*/
/*
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
	
	//MenuNode* childSettings = addChild(mainMenu,"Settings");
	
	MenuNode* childMusic = addChild(mainMenu,"Music");
	addChild(childMusic, "Rick");
	
	
	//addChild(childSettings, "No sett");
	
	
	printf("Number of children: %i\n\r",mainMenu->numChildren);

	*/
	/*
	MenuNode* childSettings = addChild(mainMenu,"Settings");
	addChild(childSettings, "No sett");
	printf("Number of children: %i\n\r",childSettings->numChildren);
	*/
	/*
	currentMenu.currentMenuItem = mainMenu;
	currentMenu.childIndex = 0;
	currentMenu.lastDir = NEUTRAL;
	
	return mainMenu;
}
*/
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
		oled_print(currentMenu.currentMenuItem->children[i]->name);
		if (currentMenu.childIndex == i) {
			oled_print_arrow();
		}
	}
	
}

