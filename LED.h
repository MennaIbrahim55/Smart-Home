/* 
 * File:   LED.h
 * Author: Menna
 *
 * Created on June 30, 2025, 10:48 PM
 */

#ifndef LED_H
#define	LED_H

#define LED1     PB3
#define LED1_DIR PORTx_B

#define LED2       PC2
#define LED2_DIR   PORTx_C

#define LED3  PC7
#define LED3_DIR  PORTx_C

#define LED4 PD6
#define LED4_DIR PORTx_D

#define LED5 PC1
#define LED5_DIR PORTx_C

#define LED6_Dim PC3
#define LED6_DIR  PORTx_C

#define ALL_LEDs 9


void init_LEDs();
void LED_ON(char LED);
void LED_OFF(char LED);
void LED_TOGG(char LED);
void init_Dimming_LED(char CMP_MODE);
void LED6_DimLevel(char level);


#endif	/* LED_H */

