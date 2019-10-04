/*
 * CAN.c
 *
 * Created: 04.10.2019 15:12:56
 *  Author: haavaei
 */ 


#include "CAN_controller.h"
#include "CAN.h"

void CAN_init() {
	CAN_controller_init();
	
	
	
	
}
void CAN_transmit_message(CAN_message_t *message) {
	static int buffer_number = 0;
	
	buffer_number ++;
	buffer_number = buffer_number%3;
	
	
	//while TXVnCTRL. TXREQ not clear, wait
	

	
	//Load id in registers TXBnSIDH and TXBnSIDL
	switch(buffer_number) {
			case 0:
				CAN_controller_write(TXB0SIDH, (uint8_t) message->ID);
				CAN_controller_write(TXB0SIDL, (uint8_t) (message->ID >> 8));
				break;
			case 1:
				CAN_controller_write(TXB1SIDH, message->ID);
				CAN_controller_write(TXB1SIDL, message->ID >> 8);
				break;
			case 2:
				CAN_controller_write(TXB2SIDH, message->ID);
				CAN_controller_write(TXB2SIDL, message->ID >> 8);
				break;
			
			
	}
	
	//Load length in register TXBnDLC
	
	switch(buffer_number) {
			case 0:
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
				CAN_controller_write(TXB0D0 + i, message[i]);
				break;
			case 1:
				CAN_controller_write(TXB0D0 +i, message[i]);
				break;
			case 2:
				CAN_controller_write(TXB0D0 +i, message[i]);
				break;
			
			
		}
		
	}
	
	//Initialize CANINTE.TXInE
	
	
	//request_to_send

	CAN_controller_RTS(buffer);
		
}
