//Africa, by Toto
//
//Africa main theme melody
#define F_CPU 4915200

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>

#include "music.h"
#include "pwm.h"
#include "notes.h"

const uint32_t PROGMEM melody[80] = {
  NOTE_A4, 0, 0, NOTE_A4,
  0, NOTE_A4, 0, 0,
  NOTE_A4, 0, 0, NOTE_A4,
  0, 0, NOTE_A4, 0,
      
  0, NOTE_FS4, 0, 0,
  NOTE_GS5, 0, 0, NOTE_B5,
  0, NOTE_CS5, 0, 0, 
  NOTE_FS4, 0, 659, 0,

  1108, 0, 987, 0, 
  1108, 0, 739, 0, 
  1318, 0, 1108, 0, 
  987, 0, 554, 0, 
  
  369, 0, 329, 0, 
  277, 0, 493, 0, 
  1108, 0, 1479, 0, 
  1318, 0, 0, 1318,

  0, 1108, 0, 1244, 
  0, 659, 0, 0, 
  1318, 0, 0, 1318, 
  0, 659, 0, 415,

  //0, 493, 0, 277, 
  //0, 1661, 0, 0

};

//Africa main them tempo
const uint8_t PROGMEM tempo[82] = {
    108, 120, 136, 115,
    128, 112, 124, 132, 
    115, 128, 128, 112,
    124, 4, 112, 124,
    
    4, 500, 124, 4, 
    112, 124, 4, 115, 
    128, 112, 124, 132, 
    115, 128, 115, 128, 

    115, 128, 115, 128, 
    115, 128, 115, 128, 
    115, 128, 115, 128, 
    115, 128, 115, 128,

    115, 128, 115, 128, 
    115, 128, 115, 128, 
    115, 128, 115, 128, 
    115, 128, 128, 115, 

    128, 115, 128, 115, 
    128, 115, 128, 128,
    115, 128, 128, 115, 
    128, 115, 128, 115,

};


const uint32_t PROGMEM lisaMelody[33] = {
	NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, 
	NOTE_G5, 0, NOTE_G5, NOTE_A5, 
	0, NOTE_A5, 0, NOTE_A5, 
	0, NOTE_A5, NOTE_G5, NOTE_F5,
	
	0, NOTE_F5, 0,  NOTE_F5, 
	0,  NOTE_F5, NOTE_E5, 0, 
	NOTE_E5, NOTE_D5, 0, NOTE_D5,
	0,  NOTE_D5, 0, NOTE_D5, 
	
	NOTE_C5

};

//Africa main them tempo
const uint8_t PROGMEM lisaTempo[33] = {
	100, 100, 100, 100,
	200, 10, 200, 100, 
	5,100, 5, 100, 
	5, 100, 200, 100,
	 
	5, 100, 5, 100, 
	5, 100, 200, 5, 
	200, 100, 5, 100,
	5, 100, 5, 100, 
	
	200

};

void music_playAfrica() {
    cli(); 
	printf("playing Africa, by Toto\n\n\r");
   for (int i = 0; i< sizeof(melody)/sizeof(uint32_t); i++) {
	   printf("Playing note or silence: %i", i);
       pwm_setFreq(pgm_read_byte(&(melody[i])));
       uint32_t duration = 3*pgm_read_byte(&(tempo[i]));
       while (duration--) {
           _delay_ms(1);
       }
   }
   pwm_setFreq(0);
   sei();

}
void music_playLisaGikk() {
	cli();
	printf("playing Lisa Gikk til Skolen, not by Toto\n\n\r");
	for (int i = 0; i< sizeof(lisaMelody)/sizeof(uint32_t); i++) {
		printf("Playing note or silence: %i", i);
		pwm_setFreq(pgm_read_byte(&(lisaMelody[i])));
		uint32_t duration = 4*pgm_read_byte(&(lisaTempo[i]));
		while (duration--) {
			_delay_ms(1);
		}
	}
	pwm_setFreq(0);
	sei();

}