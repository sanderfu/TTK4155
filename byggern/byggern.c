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

int main(void)
{
	xmem_init();
	USART_init(MYUBRR);
	adcInit();
	//xmemWrite(0x51, 0x183E); //sram
	//xmemWrite(0x1400);
	SRAM_test();
	printf("Hello, world!\n\r");
	position_t pos;
	while (1) {
		
		//sram test
		_delay_ms(500);
		setPosition(&pos);
		printf("ADC: \n\r");
		printf("x: %i\t", pos.x_pos);
		printf("y: %i\n\r", pos.y_pos);
		
	}
}