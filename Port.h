/* 
 * File:   Port.h
 * Author: Mohamed Soliman
 *
 * Created on July 14, 2020, 10:49 AM
 */

/*
 * Port Header for Electric Water Heater project
 * Running on PIC16F877A
 */


#ifndef PORT_H
#define	PORT_H

#include "main.h"
#include "DELAY.h"

/*
 * Ports pin definitions
 */
//PORTA
#define PA0 0
#define PA1 1
#define PA2 2
#define PA3 3
#define PA4 4
#define PA5 5

//PORTB
#define PB0 0
#define PB1 1
#define PB2 2
#define PB3 3
#define PB4 4
#define PB5 5
#define PB6 6
#define PB7 7

//PORTC
#define PC0 0
#define PC1 1
#define PC2 2
#define PC3 3
#define PC4 4
#define PC5 5
#define PC6 6
#define PC7 7

//PORTD
#define PD0 0
#define PD1 1
#define PD2 2
#define PD3 3
#define PD4 4
#define PD5 5
#define PD6 6
#define PD7 7

//PORTE
#define PE0 0
#define PE1 1
#define PE2 2

// ------ LED.c ------------------------------------------------
#define LED_PORT PORTB
#define LED_DIR  TRISB

#define LED_pin PB7

// ------ SSD.c ------------------------------------------------
#define SSD_PORT     PORTD
#define SSD_DIR      TRISD
#define SSD_SEL_PORT PORTA
#define SSD_SEL_DIR  TRISA

#define a PD0
#define b PD1
#define c PD2
#define d PD3
#define e PD4
#define f PD5
#define g PD6
#define DP PD7

#define SSD_NUM_DIGITS (2)
#define SSD_DIGIT0_SEL PA5
#define SSD_DIGIT1_SEL PA4

// ------ KEYBOARD.c ------------------------------------------------
#define KEYBOARD_PORT PORTB
#define KEYBOARD_DIR  TRISB

#define ON_OFF_SW PB0
#define UP_SW     PB2
#define DOWN_SW   PB1

// ------ COOLER.c ------------------------------------------------
#define COOLER_PORT PORTC
#define COOLER_DIR  TRISC

#define COOLER_pin PC2

// ------ HEATER.c ------------------------------------------------
#define HEATER_PORT PORTC
#define HEATER_DIR  TRISC

#define HEATER_pin PC5

// ------ LM35.c ------------------------------------------------
#define LM35_PORT PORTA
#define LM35_DIR  TRISA

#define LM35_pin PA2

// ------ EEPROM_I2C.c ------------------------------------------------
#define EXT_EEPROM_PORT PORTC
#define EXT_EEPROM_DIR  TRISC

#define SDA_pin PC4
#define SCK_pin PC3

#endif	/* PORT_H */

