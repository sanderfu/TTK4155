#include "setup.h"
#include "uart.h"
#include "xmem.h"
#include "adc.h"
#include "joystick.h"
#include "oled.h"
#include "timer.h"
#include "sleep.h"
#include "game.h"
#include "CAN.h"
#include "touchButton.h"
#include "menu.h"
#include "pwm.h"

#define FOSC 4915200
#define F_CPU 4915200
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1
#include <util/delay.h>


	void setupInit(void){
	cli();
	xmem_init();
	_delay_ms(100);
	USART_init(MYUBRR);
	_delay_ms(100);
	CAN_init();
	_delay_ms(100);
	adcInit();
	_delay_ms(100);
	joystick_init();
	_delay_ms(100);
	touchButton_init();
	_delay_ms(100);
	oled_init();
	_delay_ms(100);
	timer_init();
	_delay_ms(100);
	sleep_init();
	_delay_ms(100);
	menu_init();
	_delay_ms(100);
	pwm_init();
	_delay_ms(100);
	game_init();
	_delay_ms(100);
	sei();
}