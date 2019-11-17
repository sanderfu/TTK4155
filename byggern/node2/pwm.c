/*
 * pwm.c
 *
 * Created: 18.10.2019 08:51:20
 *  Author: torsteoe
 */ 
#include "pwm.h"
#include "setup.h"
#include <avr/interrupt.h>
typedef enum {
	PRESC_OFF =   ~(1 << CS12 | 1 << CS11   |   1 << CS10) ,
	PRESC_1   =                                 (1 << CS10) ,
	PRESC_8   =                 (1 << CS11)                 ,
	PRESC_64  =                 (1 << CS11)  |  (1 << CS10) ,
	PRESC_256 =    (1 << CS12)                              ,
	PRESC_1024 =   (1 << CS12)  |               (1 << CS10)
} prescaling;

#define PERIOD_MS					20
#define PWM_PRESCALER				8
#define ICR_PERIOD					(F_CPU*PERIOD_MS)/PWM_PRESCALER/1000

void pwm_init() {
	//set output pin
	DDRB |= (1 << PB5);
	
	//Reset prescaler, then set to 8.
	TCCR1B &= PRESC_OFF;
	TCCR1B |= PRESC_8;
	
	//Timer incremented until counter value matches value in OCR1A
	TCCR1A |= (1 << WGM11 & ~(1 <<WGM10));
	TCCR1B |= ((1 << WGM13) | (1 << WGM12));
	
	//Set compare output mode on channel A
	TCCR1A |= ((1 << COM1A1) & ~(1 << COM1A0));
	
	
	
	//set period to 20ms
	ICR1 = ICR_PERIOD;
	

	//Set initial pulsewidth
	OCR1A = ICR_PERIOD/(20)*(2.1+0.9)/2;
}

void pwm_setPulseWidth(float width_ms) {
	
	
	if (width_ms >= 0.9 && width_ms <=2.1) {
		
		
		float dutyCycle = width_ms/PERIOD_MS;
		uint32_t pulse = dutyCycle*(ICR_PERIOD);
		
		OCR1A = pulse;
		
	}
	
	
}