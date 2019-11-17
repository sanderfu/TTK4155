#define BUTTON_LEFT (PINB & (1 << PB1))
#define BUTTON_RIGHT (PINB & (1 << PB2))

#include "touchButton.h"
#include "adc.h"
#include "CAN.h"
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