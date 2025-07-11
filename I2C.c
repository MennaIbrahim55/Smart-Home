#include <avr/io.h>
#include "I2C.h"


void init_I2C(char SLAVE_ADDRESS){
    
    TWBR = 18; //TWI Bit Rate Register
    TWAR = (SLAVE_ADDRESS<<1);
}


char I2C_MT(char SLA_W, char data){
    char status = 0;
    
    //start condition
    TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
    while (!(TWCR & (1<<TWINT)));
    status = (TWSR & 0xF8); // 11111000
    if (status != 0x08) { 
        return 1; 
    }
    
    //send SLA write address
    TWDR = SLA_W; 
    TWCR = (1<<TWINT) | (1<<TWEN);
    while (!(TWCR & (1<<TWINT)));
    status = (TWSR & 0xF8); // 11111000
    /*
     * 0x18 -> slave write + Ack
     * 0x20 -> slave write + noAck
     */
    if (status != 0x18 && status != 0x20 ) {
        return 2; 
    }
    
    //send data
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    status = (TWSR & 0xF8); // 11111000
    /*
     * 0x28 -> date transmitted + Ack
     * 0x30 -> data transmitted + noAck
     */
    if (status != 0x28 && status != 0x30) {
        return 3;
}
    //send stop condition
    TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
    
    return 0;
}

char I2C_MR(char SLA_R){
     char status = 0;
     
    //start condition
    TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
    while (!(TWCR & (1<<TWINT)));
    status = (TWSR & 0xF8); // 11111000
    if (status != 0x08) { 
        return 1; 
    }
    
    //send SLA read address
    TWDR = SLA_R; 
    TWCR = (1<<TWINT) | (1<<TWEN);
    while (!(TWCR & (1<<TWINT))); //wait
    status = (TWSR & 0xF8); // 11111000
    /*
     * 0x40 -> slave read + Ack
     */
    if (status != 0x40) {
        return 2; 
    }
    
    // Enable Acknowledge
    TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
    // wait
    while (!(TWCR & (1 << TWINT)));
    status = (TWSR & 0xF8); // 11111000
    
    //Data byte has been received; ACK has been returned
    if (status != 0x50) {
        return 3;
    }
    char data = TWDR;

    //send stop condition
    TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO); 
    
    return data;
}  


char I2C_ST(char data){
    char status=0;
    
    // Enable Acknowledge
    TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
    // wait
    while (!(TWCR & (1 << TWINT)));
    status = (TWSR & 0xF8); // 11111000
    
    // Own SLA+R has been received; ACK has been returned
    if (status != 0xA8) {
        return 1;
    }
    
    //send data
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    status = (TWSR & 0xF8); // 11111000
    /*
     Data byte in TWDR has been transmitted; ACK has been received
     */
    if (status != 0xB8) {
        return 2;
    }
   return 0; 
} 


char I2C_SR(){
    char status =0;
    
    // Enable Acknowledge 
    TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
    // wait
    while (!(TWCR & (1 << TWINT)));
    status = (TWSR & 0xF8); // 11111000
    
    //Own SLA+W has been received; ACK has been returned
    if (status != 0x60) {
        return 1;
    }
    
    // Enable Acknowledge
    TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
    // wait
    while (!(TWCR & (1 << TWINT)));
    status = (TWSR & 0xF8); // 11111000
    
    //Previously addressed with own SLA+W; data has been received; ACK has been returned
    if (status != 0x80) {
        return 2;
    }
}  


char I2C_STA_COND(){
    char status = 0;
    //send start condition
    TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
    //wait
    while (!(TWCR & (1<<TWINT)));

    status = (TWSR & 0xF8); // 11111000
    
    /*
     * 0x08 -> START
     * 0x10 -> REPEATED START
     */
    if (status != 0x08 && status != 0x10) { 
        return 1; //as error
    }
    return 0;   
}   


char I2C_CALL_DEVICE(char SLA){
    char status=0;
    //send SLA
    TWDR = SLA; 
    TWCR = (1<<TWINT) | (1<<TWEN);
    //wait
    while (!(TWCR & (1<<TWINT)));

    status = (TWSR & 0xF8); // 11111000
    
    /*
     * 0x18 -> slave write + Ack
     * 0x20 -> slave write + noAck
     * 0x40 -> slave read + Ack
     * 0x48 -> slave read + noAck
     */
    if (status != 0x18 && status != 0x20 && status != 0x40 && status != 0x48) {
        return 2; //as error
    }
    return 0;
}


char I2C_SEND_DATA(char data){
    char status = 0;
    
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    // wait
    while (!(TWCR & (1 << TWINT)));

    status = (TWSR & 0xF8); // 11111000
    
    /*
     * 0x28 -> date transmitted + Ack
     * 0x30 -> data transmitted + noAck
     */
    if (status != 0x28 && status != 0x30) {
        return 3;
}
    return 0;
}

void I2C_STO_COND(){
    //send stop condition
    TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}
