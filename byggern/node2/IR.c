/*
 * IR.c
 *
 * Created: 25.10.2019 11:45:47
 *  Author: haavaei
 */ 

#include "IR.h"
#include "ADC.h"
#include "game.h"
#define F_CPU 16000000

#include <avr/delay.h>

void IR_detectGoal() {
	int temp5ms = numOf5ms;
	uint16_t adc_value = ADC_read();
	
	if (adc_value < 50) {
		if (gameData.score != 0) {
			gameData.score--;
		}
		
		game_sendGameData();

		while(adc_value<50) {
			_delay_ms(2000);
			adc_value = ADC_read();
		}
	}
	numOf5ms = temp5ms;
}
