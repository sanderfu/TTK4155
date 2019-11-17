/*
 * SPI.c
 *
 * Created: 25.09.2019 09:44:52
 *  Author: sanderfu
 */ 


#include "SPI.h"

void SPI_masterInit(void)
{
	/* Set MOSI and SCK output, all others input */
	DDRB |= (1 << PB5) | (1 << PB7);
	//define select slave as output
	DDRB |= (1 << PB4);
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0);
	SPI_setChipSelect(PB4, 1);
}

void SPI_slaveInit(void) {
	DDRB = (1 << PB6);
	SPCR = (1 << SPE);
	
}
void SPI_masterWrite(char cData)
{
	SPDR = cData;
	while (!(SPSR & (1<<SPIF)));

}

uint8_t SPI_masterRead() {
	SPDR = 0;
	while (!(SPSR & (1<<SPIF)));
	return SPDR;
}

void SPI_setChipSelect(uint8_t pin, uint8_t setHigh ) {
	if (setHigh) {
		PORTB |= (1 << pin); //chip select high
	}
	else {
		PORTB &= ~(1 << pin); //chip select low
	}
}