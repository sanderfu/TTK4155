







#include "timer.h"

/*

ISR (TIMER1_COMPB_vect) {
	cli();
	TCNT1 = 0x00;

	sei();
}
*/


void timer_init() {

	
	
	
	TIMSK3 |= (1 << OCIE3B);

	
	//This register contains counter value
	TCNT3 = 0x00;
	
	//set up compare output mode & clock select (prescaling)
	TCCR3A = (1 << COM3B0 | 1 << COM3B1);
	TCCR3B = (1 << CS12 | 1 << CS00);
	
	//Output compare register containing value compared to counter
	OCR3B = TIMER3_RESET;
	

}

