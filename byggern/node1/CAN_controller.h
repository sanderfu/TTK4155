/*
 * CAN.h
 *
 * Created: 25.09.2019 13:03:02
 *  Author: sanderfu
 */ 

#ifndef CAN_controller_H_
#define CAN_controller_H_

#include <avr/io.h>


void CAN_controller_init();
uint8_t CAN_controller_read(uint8_t addr);
void CAN_controller_write(uint8_t addr, uint8_t data);
void CAN_controller_RTS(uint8_t buffer);
void CAN_controller_setMode(uint8_t mode);
void CAN_controller_bitModify(uint8_t mask, uint8_t addr, uint8_t data);
#endif /* CAN_controller_H_ */