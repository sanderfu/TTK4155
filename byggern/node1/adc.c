#include "adc.h"
#include "setup.h"
#define FOSC 4915200
#define F_CPU 4915200
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1
#include "adc.h"



void adcInit(void) {
	
	DDRE &= ~(1<<PINE0);
}


 
uint8_t readAdc(uint8_t channel){ //for ch1 channel = 0;
	volatile char * adc = (char *) 0x1400;
	
	*adc = 0x04 | channel;
	

	while (test_bit(PINE, PINE0)) {

	}
	
	return *adc;
}