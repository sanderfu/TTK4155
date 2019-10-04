#ifndef SETUP_H_
#define SETUP_H_

#define FOSC 4915200
#define F_CPU 4915200
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1
#include <stdlib.h>
#include <avr/io.h>
#define test_bit(reg, bit) (reg & (1<<bit))

uint8_t setupInit(void);

#endif