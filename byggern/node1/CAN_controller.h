/*
 * CAN.h
 *
 * Created: 25.09.2019 13:03:02
 *  Author: sanderfu
 */ 

#ifndef CAN_controller_H_
#define CAN_controller_H_

#include <avr/io.h>

//Initiate and set in normal mode
void CAN_controller_init();

//Read from Can_transceiver
uint8_t CAN_controller_read(uint8_t addr);

//Write to Can transceiver
void CAN_controller_write(uint8_t addr, uint8_t data);

//Request to send, function to be called after loading transmission buffer.
void CAN_controller_RTS(uint8_t buffer);

//change mode of Can_controller.
void CAN_controller_setMode(uint8_t mode);

//Modify chosen bits on transceiver register.
void CAN_controller_bitModify(uint8_t mask, uint8_t addr, uint8_t data);
#endif /* CAN_controller_H_ */