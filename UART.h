/* 
 * File:   UART.h
 * Author: Menna
 *
 * Created on July 5, 2025, 5:41 PM
 */

#ifndef UART_H
#define	UART_H

#define baudrate_2400 2400
#define baudrate_4800 4800
#define baudrate_9600 9600

void init_UART(int baudrate);
void UART_RXCIE(); //RX Complete Interrupt Enable
void UART_TXCIE(); //TX Complete Interrupt Enable
void UART_transmit(char data);
char UART_receive();
void UART_send_str(char * str);
void UART_send_num(int num);

#endif	/* UART_H */

