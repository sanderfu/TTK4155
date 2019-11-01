#include "uart.h"
#include "setup.h"
#include "timer.h"
#include "ADC.h"
#include "sleep.h"
#include "TWI_Master.h"

void setupInit(void){
	cli();
	USART_init(MYUBRR);
	printf("finished uart setup2)");
	CAN_controller_init();
	printf("finished can setup");
	pwm_init();
	printf("finished pwm");
	ADC_init();
	printf("Finished setup");
	timer_init();
	sleep_init();
	TWI_Master_Initialise();
	motor_init();
	encoder_init();
	sei();
}