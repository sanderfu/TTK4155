/*
 * IR.c
 *
 * Created: 25.10.2019 11:45:47
 *  Author: haavaei
 */ 

#include "IR.h"
#include "ADC.h"

void IR_detectGoal() {
	
	uint16_t adc_value = ADC_read();
	
	if (adc_value < 50) {
		goals++;
		_delay_ms(200);
	}
}
