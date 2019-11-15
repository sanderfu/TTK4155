/*
 * encoder.c
 *
 * Created: 01.11.2019 13:42:50
 *  Author: sanderfu
 */ 

#include "encoder.h"
#include <stdio.h>
#define F_CPU 16000000
#include <util/delay.h>
#include <avr/io.h>
void encoder_init() {
	DDRH |= (1 <<PH5);
	DDRH |= (1 <<PH3);
	DDRH |= (1 <<PH6);
   
	//!Rst pin set high to use the encoder to know how much motor has rotated.
	PORTH &= ~(1 << PH5);
	_delay_us(20);

	PORTH |= (1 << PH6);
		_delay_us(20);

	PORTH &= ~(1 << PH6);
		_delay_us(20);

	PORTH |= (1 << PH6);
		_delay_us(20);

	PORTH |= (1 << PH5);
	encoder_maxValue = -15000;

}
void encoder_convertValues() {
	float a = (100.0-(-100.0))/encoder_maxValue;
	float b = -100;
	converted_encoderValue = a*encoder_value + b;
	//printf("Converted encoder_values: %d\n\r", converted_encoderValue);
}
void encoder_readValues() {
	
	//set !OE value low
	PORTH &= ~(1 << PH5);
	
	//set select low to get high byte, then wait 20 microseconds
	PORTH &= ~(1 << PH3);
	_delay_us(20);
	
	//Read msb !
	uint8_t high_val = PINK & 0xff;

	
	//set select low to get high byte, then wait 20 microseconds
	PORTH |= (1 << PH3);
	_delay_us(20);
	//Read lsb !
	uint8_t low_val =  PINK & 0xff;

	
	
	//toggle reset pin
	
	//PORTH |= (1 << PH6);
	//PORTH &= ~(1 << PH6);
	//PORTH |= (1 << PH6);

	//Set !OE high
	PORTH |= (1 << PH5);
	
	//Process received data.
	int16_t rec_data = (high_val << 8) +low_val;
	
	//convert from two-complement
	if (rec_data >= 0) {
		encoder_value = rec_data;
	}
	else {
		encoder_value = (-1* (~rec_data +1));
	}
	if (encoder_value>0) {
		//Encoder_reset
		PORTH |= (1 << PH6);
		_delay_us(20);

		PORTH &= ~(1 << PH6);
		_delay_us(20);

		PORTH |= (1 << PH6);
		_delay_us(20);
		
	} /*
	else if (encoder_value < encoder_maxValue) {
		encoder_value = encoder_maxValue;
		offset += encoder_value-encoder_maxValue;
		encoder_maxValue += offset;
	}
	*/
	
	encoder_convertValues();
	//printf("Encoder_values: %d\n\r", encoder_value);
}

