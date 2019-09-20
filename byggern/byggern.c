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


joystick_position_t joystick_pos;
slider_position_t slider_pos;
buttonValues_t buttons;



ISR (TIMER1_COMPB_vect) {
	cli();
	TCNT1 = 0x00;
	joystick_readPosition(&joystick_pos);
	slider_readPosition(&slider_pos);
	touchButton_readButtons(&buttons);
	sei();
}

ISR (TIMER0_COMP_vect) {
	cli();
	TCNT1 = 0x00;
	navigateMenu(&joystick_pos);
	menu_printCurrentMenu();
	sei();
}

int main(void)
{
	setupInit();
	test_SRAM();
	printf("Hello, world!\n\r");
	MenuNode* gameMenu = menuInit();
	menu_printCurrentMenu();
	
	
	oled_home();
	oled_gotoLine(2);
	
	
	
	while (1) {
		//disable analog 
		sleep_now();
		                  
		//sleep_disable();         
		//clear terminal
		printf("hei");
		//
		
		/*
		if (!strcmp(currentMenu.currentMenuItem->name,"Highscore")) {
			oled_reset();
			oled_home();
			for (int i = 0; i< 8; i++) {
				for (int col = 0; col<128; col++) {
					oled_pos(i, col);
					oled_print_arrow();
				}
				
			}
			_delay_ms(1000);
			free(currentMenu.currentMenuItem);
			currentMenu.currentMenuItem = menuInit();
			
		} else {
			
		}
		*/

		test_outputControllers(joystick_pos, slider_pos, buttons);		
		//_delay_ms(50);	
	}
}