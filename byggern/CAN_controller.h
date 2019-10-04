/*
 * CAN.h
 *
 * Created: 25.09.2019 13:03:02
 *  Author: sanderfu
 */ 

#include <avr/io.h>
#include <stdlib.h>
#ifndef CAN_controller_H_
#define CAN_controller_H_
void CAN_controller_init();
uint8_t CAN_controller_read(uint8_t addr);
void CAN_controller_write(uint8_t addr, uint8_t data);
void CAN_controller_RTS(uint8_t buffer);
#endif /* CAN_controller_H_ */