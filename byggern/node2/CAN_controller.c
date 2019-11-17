/*
 * CAN.c
 *
 * Created: 25.09.2019 13:02:48
 *  Author: sanderfu
 */ 



#define F_CPU 16000000

#include <avr/io.h>
#include "MCP2515.h"
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "CAN_controller.h"
#include "SPI.h"

#define I 7

uint8_t CAN_controller_read(uint8_t addr) {
	SPI_setChipSelect(PB7, 0); 
	SPI_masterWrite(MCP_READ);
	SPI_masterWrite(addr);
	uint8_t data = SPI_masterRead();
	SPI_setChipSelect(PB7, 1);
	
	return data;
}

void CAN_controller_write(uint8_t addr, uint8_t data) {
	SPI_setChipSelect(PB7, 0);
	
	SPI_masterWrite(MCP_WRITE);
	SPI_masterWrite(addr);
	SPI_masterWrite(data);
	
	SPI_setChipSelect(PB7, 1); 
	
}
void CAN_controller_bitModify(uint8_t mask, uint8_t addr, uint8_t data) {
		SPI_setChipSelect(PB7, 0);
		SPI_masterWrite(MCP_BITMOD);
		SPI_masterWrite(addr);
		SPI_masterWrite(mask);
		SPI_masterWrite(data);
		
		SPI_setChipSelect(PB7, 1);

}
void CAN_controller_reset() {
	SPI_setChipSelect(PB7, 0);
	//printf("CAN reset\n\r");
	SPI_masterWrite(MCP_RESET);
	SPI_setChipSelect(PB7, 1);
}
void CAN_controller_init() {
	SPI_masterInit();

	CAN_controller_setMode(MODE_NORMAL);

	//set interrupt on 2560
	EIMSK |= 1 << INT4;	//interrupt on pin INT4
	EICRB |= 1 << ISC41; //Turn on falling edge
	EICRB &= ~(1 << ISC40); //....

	//set PE4 as input
	DDRE  &= (1 << PE4); //set as input.
	
	
	
	_delay_ms(200);
	
	volatile uint8_t status = CAN_controller_read(MCP_CANSTAT);
}

void CAN_controller_RTS(uint8_t buffer) {
	SPI_setChipSelect(PB7, 0);
	switch (buffer) {
		case 0:
			SPI_masterWrite(MCP_RTS_TX0);
			break;
		case 1:
			SPI_masterWrite(MCP_RTS_TX1);
			break;
		case 2:
			SPI_masterWrite(MCP_RTS_TX2);
			break;
		default: 
			break;			
	}
	SPI_setChipSelect(PB7, 1);
}

void CAN_controller_setMode(uint8_t mode) {
	
	
	
	CAN_controller_reset();
	uint8_t status = CAN_controller_read(MCP_CANSTAT);
	uint8_t mode_bits = (status & MODE_MASK);
	
	if (mode_bits != MODE_CONFIG) {
		//printf("Not in config mode, \t %i\n\r", mode_bits);
		return;
	}
	
	
	//set mode
	CAN_controller_bitModify(0b11101110, MCP_CANCTRL, mode | (0b1100));
	
	//enable interrupts
	CAN_controller_bitModify(0b11111111, MCP_CANINTE, 0b1);
	CAN_controller_bitModify(0b01100000, MCP_RXB0CTRL, 0b01100000); //receive any type of message, no filter p. 27

	_delay_ms(200);
	status = CAN_controller_read(MCP_CANSTAT);
	mode_bits = (status & MODE_MASK);
	if (mode_bits != mode) {
		//printf("Not in correct mode: Mode: %i\n\r", mode_bits);

	}
	//printf("Mode set: %i\n\r", status & MODE_MASK);
}

