/*
 * CAN.h
 *
 * Created: 04.10.2019 15:12:44
 *  Author: haavaei
 */ 


#ifndef CAN_H_
#define CAN_H_

typedef struct {
	volatile uint8_t data[8];
	volatile uint16_t ID;
	volatile uint8_t data_length;

} CAN_message_t;

void CAN_transmit_message(CAN_message_t * message);
void CAN_receiveMessage(CAN_message_t * received_message);
void CAN_init();

#endif /* CAN_H_ */