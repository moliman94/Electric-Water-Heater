/* 
 * File:   EEPROM_I2C.h
 * Author: Mohamed Soliman
 *
 * Created on July 19, 2020, 3:28 PM
 */

#ifndef EEPROM_I2C_H
#define	EEPROM_I2C_H

#include "main.h"
#include "Port.h"
#include "I2C.h"

#define EEPROM_Address_R 0xA1
#define EEPROM_Address_W 0xA0

//---[ EEPROM Routines ]---
void EEPROM_Write(unsigned int add, unsigned char data);
void EEPROM_Write_Page(unsigned int add, unsigned char* data, unsigned char len);
unsigned char EEPROM_Read(unsigned int add);
void EEPROM_Read_Page(unsigned int add, unsigned char* data, unsigned int len);



#endif	/* EEPROM_I2C_H */

