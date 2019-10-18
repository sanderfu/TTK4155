#include "uart.h"
#include "setup.h"
#include "timer.h"

	void setupInit(void){
	//cli();
	USART_init(MYUBRR);
	CAN_controller_init();
	pwm_init();
	//sei();
}