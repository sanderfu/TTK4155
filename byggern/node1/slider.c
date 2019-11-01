#define LEFT_POS_CHANNEL 2
#define RIGHT_POS_CHANNEL 3
#include "slider.h"
#include "adc.h"
#include "CAN.h"
void slider_readPosition(slider_position_t * pos) {
	slider_pos.left_pos = readAdc(LEFT_POS_CHANNEL);
	slider_pos.right_pos = readAdc(RIGHT_POS_CHANNEL);
}

void slider_sendPositionOverCAN() {
	//printf("sending");

	CAN_message_t message;
	
	message.ID = 0x02;
	message.data_length = 2;
	
	message.data[0] = slider_pos.left_pos;
	message.data[1] = slider_pos.right_pos;
	
	
	CAN_transmit_message(&message);
}