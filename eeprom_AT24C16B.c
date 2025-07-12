#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "eeprom_AT24C16B.h"
#include "I2C.h"

void init_MM_AT24C16B(){
    init_I2C(0x03);
}


char MM_AT24C16B_read(short MM_address){
    //send start condition
    I2C_STA_COND();
    
    //call device
    // Send Device Address (Write mode)
    I2C_CALL_DEVICE(AT24C16B_ADDRESS_W);
    
    //send memory location (data)
    TWDR = (char) MM_address;
    TWCR = (1 << TWINT) | (1 << TWEN);
    // wait
    while (!(TWCR & (1 << TWINT)));

    char status = (TWSR & 0xF8); // 11111000
    
    /*
     * 0x28 -> date transmitted + Ack
     * 0x30 -> data transmitted + noAck
     */
    if (status != 0x28 && status != 0x30) {
        return 1;
    }
    
    //send repeated start
    I2C_STA_COND();
    
    // Send Device Address (Read mode)
    I2C_CALL_DEVICE(AT24C16B_ADDRESS_R);
    
    // Enable Acknowledge
    TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
    // wait
    while (!(TWCR & (1 << TWINT)));
    status = (TWSR & 0xF8); // 11111000
    
    //Data byte has been received; ACK has been returned
    if (status != 0x50) {
        return 3;
    }
    
    //read data
    char data = TWDR;

    //send stop condition
    I2C_STO_COND();
    
    return data;
} 


char MM_AT24C16B_read_Current(){
    
    return I2C_MR(AT24C16B_ADDRESS_R);
}


void MM_AT24C16B_write(short MM_address, char data){
    //send start condition
    I2C_STA_COND();
    
    //call device
    // Send Device Address (Write mode)
    I2C_CALL_DEVICE(AT24C16B_ADDRESS_W);
    
    //send memory location (data)
    TWDR = (char) MM_address;
    TWCR = (1 << TWINT) | (1 << TWEN);
    // wait
    while (!(TWCR & (1 << TWINT)));

    char status = (TWSR & 0xF8); // 11111000
    
    /*
     * 0x28 -> date transmitted + Ack
     * 0x30 -> data transmitted + noAck
     */
    if (status != 0x28 && status != 0x30) {
        return 1;
    }
    
    //send data
    I2C_SEND_DATA(data);
    
    //send stop condition
    I2C_STO_COND();
}
