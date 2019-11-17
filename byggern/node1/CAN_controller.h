/*
 * CAN.h
 *
 * Created: 25.09.2019 13:03:02
 *  Author: sanderfu
 */ 

#ifndef CAN_controller_H_
#define CAN_controller_H_

#define F_CPU 4915200

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>
#include "MCP2515.h"
#include "SPI.h"

void CAN_controller_init();
uint8_t CAN_controller_read(uint8_t addr);
void CAN_controller_write(uint8_t addr, uint8_t data);
void CAN_controller_RTS(uint8_t buffer);
void CAN_controller_setMode(uint8_t mode);
void CAN_controller_bitModify(uint8_t mask, uint8_t addr, uint8_t data);
#endif /* CAN_controller_H_ */