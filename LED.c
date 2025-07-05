#include <avr/io.h>
#include "DIO.h"
#include "LED.h"
#include "Timers.h"

//PIN_DIR output
void init_LEDs(){
    DIO_PIN_DIR(LED1_DIR, LED1, OUTPUT);
    DIO_PIN_DIR(LED2_DIR, LED2, OUTPUT);
    DIO_PIN_DIR(LED3_DIR, LED3, OUTPUT);
    DIO_PIN_DIR(LED4_DIR, LED4, OUTPUT);
    DIO_PIN_DIR(LED5_DIR, LED5, OUTPUT);

}
//set PIN
void LED_ON(char LED){
    switch(LED){
        case LED1:
            DIO_PINx_SET(LED1_DIR, LED1);
            break;
        case LED2:
            DIO_PINx_SET(LED2_DIR, LED2);
            break;
        case LED3:
            DIO_PINx_SET(LED3_DIR, LED3);
            break;
        case LED4:
            DIO_PINx_SET(LED4_DIR, LED4);
            break;
        case LED5:
            DIO_PINx_SET(LED5_DIR, LED5);
            break;    
        case ALL_LEDs:
            DIO_PINx_SET(LED1_DIR, LED1);
            DIO_PINx_SET(LED2_DIR, LED2);
            DIO_PINx_SET(LED3_DIR, LED3);
            DIO_PINx_SET(LED4_DIR, LED4);
            DIO_PINx_SET(LED5_DIR, LED5);
            break;
                  
    }
}
//reset PIN
void LED_OFF(char LED){
    switch(LED){
        case LED1:
            DIO_PINx_RESET(LED1_DIR, LED1);
            break;
        case LED2:
            DIO_PINx_RESET(LED2_DIR, LED2);
            break;
        case LED3:
            DIO_PINx_RESET(LED3_DIR, LED3);
            break;
        case LED4:
            DIO_PINx_RESET(LED4_DIR, LED4);
            break;
        case LED5:
            DIO_PINx_RESET(LED5_DIR, LED5);
            break;     
        case ALL_LEDs:
            DIO_PINx_RESET(LED1_DIR, LED1);
            DIO_PINx_RESET(LED2_DIR, LED2);
            DIO_PINx_RESET(LED3_DIR, LED3);
            DIO_PINx_RESET(LED4_DIR, LED4);
            DIO_PINx_RESET(LED5_DIR, LED5);
            break;
          
    }
}


void LED_TOGG(char LED){
    switch(LED){
        case LED1:
            DIO_PINx_TOGGLE(LED1_DIR, LED1);
            break;
        case LED2:
            DIO_PINx_TOGGLE(LED2_DIR, LED2);
            break;
        case LED3:
            DIO_PINx_TOGGLE(LED3_DIR, LED3);
            break;
        case LED4:
            DIO_PINx_TOGGLE(LED4_DIR, LED4);
            break;
        case LED5:
            DIO_PINx_TOGGLE(LED5_DIR, LED5);
            break;    
        case ALL_LEDs:
            DIO_PINx_TOGGLE(LED1_DIR, LED1);
            DIO_PINx_TOGGLE(LED2_DIR, LED2);
            DIO_PINx_TOGGLE(LED3_DIR, LED3);
            DIO_PINx_TOGGLE(LED4_DIR, LED4);
            DIO_PINx_TOGGLE(LED5_DIR, LED5);
            break;
}
}

void LED6_DimLevel(char level){
    if(level <= 255){
        Timer0_set_OCR0(level);
    }
}


void init_Dimming_LED(char CMP_MODE){
    
    DIO_PIN_DIR(LED6_DIR, LED6_Dim, OUTPUT);
    
    // Timer0 in Fast PWM mode
    //select prescaler 64= 976.56Hz
    init_timer0(TIMER_MODE_FPWM, TIMER_CLOCK_SELECT_PS_64); 
    

    //clear-set(high at first) OR set-clear (low at first)
    Timer0_set_CMP(CMP_MODE);
        
    // intensity=50%
    LED6_DimLevel(128); 
}

