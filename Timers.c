#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "Timers.h"
#include "DIO.h"

void init_timer0(char TIMER_MODE, char TIMER_CLOCK_SELECT){
    //reset bits
    TCCR0 &= ~((1 << WGM01)|(1 << WGM00));
    
    //select timer mode
    switch (TIMER_MODE){
        case TIMER_MODE_NORMAL:
            TCCR0 &= ~((1 << WGM01)|(1 << WGM00)); //0,0
            TIMSK |= (1 << TOIE0); //Overflow Interrupt Enable
            break;
        case TIMER_MODE_PWM:
            TCCR0 |= (1 << WGM00); //0,1
            break;
        case TIMER_MODE_CTC:
            TCCR0 |= (1 << WGM01); //1,0
            TIMSK |= (1<<OCIE0); //output compare value 
            Timer0_set_OCR0(255); //customized value
            break;
        case TIMER_MODE_FPWM:
            TCCR0 |= ((1 << WGM01)|(1 << WGM00));
            break;
                      
    }
    
    TCCR0 &= ~((1<<CS02)|(1<<CS01)|(1<<CS00)); //reset (No clock source)  
    TCCR0 |= TIMER_CLOCK_SELECT; //prescaler
    
}

void Timer0_set_OCR0(char val){
    OCR0 = val;
   
}
//CTC /PWM mode
void Timer0_set_CMP(char CMP_MODE){
    // Set Direction of PIN OC0
    DIO_PIN_DIR(PORTx_B, PB3, OUTPUT);
    // Set Mode .. 
    TCCR0 &= ~((1<<COM01)|(1<<COM00));
    TCCR0 |= (CMP_MODE << COM00);
}
