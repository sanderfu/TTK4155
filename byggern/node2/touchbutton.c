/*
 * touchbutton.c
 *
 * Created: 06.11.2019 15:45:44
 *  Author: torsteoe
 */ 
#include "touchButton.h"
#include "solenoid.h"
void touchButton_readButtonsOverCAN(CAN_message_t mess) {
	
	if (mess.ID == 0x03) {
		
		buttons.left_button = mess.data[0];
		buttons.right_button = mess.data[1];
		if (buttons.left_button == 0) {
			shooting = 0;
		}
	}
}