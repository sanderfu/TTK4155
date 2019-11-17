/*
 * CAN.h
 *
 * Created: 04.10.2019 15:12:44
 *  Author: haavaei
 */ 


#ifndef CAN_H_
#define CAN_H_
#include <avr/io.h>
typedef struct {
	volatile uint8_t data[8];
	volatile uint16_t ID;
	volatile uint8_t data_length;

} CAN_message_t;

CAN_message_t received_message;
uint8_t flag;

//Initialize CAN
void CAN_init();

//Transmit CAN message
void CAN_transmit_message(CAN_message_t * message);

//Receive CAN message
void CAN_receiveMessage(CAN_message_t * received_message);

//Send joystick, slider and button positions
void CAN_sendInputData();

//clear CAN receive interrupt
void CAN_clearInterrupt();
#endif /* CAN_H_ */