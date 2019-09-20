/*
 * sleep.c
 *
 * Created: 20.09.2019 15:16:02
 *  Author: torsteoe
 */ 

#include "sleep.h"
#include <avr/sleep.h>
#include <avr/interrupt.h>

void sleep_init() {
	
	//Choose sleep mode
	set_sleep_mode(SLEEP_MODE_IDLE);
	
	//Set sleep mode
	sleep_mode();
	
	//Enable sleep
	sleep_enable();
   
}

void sleep_now() {
	
	//disable analog reading
	ACSR |= (1 << ACD | 1 << ACIE);



	// Put the device to sleep:
	sleep_mode();
	sleep_cpu();

	// Upon waking up, sketch continues from this point.
	sleep_disable();
}