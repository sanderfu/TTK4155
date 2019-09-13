#include "uart.h"
#include "xmem.h"
#include "adc.h"
#include "joystick.h"
#include "setup.h"

	void setupInit(void){
	xmem_init();
	USART_init(MYUBRR);
	adcInit();
	joystickInit();
}