/**
 * @file
 * @brief A library for using the timers on Node 2.
 */


#ifndef TIMER_H_
#define TIMER_H_


#include "setup.h"
#include <avr/interrupt.h>


#define PRESCALE 1024
#define TIMER1_SECONDS 0.025
#define TIMER1_RESET (F_CPU/PRESCALE)*TIMER1_SECONDS

#define TIMER3_SECONDS 0.05
#define TIMER3_RESET (F_CPU/PRESCALE)*TIMER3_SECONDS

/**
 * @brief Initialize timer
 */
void timer_init();

#endif /* !TIMER_HEADER */