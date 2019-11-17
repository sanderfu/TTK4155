#ifndef XMEM_H_
#define XMEM_H_

//Initialize XMEM
void xmem_init(void);

//Write to XMEM
void xmemWrite(uint8_t data, uint16_t addr);

//Read from XMEM
uint8_t xmemRead(uint16_t addr);

#endif