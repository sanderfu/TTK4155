#define PRESCALE 1024
#define F_CPU 4915200
#define TIMER1_SECONDS 0.1
#define TIMER1_RESET (F_CPU/PRESCALE)*TIMER1_SECONDS

#define TIMER0_SECONDS 0.2
#define TIMER0_RESET (F_CPU/PRESCALE)*TIMER0_SECONDS
#include "timer.h"
#include "joystick.h"
#include "slider.h"
#include "touchButton.h"
#include "menu.h"
#include "game.h"
#include <avr/interrupt.h>


ISR (TIMER1_COMPB_vect) {
	cli();
	TCNT1 = 0x00;
	joystick_readPosition(&joystick_pos);
	slider_readPosition(&slider_pos);
	touchButton_readButtons(&buttons);
	if(gameActive==0){
		navigateMenu(&joystick_pos);
		menu_printCurrentMenu();
	}
	else{
		//game_updateOled();
	}
	sei();
}

void timer_init() {

	
	//////////////////////////TIMER 1 (16 bit)//////////////////////////////////
	
	//Enable "compare output match" interrupt
	TIMSK |= (1 << OCIE1B);

	
	//This register cointains counter value
	TCNT1 = 0x00;
	
	//set up compare output mode & clock select (prescaling)
	TCCR1A = (1 << COM1B0 | 1 << COM1B1);
	TCCR1B = (1 << CS12 | 1 << CS00);
	
	//Output compare register containing value compared to counter
	OCR1B = TIMER1_RESET;
}