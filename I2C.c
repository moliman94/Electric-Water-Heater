/* 
 * File:   I2C.h
 * Author: Mohamed Soliman
 *
 * Created on July 19, 2020, 3:08 PM
 */

#include "I2C.h"

void I2C_Master_Wait()
{
    while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
}

void I2C_Master_Init()
{
    SSPCON = 0x28;
    SSPCON2 = 0x00;
    SSPSTAT = 0x00;
    SSPADD = ((_XTAL_FREQ / 4) / I2C_BaudRate) - 1;
    TRISCbits.TRISC3 = 1;
    TRISCbits.TRISC4 = 1;
}

void I2C_Master_Start()
{
    //---[ Initiate I2C Start Condition Sequence ]---
    I2C_Master_Wait();
    SSPCON2bits.SEN = 1;
    PIR1bits.SSPIF = 0;
}

void I2C_Master_Stop()
{
    //---[ Initiate I2C Stop Condition Sequence ]---
    I2C_Master_Wait();
    SSPCON2bits.PEN = 1;
    PIR1bits.SSPIF = 0;
}

void I2C_Master_RepeatedStart()
{
    //---[ Initiate I2C Restart Condition Sequence ]---
    I2C_Master_Wait();
    SSPCON2bits.RSEN = 1;
    PIR1bits.SSPIF = 0;
}

void I2C_ACK(void)
{
    //---[ Send ACK - For Master Receiver Mode ]---
    //I2C_Master_Wait();
    SSPCON2bits.ACKDT = 0; // 0 -> ACK, 1 -> NACK
    SSPCON2bits.ACKEN = 1; // Send ACK Signal!
    I2C_Master_Wait();
    PIR1bits.SSPIF = 0;
}

void I2C_NACK(void)
{
    //---[ Send NACK - For Master Receiver Mode ]---
    //I2C_Master_Wait();
    SSPCON2bits.ACKDT = 1; // 1 -> NACK, 0 -> ACK
    SSPCON2bits.ACKEN = 1; // Send NACK Signal!
    I2C_Master_Wait();
    PIR1bits.SSPIF = 0;
}

unsigned char I2C_Master_Write(unsigned char Data)
{
    //---[ Send Byte, Return The ACK/NACK ]---
    I2C_Master_Wait();
    SSPBUF = Data;
    while(!PIR1bits.SSPIF); // Wait Until Completion
        PIR1bits.SSPIF = 0;
    return SSPCON2bits.ACKSTAT;
}

unsigned char I2C_Read_Byte(void)
{
    I2C_Master_Wait();
    SSPCON2bits.RCEN = 1;
    while(!PIR1bits.SSPIF); // Wait Until Completion
    PIR1bits.SSPIF = 0; // Clear The Interrupt Flag Bit
    I2C_Master_Wait();
    //I2C_NACK();
    return SSPBUF;
}