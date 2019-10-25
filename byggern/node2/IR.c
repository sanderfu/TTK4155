/*
 * IR.c
 *
 * Created: 18.10.2019 14:20:46
 *  Author: torsteoe
 */ 
#include "IR.h"
#include <stdio.h>
#include <avr/interrupt.h>
void IR_init() {
	//Set pin ADC0 to input, PF0
	DDRF &= ~(1 << PF0);
	//set ADEN in ADCSRA, enable adc
	ADCSRA |= (1 << ADEN);
	
	//Set prescaling in ADCSRA, ADPS bits
	ADCSRA |= (1 << ADPS2 | 1 << ADPS1 | 1 << ADPS0);
	
	
	//Set adlar = 0, right adjusted ADCH
	ADMUX &= ~(1 << ADLAR);
	
	//enable adc conversion complete interrupt
	ADCSRA |= (1 << ADIE);
	
	
	//Select AVCC as voltage reference
	ADMUX &= ~(1 << REFS1);
	ADMUX |=  (1 << REFS0);
	
}

uint16_t IR_read() {
	//Select channel 0 (ADC0)
	cli();
	ADMUX &= ~(1 << MUX4 | 1 << MUX3 | 1 << MUX2 | 1 << MUX1 | 1 << MUX0 );
	ADCSRB &= ~(1 << MUX5);
	printf("check 1");
	//Start conversion, set ADSC to 1 (Use single conversion).
	ADCSRA |= (1 << ADSC);
	printf("check 2");

	//Wait until conversion complete :
	//While ADIF is not high, wait
	while (!(ADCSRA & (1<<ADIF)));
	printf("check 3");
	//result present in ADCH and ADCL
	//Read adcl first, then ADCH
	
	
	uint16_t adcValue = ADCL + (ADCH << 8);
	return adcValue;
	//adc = v-in*1024/v-ref
	sei();
}