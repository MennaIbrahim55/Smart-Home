#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "ADC.h"

void init_ADC(char ADC_CH, char ADC_FREQ, char ADC_REF){
    ADC_select_CH(ADC_CH);
    ADC_select_FREQ(ADC_FREQ);
    ADC_select_REF(ADC_REF);
    ADC_enable();
}

void ADC_enable(){
     ADCSRA |= (1 << ADEN);
}

void ADC_disable(){
    ADCSRA &= ~(1 << ADEN);
}

void ADC_select_CH(char ADC_CH){
    //clear the selection bits
    ADMUX &= ~((1<<MUX4)|(1<<MUX3)|(1<<MUX2)|(1<<MUX1)|(1 << MUX0));
    /*OR
     *ADMUX &= 0xE0; // 11100000
     */
    
    //select channel
    ADMUX |= ADC_CH;
}

void ADC_select_FREQ(char ADC_FREQ){
     //clear ADC Prescaler Select Bits
    ADCSRA &= ~((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));
    /*OR
     * ADCSRA &= 0xF8; // 11111000
     */
    
    //set
    ADCSRA |= ADC_FREQ;
}

void ADC_select_REF(char ADC_REF){
    //clear
    ADMUX &= ~((1<<REFS1)|(1<<REFS0));
    /*OR
     *ADMUX &= 0x3F; // 00111111
     */
    
    //shift the value to reach 6&7 bits
    ADMUX |= (ADC_REF << 6);
   
}

void ADC_SC(){
    //ADC Start Conversion
    ADCSRA |= (1<<ADSC);
}

void ADC_wait(){
    //ADIF: ADC Interrupt Flag
   while(!(ADCSRA & (1<<ADIF)));
   
}

void ADC_INT_enable(){
    ADCSRA |= (1<<ADIE);
}

int ADC_read_mV(){
    
    ADCSRA |= (1 << ADSC); // Start conversion
    while (!(ADCSRA & (1 << ADIF))); // Wait
    //ADCW-> ADCL & ADCH
    return (ADCW * ADC_step); // Return mV
}




