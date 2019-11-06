
#include "touchButton.h"
#include "CAN.h"
#include "adc.h"

void touchButton_init() {
	DDRB &= ~(1 << BUTTON_LEFT | 1 << BUTTON_RIGHT);
}
void touchButton_readButtons() {
	buttons.left_button = !!(BUTTON_LEFT);
	buttons.right_button = !!(BUTTON_RIGHT);
}

void touchButton_sendButtonsOverCAN() {
	//printf("sending");

	CAN_message_t message;
	
	message.ID = 0x03;
	message.data_length = 2;
	
	message.data[0] = buttons.left_button;
	message.data[1] = buttons.right_button;
	
	
	CAN_transmit_message(&message);
}