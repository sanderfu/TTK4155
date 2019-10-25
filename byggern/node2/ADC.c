/*
 *ADC.c
 *
 * Created: 18.10.2019 14:20:46
 *  Author: torsteoe
 */ 
#include "ADC.h"
#include <stdio.h>
#include <avr/interrupt.h>
void ADC_init() {
	//Set pin ADC0 to input, PF0
	DDRF &= ~(1 << PF0);
	
	//Set prescaling in ADCSRA, ADPS bits
	ADCSRA |= (1 << ADPS2 | 1 << ADPS1 | 1 << ADPS0);
	
	
	//Set adlar = 0, right adjusted ADCH
	ADMUX &= ~(1 << ADLAR);
	
	
	
	//Select AVCC as voltage reference
	ADMUX &= ~(1 << REFS1);
	ADMUX |=  (1 << REFS0);
	
	//set ADEN in ADCSRA, enable adc
	ADCSRA |= (1 << ADEN);
		
		

	
}

uint16_t ADC_read() {
	//printf("adc read\n\r");

	//Select channel 0 (ADC0)
	ADMUX &= ~(1 << MUX4 | 1 << MUX3 | 1 << MUX2 | 1 << MUX1 | 1 << MUX0 );
	ADCSRB &= ~(1 << MUX5);
	//Start conversion, set ADSC to 1 (Use single conversion).
	ADCSRA |= (1 << ADSC);
	//Wait until conversion complete :
	//While ADIF is not high, wait
	while (!(ADCSRA & (1<<ADIF))){
		//printf("in while loop\n");
	}
	//result present in ADCH and ADCL
	//Read adcl first, then ADCH
	uint8_t low = ADCL;
	uint8_t high = ADCH;
	
	uint16_t adcValue = low + (high << 8);
	return adcValue;/// adcValue;
	//adc = v-in*1024/v-ref
}