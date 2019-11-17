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
   
}

void sleep_now() {
	
	
	// Put the device to sleep:
	sleep_mode();
	
	
	// Upon waking up, sketch continues from this point.
}