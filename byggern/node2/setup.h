/**
 * @file
 * @brief A library for initial setup of Node 2.
 */
#ifndef SETUP_H_
#define SETUP_H_

#define FOSC 16000000
#define F_CPU 16000000
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#define test_bit(reg, bit) (reg & (1<<bit))

void setupInit(void);

#endif