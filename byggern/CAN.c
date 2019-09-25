/*
 * CAN.c
 *
 * Created: 25.09.2019 13:02:48
 *  Author: sanderfu
 */ 





#include <avr/io.h>
#include "MCP2515.h"
#include <stdlib.h>
#include <util/delay.h>


uint8_t CAN_read(uint8_t addr) {
	SPI_setChipSelect(PB4, 0); 
	SPI_masterWrite(MCP_READ);
	SPI_masterWrite(addr);
	uint8_t data = SPI_masterRead();
	SPI_setChipSelect(PB4, 1);
	
	return data;
}

void CAN_write(uint8_t addr, uint8_t data) {
	SPI_setChipSelect(PB4, 0);
	
	SPI_masterWrite(MCP_WRITE);
	SPI_masterWrite(addr);
	SPI_masterWrite(data);
	
	SPI_setChipSelect(PB4, 1); 
	
}
void CAN_bitModify(uint8_t mask, uint8_t addr, uint8_t data) {
		SPI_setChipSelect(PB4, 0);
		SPI_masterWrite(MCP_BITMOD);
		SPI_masterWrite(addr);
		SPI_masterWrite(mask);
		SPI_masterWrite(data);
		
		SPI_setChipSelect(PB4, 1);

}

void CAN_init() {
	//reset with spi command
	SPI_setChipSelect(PB4, 0);
	printf("Before spi write");
	SPI_masterWrite(MCP_RESET);
	SPI_setChipSelect(PB4, 1);
	printf("After spi write\n\r");
	_delay_ms(200);
	
	 //set in loopback mode p.60 MCP2515
	CAN_bitModify(0b11100000, MCP_CANCTRL, MODE_LOOPBACK);
	CAN_bitModify(0b01100000, MCP_RXB0CTRL, 0b01100000); //receive any type of message, no filter p. 27
	CAN_bitModify(0b1, MCP_CANINTE, 0b1);
	
	_delay_ms(200);
	printf("after write to canctrl\n\r");
	
	//Check CANSTAT register
	uint8_t data = CAN_read(MCP_CANSTAT);
	printf("Data: %i\n\r", data);
}