/*
 * solenoid.c
 *
 * Created: 06.11.2019 13:08:11
 *  Author: torsteoe
 */ 
#define F_CPU 16000000

#include <util/delay.h>
#include <avr/io.h>
#include "solenoid.h"
void solenoid_init() {
	DDRE  |= (1 << PE5);
	PORTE |= (1 << PE5);

	shooting = 0;
}
void solenoid_setPulse() {
	shooting = 1;
	PORTE &= ~(1 << PE5);
	_delay_ms(75);
	PORTE |= (1 << PE5);

}
