/*
 * CAN.h
 *
 * Created: 04.10.2019 15:12:44
 *  Author: haavaei
 */ 


#ifndef CAN_H_
#define CAN_H_

#include "CAN_controller.h"
#include "CAN.h"
#include "MCP2515.h"
#include "slider.h"
#include "joystick.h"
#include "touchButton.h"

#define F_CPU 4915200

#include <util/delay.h>
#include <stdio.h>

typedef struct {
	volatile uint8_t data[8];
	volatile uint16_t ID;
	volatile uint8_t data_length;

} CAN_message_t;

volatile CAN_message_t received_message;
volatile uint8_t flag;

void CAN_transmit_message(CAN_message_t * message);
void CAN_receiveMessage(CAN_message_t * received_message);
void CAN_init();
void CAN_sendInputData();
void CAN_clearInterrupt();
#endif /* CAN_H_ */