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
#include "oled.h"

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

volatile const char* lyrics_chorus[80] =
{ "Never ", "", "gonna ", "",
  "", "give ", "", "you ", "up.",
  "Never ", "", "gonna ", "",
   "", "let ",  "",  "you ", "",
   
   "down.", "", "", "Never ", "", 
  "gonna ", "", "", "", "run ", "", "", 
  "around ", "", "", 
   "", "", "and ", "", "desert ",  "","", "you.", "",  
  
  "Never ", "", "gonna ", "",
   "make ", "", "you ", "cry.", "",
   "Never ", "", "gonna ", "",
    "", "",  "say ",  "goodbye.", "", 
	
	"", "", "Never ", "", 
	"gonna ", "", "", "tell ", "", "",
	"a ", "lie ", "","",
   "and ","", "hurt ",  "you.", "", ""
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


void music_playRick() {
	cli();
	oled_home();
	oled_reset();
	uint8_t line = 0;
	for (int i = 0; i< sizeof(song1_chorus_melody)/sizeof(uint32_t); i++) {
		if (line== 0) {
			oled_reset();
		}
		//if not equal to ""
		if ((strcmp(lyrics_chorus[i], ""))) {
			oled_gotoLine(line);
			line++;
			oled_print(lyrics_chorus[i]);
		}
		if (lyrics_chorus[i][strlen(lyrics_chorus[i])-1] == '.') {
			
			line = 0;
		}
		
		
		//printf(lyrics_chorus[i]);
		pwm_setFreq(pgm_read_word(&(song1_chorus_melody[i])));
		uint32_t duration = 20*pgm_read_byte(&(song1_chorus_rhythmn[i]));
		while (duration--) {
			_delay_ms(1);
		}
	}
	pwm_setFreq(0);
	menu_init();

	sei();
	

}

void music_gameOver() {
	pwm_setFreq(NOTE_C5);
	_delay_ms(500);
	pwm_setFreq(NOTE_G4);
	_delay_ms(500);
	pwm_setFreq(NOTE_DS4);
	_delay_ms(500);
	pwm_setFreq(NOTE_C4);
	_delay_ms(500);
	pwm_setFreq(0);
	
}

void music_playNote(uint16_t note) {
	pwm_setFreq(note);
}