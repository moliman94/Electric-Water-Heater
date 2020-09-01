/* 
 * File:   I2C.h
 * Author: Mohamed Soliman
 *
 * Created on July 19, 2020, 3:08 PM
 */

#ifndef I2C_H
#define	I2C_H

#include "main.h"
#include "Port.h"

#define I2C_BaudRate 100000

//---[ I2C Routines ]---
void I2C_Master_Init();
void I2C_Master_Wait();
void I2C_Master_Start();
void I2C_Master_RepeatedStart();
void I2C_Master_Stop();
void I2C_ACK();
void I2C_NACK();
unsigned char I2C_Master_Write(unsigned char);
unsigned char I2C_Read_Byte(void);
#endif	/* I2C_H */

