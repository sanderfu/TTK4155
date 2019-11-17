#include "uart.h"
#include "setup.h"
#include "timer.h"
#include "ADC.h"
#include "sleep.h"
#include "TWI_Master.h"
#include "solenoid.h"
#define F_CPU 16000000
#include <util/delay.h>
void setupInit(void){
	cli();
	USART_init(MYUBRR);
	CAN_controller_init();
	pwm_init();
	ADC_init();
	timer_init();
	sleep_init();
	TWI_Master_Initialise();
	encoder_init();
	motor_init();
	solenoid_init();
	sei();
}