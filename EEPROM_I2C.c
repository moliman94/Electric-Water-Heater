/* 
 * File:   EEPROM_I2C.c
 * Author: Mohamed Soliman
 *
 * Created on July 19, 2020, 3:28 PM
 */

#include "EEPROM_I2C.h"

void EEPROM_Write(unsigned int add, unsigned char data)
{
    I2C_Master_Start();
    // Wait Until EEPROM Is IDLE
    while (I2C_Master_Write(EEPROM_Address_W))
        I2C_Master_RepeatedStart();
    I2C_Master_Write(add >> 8);
    I2C_Master_Write((unsigned char) add);
    I2C_Master_Write(data);
    I2C_Master_Stop();
}

//---[ Byte Read ]---

unsigned char EEPROM_Read(unsigned int add)
{
    unsigned char Data;
    I2C_Master_Start();
    //Wait Until EEPROM Is IDLE
    while (I2C_Master_Write(EEPROM_Address_W))
        I2C_Master_RepeatedStart();
    I2C_Master_Write(add >> 8);
    I2C_Master_Write((unsigned char) add);
    I2C_Master_RepeatedStart();
    I2C_Master_Write(EEPROM_Address_R);
    Data = I2C_Read_Byte();
    I2C_NACK();
    I2C_Master_Stop();
    return Data;
}


