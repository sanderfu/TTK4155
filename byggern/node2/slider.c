/*
 * slider.c
 *
 * Created: 01.11.2019 10:48:07
 *  Author: sanderfu
 */ 
#include "slider.h"
void slider_readPositionOverCAN(CAN_message_t mess) {
	
	if (mess.ID == 0x02) {
		int32_t dataLeft = mess.data[0];
		int32_t dataRight = mess.data[1];

		slider_pos.left_pos = (dataLeft*200)/255-100;
		slider_pos.right_pos = (dataRight*200)/255-100;
	}
}

