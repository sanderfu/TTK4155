#include "uart.h"
#include "xmem.h"
#include "adc.h"
#include "joystick.h"
#include "setup.h"
#include "oled.h"
#include "timer.h"
#include "sleep.h"

	void setupInit(void){
	cli();
	xmem_init();
	USART_init(MYUBRR);
	adcInit();
	joystickInit();
	touchButton_init();
	oled_init();
	printf("After oledinit\n\r");
	timer_init();
	sleep_init();
	//menuInit();
	this_init();
	printf("Finished this");
	CAN_controller_init();
	//pwm_init(); uncommenting this breaks can on node 2.
	sei();
}