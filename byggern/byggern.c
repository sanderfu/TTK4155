/*
 * byggern.c
 *
 * Created: 30.08.2019 15:12:42
 *  Author: torsteoe
 */ 


#include "setup.h"

#include <stdlib.h>
#include <util/delay.h>
#include "uart.h"
#include "xmem.h"
#include "adc.h"
#include "joystick.h"
#include "slider.h"
#include "touchButton.h"
#include "oled.h"
#include "avr/interrupt.h"
#include "menu.h"
#include "timer.h"
#include "test.h"
#include "SPI.h"
#include "pwm.h"

int main(void)
{
	setupInit();
	test_SRAM();
	pwm_testPlayNote();
	pwm_init();
	while (1) {
		//Put microcontroller to sleep until next interrupt. 
		//sleep_now();
		                         
		
		
		//test_resetMenu();
		//test_outputControllers(joystick_pos, slider_pos, buttons);		
		//_delay_ms(50);	
	}
}