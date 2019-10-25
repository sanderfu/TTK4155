#include "uart.h"
#include "setup.h"
#include "timer.h"
#include "IR.h"
	void setupInit(void){
	//cli();
	USART_init(MYUBRR);
	CAN_controller_init();
	pwm_init();
	IR_init();
	//sei();
}