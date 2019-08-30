/*
 * byggern.c
 *
 * Created: 30.08.2019 15:12:42
 *  Author: torsteoe
 */ 
#define FOSC 4915200
#define F_CPU 4915200
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1



#include <util/delay.h>
#include "uart.h"

int main(void)
{
	USART_init(MYUBRR);
    while(1)
    {
		printf("hello");
		_delay_ms(50);
        //TODO:: Please write your application code 
    }
}