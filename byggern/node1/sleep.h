/*
 * sleep.h
 *
 * Created: 20.09.2019 15:15:51
 *  Author: torsteoe
 */ 


#ifndef SLEEP_H_
#define SLEEP_H_

//Initialize the sleep function with mode = SLEEP_MODE_IDLE 
void sleep_init();

//Put the MCU to sleep
void sleep_now();


#endif /* SLEEP_H_ */