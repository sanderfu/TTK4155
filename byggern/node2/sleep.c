/*
 * sleep.c
 *
 * Created: 25.10.2019 13:50:44
 *  Author: haavaei
 */ 

#include "sleep.h"
#include <avr/sleep.h>
#include <avr/interrupt.h>

void sleep_init() {
	
	//Choose sleep mode
	set_sleep_mode(SLEEP_MODE_IDLE);
	
	
   
}

void sleep_now() {
	
	//disable analog reading
	ACSR |= (1 << ACD | 1 << ACIE);

	

	// Put the device to sleep:
	sleep_mode();
	
	
	// Upon waking up, sketch continues from this point.
	
}