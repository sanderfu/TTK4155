/*
 * SPI.h
 *
 * Created: 25.09.2019 09:45:23
 *  Author: sanderfu
 */ 


#ifndef SPI_H_
#define SPI_H_
#include <avr/io.h>

void SPI_masterInit(void);
void SPI_masterWrite(char cData);
void SPI_setChipSelect(uint8_t pin, uint8_t setHigh );
uint8_t SPI_masterRead();

#endif /* SPI_H_ */