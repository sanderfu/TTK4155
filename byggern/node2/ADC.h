/*
 * ADC.h
 *
 * Created: 25.10.2019 09:59:17
 *  Author: haavaei
 */ 


#ifndef ADC_H_
#define ADC_H_
#include <avr/io.h>
#include <stdint.h>

void ADC_init();

uint16_t ADC_read();



#endif /* ADC_H_ */