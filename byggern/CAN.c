/*
 * CAN.c
 *
 * Created: 04.10.2019 15:12:56
 *  Author: haavaei
 */ 


#include "CAN_controller.h"
#include "CAN.h"
#include "MCP2515.h"

#include <stdio.h>
void CAN_init() {
	CAN_controller_init();
	
	
	
	
}
void CAN_transmit_message(CAN_message_t *message) {
	printf("Transmitting message");
	static int buffer_number = 0;
	
	buffer_number++;
	buffer_number = buffer_number%3;
	
	buffer_number = 0;
	
	//while TXBnCTRL. TXREQ not clear, wait
	switch(buffer_number) {
		case 0:
			while (CAN_controller_read(TXB0CTRL) & 1 << TXREQ);
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
	/*
	//Initialize CANINTE.TXInE and set 0
	switch(buffer_number) {
		case 0:
			CAN_controller_write(1<<TX0IE);
			break;
		case 1:
			CAN_controller_write(1<<TX1IE);
			break;
		case 2:
			CAN_controller_write(1<<TX2IE);
			break;		
		
	}
	*/
	
	//PRIORITET?
	
	
	
	
	
	
	//Load id in registers TXBnSIDH and TXBnSIDL
	switch(buffer_number) {
			case 0:
				CAN_controller_write(TXB0SIDL, (uint8_t) message->ID);
				CAN_controller_write(TXB0SIDH, (uint8_t) (message->ID >> 8));
				break;
			case 1:
				CAN_controller_write(TXB1SIDL, (uint8_t) message->ID);
				CAN_controller_write(TXB1SIDH, (uint8_t)  message->ID >> 8);
				break;
			case 2:
				CAN_controller_write(TXB2SIDL, (uint8_t) message->ID);
				CAN_controller_write(TXB2SIDH, (uint8_t) message->ID >> 8);
				break;
			
			
	}
	
	//Load length in register TXBnDLC
	
	switch(buffer_number) {
			case 0:
				printf("\n\rtransmitting data length: %i\n\r", message->data_length);
				CAN_controller_write(TXB0DLC,message->data_length);
				break;
			case 1:
				CAN_controller_write(TXB1DLC,message->data_length);
				break;
			case 2:
				CAN_controller_write(TXB2DLC,message->data_length);
				break;
			
			
	}
	//iterate in for loop length = message.length and load TXBnDm
	for (int i = 0; i != message->data_length; i++) {
		switch(buffer_number) {
			case 0:
				printf("transmitting data: %i\t", message->data[i]);
				CAN_controller_write(TXB0D0 + i, message->data[i]);
				break;
			case 1:
				CAN_controller_write(TXB1D0 +i, message->data[i]);
				break;
			case 2:
				CAN_controller_write(TXB2D0 +i, message->data[i]);
				break;
			
			
		}
		
	}
	
	
	
	//request_to_send

	CAN_controller_RTS(buffer_number);
	
	//ERROR HANDLING?	
}

void CAN_receiveMessage(CAN_message_t * received_message) {
	
	
	uint8_t buffer = 0;
	switch (buffer) {
		case 0:
				received_message->ID = CAN_controller_read(MCP_RXB0SIDH << 8)+CAN_controller_read(MCP_RXB0SIDL) ; 
				received_message->data_length = CAN_controller_read(MCP_RXB0DLC);
				printf("data length read: %i\n\r", received_message->data_length);
				for (int i = 0; i != received_message->data_length; i++) {
					received_message->data[i] = CAN_controller_read(MCP_RXB0D0 + i);
				//	printf("data: %i\t", received_message->data[i]);

				}
				break;
		case 1:
				received_message->ID = CAN_controller_read(MCP_RXB1SIDH << 8)+CAN_controller_read(MCP_RXB1SIDL) ; 
				received_message->data_length = CAN_controller_read(MCP_RXB1DLC);
				for (int i = 0; i != received_message->data_length; i++) {
					received_message->data[i] = CAN_controller_read(MCP_RXB1D0 + i);
				}
				break;
	}
	
	
	
	
}
