/*
 * test.c
 *
 * Created: 20.09.2019 14:29:16
 *  Author: torsteoe
 */ 

#include "setup.h"
#include "test.h"
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>


#include <util/delay.h>
#include <avr/interrupt.h>
#include "menu.h"

void test_SRAM(void)
{
	volatile char *ext_ram = (char *) 0x1800; // Start address for the SRAM
	uint16_t ext_ram_size = 0x800;
	uint16_t write_errors = 0;
	uint16_t retrieval_errors = 0;
	printf("Starting SRAM test...\n\r");
	// rand() stores some internal state, so calling this function in a loop will
	// yield different seeds each time (unless srand() is called before this function)
	uint16_t seed = rand();
	// Write phase: Immediately check that the correct value was stored
	srand(seed);
	for (uint16_t i = 0; i < ext_ram_size; i++) {
		uint8_t some_value = rand();
		ext_ram[i] = some_value;
		uint8_t retreived_value = ext_ram[i];
		if (retreived_value != some_value) {
			printf("Write phase error: ext_ram[%4d] = %02X (should be %02X)\n\r", i, retreived_value, some_value);
			write_errors++;
		}
	}
	// Retrieval phase: Check that no values were changed during or after the write phase
	srand(seed); // reset the PRNG to the state it had before the write phase
	for (uint16_t i = 0; i < ext_ram_size; i++) {
		uint8_t some_value = rand();
		uint8_t retreived_value = ext_ram[i];
		if (retreived_value != some_value) {
			printf("Retrieval phase error: ext_ram[%4d] = %02X (should be %02X)\n\r",
			i, retreived_value, some_value);
			retrieval_errors++;
		}
	}
	printf("SRAM test completed with \n\r%4d errors in write phase and \n\r%4d errors in retrieval phase\n\r", write_errors, retrieval_errors);
}

void test_outputControllers(joystick_position_t joystick_pos, slider_position_t slider_pos, buttonValues_t buttons) {
	
	//clear terminal
	printf("\033\143");
		
	printf("x: %i y: %i\n\rSl L: %i SL R: %i\n\rB L: %i B R: %i\n\rAngle: %i\n", joystick_pos.x_pos, joystick_pos.y_pos, slider_pos.left_pos, slider_pos.right_pos,  buttons.left_button, buttons.right_button, joystick_pos.angle);

	
}


void test_resetMenu(void) {
	/*
	cli();

		if (!strcmp(currentMenu.currentMenuItem->name,"Highscore")) {
			
			oled_reset();
			oled_home();
			for (int i = 0; i< 8; i++) {
				for (int col = 0; col<128; col++) {
					oled_pos(i, col);
					oled_print_arrow();
				}
				
			}
			
			
			free(currentMenu.currentMenuItem);
			currentMenu.currentMenuItem = menuInit();
			_delay_ms(500);
			
			
		}
	sei();
	*/
		
}