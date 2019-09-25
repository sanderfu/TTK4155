/*
 * SPI.h
 *
 * Created: 25.09.2019 09:45:23
 *  Author: sanderfu
 */ 


#ifndef SPI_H_
#define SPI_H_
#include <avr/io.h>

void SPI_MasterInit(void);
void SPI_MasterTransmit(char cData);



#endif /* SPI_H_ */