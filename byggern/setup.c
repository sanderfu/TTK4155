#include "uart.h"
#include "xmem.h"
#include "adc.h"
#include "joystick.h"
#include "setup.h"
#include "oled.h"
#include "timer.h"
#include "sleep.h"
#include "CAN_controller.h"

	uint8_t setupInit(void){
		cli();
	xmem_init();
	USART_init(MYUBRR);
	adcInit();
	joystickInit();
	touchButton_init();
	oled_init();
	timer_init();
	sleep_init();
	//menuInit();
	
	if (!CAN_controller_init()) {
		return 0;
	}
		sei();
	return 1;
}