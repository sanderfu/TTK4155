/*
 * CAN.h
 *
 * Created: 04.10.2019 15:12:44
 *  Author: haavaei
 */ 


#ifndef CAN_H_
#define CAN_H_

typedef struct {
	unsigned int ID;
	uint8_t data_length;
	uint8_t data[8];
} CAN_message_t;

void CAN_transmit_message(CAN_message_t * message);
void CAN_receiveMessage(CAN_message_t * received_message);
void CAN_init();

#endif /* CAN_H_ */