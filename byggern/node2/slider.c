/*
 * slider.c
 *
 * Created: 01.11.2019 10:48:07
 *  Author: sanderfu
 */ 
#include "slider.h"
void slider_readPositionOverCAN(CAN_message_t mess) {
	
	if (mess.ID == 0x02) {
		slider_pos.left_pos = mess.data[0];
		slider_pos.right_pos = mess.data[1];
	}
}

