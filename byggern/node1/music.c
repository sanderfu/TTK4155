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
/*

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


const uint32_t PROGMEM song1_chorus_melody[79] =
{ NOTE_AS4, NOTE_AS4, NOTE_GS4, 0, 
	NOTE_GS4,NOTE_F5, 0, NOTE_F5, 
	NOTE_DS5, NOTE_AS4, 0,NOTE_AS4,
    NOTE_GS4, 0, NOTE_GS4, NOTE_DS5, 0,
	
	NOTE_DS5, NOTE_CS5, NOTE_C5, NOTE_AS4,
	NOTE_CS5, 0, NOTE_CS5, 0, 
	 NOTE_CS5, 0, NOTE_CS5, 0, NOTE_CS5,
	  0, NOTE_DS5, NOTE_C5, NOTE_AS4,
	 
	 NOTE_GS4, 0, NOTE_GS4, 0, 
	 NOTE_GS4, NOTE_DS5, NOTE_CS5,NOTE_AS4,
	  0, NOTE_AS4, NOTE_GS4,NOTE_GS4,
	  NOTE_F5, 0, NOTE_F5, NOTE_DS5, 
	 
	 NOTE_AS4, 0, NOTE_AS4, NOTE_GS4, 
	 0, NOTE_GS4, 0,  NOTE_GS4, 
	 NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_AS4,
	 NOTE_CS5, 0, NOTE_CS5, 0,
	 
	 NOTE_CS5,  NOTE_CS5, 0, NOTE_CS5, NOTE_DS5,
	 NOTE_C5, NOTE_AS4, NOTE_GS4, 0, 
	 NOTE_GS4, NOTE_DS5, NOTE_CS5, 0
};

const char* lyrics_chorus[79] =
{ "Never ", "", "gonna ", "",
  "", "give ", "", "you ", "up\r\n",
  "Never ", "", "gonna ", "",
   "", "let ",  "",  "you ", "",
   
   "down", "\r\n", "", "Never ", "", 
  "gonna ", "", "", "", "run ", "", "", 
  "around ", "", "", 
   "", "", "and ", "", "desert ",  "","", "you", "\n\r",  
  
  "Never ", "", "gonna ", "",
   "make ", "", "you ", "cry", "\n\r",
   "Never ", "", "gonna ", "",
    "", "",  "say ",  "goodbye ", "", 
	
	"", "\r\n", "Never ", "", 
	"gonna ", "", "", "tell ", "", "",
	"a ", "lie ", "","",
   "and ","", "hurt ",  "you", "\r\n", ""
};

const uint8_t PROGMEM song1_chorus_rhythmn[79] =
{ 10, 10, 10, 1, 
	10,30,  1, 30,
	 60, 10,  1,10, 
	 10,  1, 10, 30, 0,
	 
	 30, 30, 10, 20,
	10, 1, 10, 1, 
	10, 1, 10, 1, 30, 
	1, 30, 30, 10,
	
	20, 1, 20,  1,
	 20, 40, 80,10, 
	 1, 10, 10, 10,
	 30,  1, 30, 60, 
	
	10,  1, 10, 10,
	 1, 10, 1,30,
	30, 30, 10, 20,
	10,  1, 10,  1,
	
	10, 10, 1, 30, 30,
	 30, 10, 20, 20,
	 20,40, 80, 40
};



void music_playLisaGikk() {
	cli();
	printf("playing Lisa Gikk til Skolen, not by Toto\n\n\r");
	for (int i = 0; i< sizeof(lisaMelody)/sizeof(uint32_t); i++) {
		printf("Playing frequency: %i", pgm_read_word(&(lisaMelody[i])));
		pwm_setFreq(pgm_read_word(&(lisaMelody[i])));
		uint32_t duration = 4*pgm_read_byte(&(lisaTempo[i]));
		while (duration--) {
			_delay_ms(1);
		}
	}
	pwm_setFreq(0);
	sei();

}
void music_playRick() {
	
	printf("You got rickrolled\n\n\r");
	for (int i = 0; i< sizeof(song1_chorus_melody)/sizeof(uint32_t); i++) {
		printf(lyrics_chorus[i]);
		pwm_setFreq(pgm_read_word(&(song1_chorus_melody[i])));
		uint32_t duration = 20*pgm_read_byte(&(song1_chorus_rhythmn[i]));
		while (duration--) {
			_delay_ms(1);
		}
	}
	pwm_setFreq(0);
	

}
*/