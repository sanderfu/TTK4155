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


#define PRESCALE 1024
#define SECONDS 0.05
#define TIMER_RESET (F_CPU/PRESCALE)*SECONDS

joystick_position_t joystick_pos;
slider_position_t slider_pos;
buttonValues_t buttons;

void SRAM_test(void)
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

ISR (TIMER1_COMPB_vect) {
	cli();
	TCNT1 = 0x00;
	joystick_readPosition(&joystick_pos);
	slider_readPosition(&slider_pos);
	touchButton_readButtons(&buttons);
	sei();
}
void timer_init() {
	
}
int main(void)
{
	//DDRB &= ~(1 << BUTTON_LEFT | 1 << BUTTON_RIGHT);
	setupInit();
	//SRAM_test();
	printf("Hello, world!\n\r");
	MenuNode* gameMenu = menuInit();
	oled_gotoLine(6);
	
	oled_print((gameMenu->name));
	oled_gotoLine(7);
	
	oled_print((gameMenu->children[0]->name));
	
	oled_print_arrow();
	
	
	//oled_print(gameMenu->name);
	
	//Enable interrupt from timer
	
	//Disable global interrupts
	cli();
	
	//enable timer 0
	TIMSK |= (1 << OCIE1B);

	
	//Setup code here for timer interrupt
	TCNT1 = 0x00;
	TCCR1A = (1 << COM1B0 | 1 << COM1B1);
	TCCR1B = (1 << CS12 | 1 << CS00);
	
	OCR1B = TIMER_RESET;
	
	//Enable global interrupts
	sei();
	//printf("Timer initialized");
	
	oled_home();
	oled_gotoLine(2);
	
	//oled_print("hei paa deg");
	while (1) {
		//_delay_ms(500);
		
		//cli();
		//TCNT1 = 0x4444;
		//printf("Timer: %i\n\r", TCNT1);
		//sei();
		
		//clear terminal
		//printf("\033\143");
		
		//printf("ADC: \n\r");
		//printf("x: %i\t", joystick_pos.x_pos);
		//printf("", joystick_pos.y_pos);
		//joystick_printDirection(joystick_getDirection(&joystick_pos));
		//printf("Slider left: %i\tSlider right: %i\n\r", slider_pos.left_pos, slider_pos.right_pos);
		//printf("Button left: %i \tButton right: %i\n\r", buttons.left_button, buttons.right_button);
		//printf("Angle: %i\n\r", joystick_pos.angle);
		//oled_print_arrow(0x6, 0x6);

		//printf("x: %i y: %i\n\rSl L: %i SL R: %i\n\rB L: %i B R: %i\n\rAngle: %i\n", joystick_pos.x_pos, joystick_pos.y_pos, slider_pos.left_pos, slider_pos.right_pos,  buttons.left_button, buttons.right_button, joystick_pos.angle);
		_delay_ms(100);	
	}
}