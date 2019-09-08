#define BASE_ADDRESS 0x1000;
#include <avr/io.h>
#include "xmem.h"

void xmem_init(void) {
	MCUCR |= (1<<SRE);
	SFIOR |= (1<<XMM0);
}

void xmemWrite(uint8_t data, uint16_t addr) {
	volatile char *ext_mem = (char *) BASE_ADDRESS;
	ext_mem[addr] = data;
}
void xmemRead(uint16_t addr) {
	volatile char * ext_mem = (char *) BASE_ADDRESS;
	uint8_t ret_val = ext_mem[addr];
	return ret_val;
}
	