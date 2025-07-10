/*
 * File:   main.c
 * Author: Menna
 *
 * Created on June 29, 2025, 10:28 PM
 */
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

#include "DIO.h"
#include "LED.h"
#include "Timers.h"


int main() {
    
    init_LEDs();
    
    
    init_Dimming_LED(CMP_MODE_PWM_CLEAR_SET);
    
    while(1){
        
        LED_TOGG(ALL_LEDs);
    
    }
    return;
}
