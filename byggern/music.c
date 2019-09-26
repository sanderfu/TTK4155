//Africa, by Toto
//
//Africa main theme melody

#include <avr/io.h>
#include "music.h"
#include "pwm.h"

uint32_t PROGMEM melody[] = {
  NOTE_A4, 0, 0, NOTE_A4,
  0, NOTE_A4, 0, 0,
  NOTE_A4, 0, 0, NOTE_A4,
  0, 0, NOTE_A4, 0
      
  0, NOTE_FS4, 0, 0,
  NOTE_GS5, 0, 0, NOTE_B5,
  0, NOTE_CS5, 0, 0, 
  NOTE_FS4, 0, 659, 0

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

  0, 493, 0, 277, 
  0, 1661, 0, 0

};

//Africa main them tempo
uint8_t PROGMEM tempo[] = {
    108, 120, 136, 115,
    128, 112, 124, 132, 
    115, 128, 128, 112,
    124, 4, 112, 124,
    
    4, 112, 124, 4, 
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
    128, 115, 128, 128
    115, 128, 128, 115, 
    128, 115, 128, 115,

};




void music_playAfrica() {
    cli(); 
   for (int i = 0; i< sizeof(melody)/sizeof(uint8_t); i++) {
       pwm_playFreq(pgm_read_byte(&(melody[i]));
       uint32_t duration = pgm_read_byte(&(tempo[i]));
       while (duration--) {
           _delay_ms(1);
       }
   }
   pwm_playFreq(0);
   sei();

}
