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


	void setupInit(void){
	cli();
	xmem_init();
	USART_init(MYUBRR);
	adcInit();
	joystick_init();
	touchButton_init();
	oled_init();
	timer_init();
	sleep_init();
	menu_init();
	CAN_init();
	pwm_init();
	game_init();
	sei();
}