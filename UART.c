#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "UART.h"
#include "stdlib.h"



void init_UART(int baudrate) {
    // Calculate UBRR value from formula: UBRR = (F_CPU / (16 * baudrate)) - 1
    short UBRR = F_CPU / (16.0 * baudrate) - 1;

   
    UBRRL = (char) UBRR;           // Load lower 8 bits
    UBRRH = (char)(UBRR >> 8);     // Load upper 8 bits

    // Enable Transmitter and Receiver
    UCSRB |= (1 << RXEN) | (1 << TXEN); 
    
    // 1 -> URSEL to writing the UCSRC
    // 1 -> UCSZ1 & UCSZ0 to 8 bit
    UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0); 
}


//RX Complete Interrupt Enable
void UART_RXCIE(){   
     
    UCSRB |= (1<<RXCIE);
}

//TX Complete Interrupt Enable
void UART_TXCIE(){
     
    UCSRB |= (1<<TXCIE);
}

void UART_transmit(char data){
    //Wait for empty transmit buffer 
     while ( !( UCSRA & (1<<UDRE)) );
     
    //Put data into buffer, sends the data 
    UDR = data;
}

char UART_receive(){
    // Wait for data to be received 
     while ( !(UCSRA & (1<<RXC)) );
     
    //Get and return received data from buffer 
    return UDR;  
}


void UART_send_str(char * str){
    
    for (int i=0 ; str[i] != '\0'; i++){
        UART_transmit(str[i]);
    }
}


void UART_send_num(int num){
    char str[12];
    itoa(num, str , 10); //Integer To ASCII
    UART_send_str(str);
}