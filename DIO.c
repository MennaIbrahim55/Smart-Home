
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "DIO.h"

//PORT DIRECTION?
void DIO_PORT_DIR(char PORTx, char PORT_DIR){
    switch(PORTx){
        case PORTx_A:
            DDRA = PORT_DIR;
            break;
        case PORTx_B:
            DDRB = PORT_DIR;
            break;
        case PORTx_C:
            DDRC = PORT_DIR;
            break;
        case PORTx_D:
            DDRD = PORT_DIR;
            break;            
    }
    _delay_ms(100);
}

void DIO_PIN_DIR(char PORTx, char PINx, char PIN_DIR){
    switch (PORTx){
        case PORTx_A:
            if (PIN_DIR){
                DDRA |= (1 << PINx); //OR 
            } else{
                DDRA &= ~(1 << PINx); //AND
            }
            break;
        case PORTx_B:
            if (PIN_DIR){
                DDRB |= (1 << PINx);
            } else{
                DDRB &= ~(1 << PINx);
            }
            break;
        case PORTx_C:
            if (PIN_DIR){
                DDRC |= (1 << PINx);
            } else{
                DDRC &= ~(1 << PINx);
            }
            break;
        case PORTx_D:
            if (PIN_DIR){
                DDRD |= (1 << PINx);
            } else{
                DDRD &= ~(1 << PINx);
            }
            break;
    }
    _delay_ms(100);
}

//OUTPUT, State?
void DIO_PORTx_SET(char PORTx, char PORT_DATA){
    switch (PORTx){
        case PORTx_A:
            PORTA = PORT_DATA;
            break;
        case PORTx_B:
            PORTB = PORT_DATA;
            break;
        case PORTx_C:    
            PORTC = PORT_DATA;
            break;
        case PORTx_D:
            PORTD = PORT_DATA;
            break;
    }
}
void DIO_PINx_SET(char PORTx, char PINx){
    switch (PORTx){
        case PORTx_A:
            PORTA |= (1 << PINx);
            break;
        case PORTx_B:
            PORTB |= (1 << PINx);
            break;
        case PORTx_C:
            PORTC |= (1 << PINx);
            break;
        case PORTx_D:
            PORTD |= (1 << PINx);
            break;    
    }
}

void DIO_PINx_RESET(char PORTx, char PINx){
    switch (PORTx){
        case PORTx_A:
            PORTA &= ~(1 << PINx);
            break;
        case PORTx_B:
            PORTB &= ~(1 << PINx);
            break;
        case PORTx_C:
            PORTC &= ~(1 << PINx);
            break;
        case PORTx_D:
            PORTD &= ~(1 << PINx);
            break;    
    }
}
    
void DIO_PINx_TOGGLE(char PORTx, char PINx){
    switch (PORTx){
        case PORTx_A:
            PORTA ^= (1 << PINx); //XOR
            break;
        case PORTx_B:
            PORTB ^= (1 << PINx);
            break;  
        case PORTx_C:
            PORTC ^= (1 << PINx);
            break;
        case PORTx_D:
            PORTD ^= (1 << PINx);
            break;    
    }
}


//Input,Read
char DIO_PORTx_READ(char PORTx){
     switch (PORTx) {
        case PORTx_A:
            return PINA;
        case PORTx_B:
            return PINB;
        case PORTx_C:
            return PINC;
        case PORTx_D:
            return PIND;

        default:
            return 0;

    }
}
char DIO_PINx_READ(char PORTx, char PINx){
    switch (PORTx) {
        case PORTx_A:
            return (PINA & (1 << PINx));
        case PORTx_B:
            return (PINB & (1 << PINx));
        case PORTx_C:
            return (PINC & (1 << PINx));
        case PORTx_D:
            return (PIND & (1 << PINx)); 
        
        default:
            return 0;    
    }}
