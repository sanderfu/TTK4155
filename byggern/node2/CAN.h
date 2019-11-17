/**
 * @file
 * @brief A library for communicating via CAN on node 2.
 */



#ifndef CAN_H_
#define CAN_H_
#include <avr/io.h>

typedef struct {
	volatile uint8_t data[8];
	volatile uint16_t ID;
	volatile uint8_t data_length;

} CAN_message_t;

void CAN_transmit_message(CAN_message_t * message);
void CAN_receiveMessage();
void CAN_init();
void CAN_readPosition(CAN_message_t mess);
void CAN_clearInterrupt();
#endif /* CAN_H_ */