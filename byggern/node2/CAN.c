/*
 * CAN.c
 *
 * Created: 04.10.2019 15:12:56
 *  Author: haavaei
 */ 


#include "CAN_controller.h"
#include "CAN.h"
#include "MCP2515.h"
#include "joystick.h"
#include "slider.h"
#include "touchButton.h"
#include "solenoid.h"
#include "game.h"
#define F_CPU 16000000

#include <util/delay.h>
#include <stdio.h>
void CAN_init() {
	CAN_controller_init();
	
}



void CAN_clearInterrupt()
{
	uint8_t mask = 0b11;
	CAN_controller_bitModify(mask, CANINTF, 0b00);
}


void CAN_transmit_message(CAN_message_t *message) {
	printf("Transmitting message");
	//changing between three buffers
	static int buffer_number = 0;
	
	buffer_number++;
	buffer_number = buffer_number%3;
	//buffer_number =0;
	
	/*
	
	//while TXBnCTRL. TXREQ not clear, wait
	switch(buffer_number) {
		case 0:
			while (!(CAN_controller_read(TXB0CTRL) & 1 << TXREQ));
			break;
		break;
		case 1:
			while (CAN_controller_read(TXB1CTRL) & 1 << TXREQ);
			break;
		break;
		case 2:
			while (CAN_controller_read(TXB2CTRL) & 1 << TXREQ);
			break;
		break;
		
		
	}
	
	*/
	
	

	

	//Load ID in message
	switch(buffer_number) {
			case 0:
				CAN_controller_bitModify(0b11100000, TXB0SIDL, (uint8_t) ((message->ID & 0b111) << 5));
				CAN_controller_write(TXB0SIDH, (uint8_t) ( message->ID >> 3) );

				break;
			case 1:
				CAN_controller_bitModify(0b11100000, TXB1SIDL, (uint8_t) ((message->ID & 0b111) << 5));
				CAN_controller_write(TXB1SIDH, (uint8_t) ( message->ID >> 3) );
				
				break;
			case 2:
				CAN_controller_bitModify(0b11100000, TXB2SIDL, (uint8_t) ((message->ID & 0b111) << 5));
				CAN_controller_write(TXB2SIDH, (uint8_t) ( message->ID >> 3) );
				break;
			
			
	}
		
	//Filling message with data length
	switch(buffer_number) {
			case 0:
				CAN_controller_bitModify(0b1111, TXB0DLC, message->data_length);
				break;
			case 1:
				CAN_controller_bitModify(0b1111, TXB1DLC, message->data_length);
				break;
			case 2:
				CAN_controller_bitModify(0b1111, TXB2DLC, message->data_length);
				break;
			
			
	}

	//Filling message with data.
	for (uint8_t i = 0; i != message->data_length; i++) {
		switch(buffer_number) {
			case 0:
				CAN_controller_write(TXB0D0 + i, message->data[i]);
				break;
			case 1:
				CAN_controller_write(TXB1D0 + i, message->data[i]);
				break;
			case 2:
				CAN_controller_write(TXB2D0 + i, message->data[i]);
				break;
			
			
		}
		
	}
	

	
	//request_to_send
	CAN_controller_RTS(buffer_number);

	//Currently no error handling
}

void CAN_receiveMessage() {
	CAN_message_t received_message;
	uint8_t buffer = 0;
	switch (buffer) {
		case 0:
				received_message.ID = ((CAN_controller_read(MCP_RXB0SIDL) & 0b11100000) >> 5) + (CAN_controller_read(MCP_RXB0SIDH) << 3); 
				
				//printf("Whole id: %i\n\r", received_message.ID);
				received_message.data_length = (CAN_controller_read(MCP_RXB0DLC) & 0b00001111);
				//printf("data length read: %i\n\r",(CAN_controller_read(MCP_RXB0DLC) & 0b00001111));
				for (uint8_t i = 0; i != received_message.data_length; i++) {
					received_message.data[i] = CAN_controller_read(MCP_RXB0D0 + i);
				//	printf("data: %i\t", received_message.data[i]);

				}
				break;
				
	}
	

	
	switch(received_message.ID) {
		case 1:
			CAN_readPosition(received_message);
			break;
		case 2:
			game_init();
			break;
		case 3:
			game_stop();
			break;
		case 0x10:
			setupInit();
			break;
	}
	
	
	
	
}

void CAN_readPosition(CAN_message_t mess) {
	
	int32_t dataLeft = mess.data[0];
	int32_t dataRight = mess.data[1];

	slider_pos.left_pos = (dataLeft*200)/255-100;
	slider_pos.right_pos = (dataRight*200)/255-100;
	buttons.left_button = mess.data[2];
	buttons.right_button = mess.data[3];
	if (buttons.left_button == 0) {
		shooting = 0;
	}

	joystick_pos.x_pos = mess.data[4];
	joystick_pos.y_pos = mess.data[5];
	joystick_pos.angle = atan2(joystick_pos.y_pos, joystick_pos.x_pos)*360/2.0/3.14;
}