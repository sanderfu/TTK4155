#ifndef XMEM_H_
#define XMEM_H_
void xmem_init(void);
void xmemWrite(uint8_t data, uint16_t addr);
uint8_t xmemRead(uint16_t addr);

#endif