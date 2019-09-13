#define FOSC 4915200
#define F_CPU 4915200
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

#define test_bit(reg, bit) (reg & (1<<bit))

void setupInit(void);