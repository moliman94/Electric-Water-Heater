/* 
 * File:   main.h
 * Author: Mohamed Soliman
 *
 * Created on July 13, 2020, 10:37 PM
 */

#ifndef MAIN_H
#define	MAIN_H

#include <xc.h>
#include <pic16f877a.h>


/**
 * Configuration bits setup
 */

#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// Oscillator / resonator frequency (in Hz)
#define _XTAL_FREQ (8000000UL)

// Number of oscillations per instruction
#define OSC_PER_INST (4)    //for PIC16F877A



#define SETBIT(REG,BIT)  (REG |= (1<<BIT))
#define CLRBIT(REG,BIT)  (REG &= ~(1<<BIT))
#define TOGBIT(REG,BIT)  (REG ^= (1<<BIT))
#define READBIT(REG,BIT) ((REG>>BIT)&1)

typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef unsigned long  uint32;
typedef signed char    s_int8;
typedef signed short   s_int16;
typedef signed long    s_int32;


// Misc #defines
#ifndef TRUE
#define FALSE 0
#define TRUE (!FALSE)
#endif

#define NULL (0)

#define RETURN_NORMAL (bit) 0
#define RETURN_ERROR  (bit) 1

#endif	/* MAIN_H */

