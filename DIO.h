/* 
 * File:   DIO.h
 * Author: Menna
 *
 * Created on June 28, 2025, 11:18 PM
 */

#ifndef DIO_H
#define	DIO_H

//define
#define PORTx_A  1
#define PORTx_B  2
#define PORTx_C  3
#define PORTx_D  4

#define OUTPUT   1
#define INPUT    0

#define PORT_OUTPUT 0xFF
#define PORT_INPUT  0x00

#define HIGH 1
#define LOW  0

//PORT DIRECTION?
void DIO_PORT_DIR(char PORTx, char PORT_DIR);
void DIO_PIN_DIR(char PORTx, char PINx, char PIN_DIR);

//OUTPUT, State?
void DIO_PORTx_SET(char PORTx, char PORT_DATA);
void DIO_PINx_SET(char PORTx, char PINx);
void DIO_PINx_RESET(char PORTx, char PINx);
void DIO_PINx_TOGGLE(char PORTx, char PINx);


//Input,Read
char DIO_PORTx_READ(char PORTx);
char DIO_PINx_READ(char PORTx, char PINx);


#endif	/* DIO_H */

