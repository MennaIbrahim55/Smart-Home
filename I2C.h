/* 
 * File:   I2C.h
 * Author: Menna
 *
 * Created on July 11, 2025, 1:06 AM
 */

#ifndef I2C_H
#define	I2C_H

void init_I2C(char SLAVE_ADDRESS);
char I2C_MT(char SLA_W, char data);   //Master Transmit
char I2C_MR(char SLA_R);    //Master Receive
char I2C_ST(char data); //Slave Transmit
char I2C_SR();   //Slave receive


char I2C_STA_COND();   //Start Condition
char I2C_CALL_DEVICE(char SLA); 
char I2C_SEND_DATA(char data);
void I2C_STO_COND();  //Stop Condition






#endif	/* I2C_H */

