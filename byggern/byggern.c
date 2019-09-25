/*
 * byggern.c
 *
 * Created: 30.08.2019 15:12:42
 *  Author: torsteoe
 */ 
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>


#include <avr/interrupt.h>
#include "menu.h"

#include "setup.h"

#include <stdlib.h>
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
#include "CAN.h"
#include "MCP2515.h"

int main(void)
//p.23 for can read instructions
{
	setupInit();
	test_SRAM();
	
	CAN_write(0x31, 5);
	SPI_setChipSelect(PB4, 0);
	SPI_masterWrite(MCP_RTS_TX0);
	SPI_setChipSelect(PB4, 1);

	uint8_t i = CAN_read(0x61);
	
	printf("This is my integer: %i",i);

	while (1) {
		//Put microcontroller to sleep until next interrupt. 
		//sleep_now();
		                         
		
		
		//test_resetMenu();
		//test_outputControllers(joystick_pos, slider_pos, buttons);		
		//_delay_ms(50);	
	}
}