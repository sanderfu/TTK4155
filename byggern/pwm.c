
#define FOSC 4915200
#define F_CPU 4915200
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

#include <avr/io.h>
#include "notes.h"
typedef enum {
    PRESC_OFF =  ~( 1 << CS02 &  1 << CS01   &   1 << CS00) , 
    PRESC_1   =                                 (1 << CS00) ,
    PRESC_8   =                 (1 << CS01)                 ,
    PRESC_64  =                 (1 << CS01)  |  (1 << CS00) ,
    PRESC_256 =    (1 << CS02)                              , 
    PRESC_1024 =   (1 << CS02)  |               (1 << CS00)
} prescaling;

void pwm_init() {
    //set output pin
    DDRB = (1 << PB0); 


    //set ocr0 register as something
    OCR0 = 0xFF;
    
    //set foc0 in tcr0
    TCR0 = (1 << FOC0);

    //set tct mode
    TCR0 |= (1 << WGM01) ;
    
    //set toggle output mode
    TCR0 |= (1 << COM01); //and 0 << COM00;
    
    //set OC0 to clear on match
    TCR0 |= PRESC_1;

}

void pwm_setFreq(uint32_t freq) {
    if (freq == 0) {
        TCCR0 &= PRESC_OFF;
        return;
    }
    //first calculate for prescaling type 1
    enum prescaler = PRESC_1;
    uint32_t ocr_plus_one = F_CPU/(2*prescaler)/freq;

    if (ocr_plus_one > 255+1) {
        prescaler = PRESC_8;
        ocr_plus_one /= 8;

        if (ocr_plus_one > 255+1) {
            prescaler = PRESC_64;
            ocr_plus_one /= 8;
            
            if (ocr_plus_one > 255+1) {
                prescaler = PRESC_256;
                ocr_plus_one /= 4;
                    
                if (ocr_plus_one > 255+1) {
                    prescaler = PRESC_1024;
                    ocr_plus_one /= 4;
                }
            }
        }
    }

    //set prescaler bits to 0 first to reset
    TCCR0 &= PRESC_OFF; 
    //set correct prescaler    
    TCCR0 |= prescaler;
    
}
void pwm_testPlayNote() {
    pwm_setFreq(NOTE_A4);
}
