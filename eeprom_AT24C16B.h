/* 
 * File:   eeprom_AT24C16B.h
 * Author: Menna
 *
 * Created on July 12, 2025, 12:36 AM
 */

#ifndef EEPROM_AT24C16B_H
#define	EEPROM_AT24C16B_H

#define AT24C16B_ADDRESS_W 0xA0 // 10100000
#define AT24C16B_ADDRESS_R 0xA1 // 10100001

void init_MM_AT24C16B();
char MM_AT24C16B_read(short MM_address);
char MM_AT24C16B_read_Current();
void MM_AT24C16B_write(short MM_address, char data);

#endif	/* EEPROM_AT24C16B_H */

