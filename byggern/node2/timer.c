







#include "timer.h"

/*

ISR (TIMER1_COMPB_vect) {
	cli();
	TCNT1 = 0x00;

	sei();
}
*/


void timer_init() {

	
	//////////////////////////TIMER 1 (16 bit)//////////////////////////////////
	/*
	
	*/
	
	////////////////////////TIMER 0////////////////////////////////////
	/*
	TIMSK3 |= (1 << OCIE3A);
	TCNT3 = 0x0; 
	
	//set oc0a on compare match
	TCCR3A |= (1 << COM3A1 | 1 << COM3A0);
	
	//Set prescaler
	TCCR3B |= (1 << CS02 | 1 << CS00);
	TCCR3B &= ~(1 << CS01);
	
	//Set value to be compared
	//OCR3A = TIMER3_RESET;
	uint16_t val = TIMER3_RESET;
	OCR3AH = val >> 8;
	OCR3AL = val;
	
	*/
	//Enable "compare output match" interrupt
	
	TIMSK3 |= (1 << OCIE3B);

	
	//This register contains counter value
	TCNT3 = 0x00;
	
	//set up compare output mode & clock select (prescaling)
	TCCR3A = (1 << COM3B0 | 1 << COM3B1);
	TCCR3B = (1 << CS12 | 1 << CS00);
	
	//Output compare register containing value compared to counter
	OCR3B = TIMER3_RESET;
	
	//Enable global interrupts

	//printf("Timer initialized");
}

