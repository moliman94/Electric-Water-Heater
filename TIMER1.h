/* 
 * File:   TIMER1.h
 * Author: Mohamed Soliman
 *
 * Created on July 17, 2020, 2:19 PM
 */

#ifndef TIMER1_H
#define	TIMER1_H

#include "main.h"
#include "Port.h"
#include "INTERRUPT.h"

/* Timer1 control register bits definitions (T1CON) */
#define TMR1ON  0
#define TMR1CS  1
#define T1SYNC  2
#define T1OSCEN 3
#define T1CKPS0 4
#define T1CKPS1 5

/*
 * Prescaler value of Timer1
 * it has four prescaler values:
 * 1:1 ---> T1CKPS1:T1CKPS0 = 0b00
 * 1:2 ---> T1CKPS1:T1CKPS0 = 0b01
 * 1:4 ---> T1CKPS1:T1CKPS0 = 0b10
 * 1:8 ---> T1CKPS1:T1CKPS0 = 0b11
 */
#define PRESCALER 1

// Assume we want the Timer1 to overflow every 1ms using Timer1 which is 16-bit
// if the oscillator is 8MHz, so the freq of the timer is Fosc/4 = 2MHz
// So, tick time of Timer1 is 0.5 us
// No. of ticks of the timer is 2^16 = 65536
// So, this takes 2000 timer ticks to produce 1ms
#define TMR1_OVF_PRELOAD(x) (65536-(_XTAL_FREQ/(4*PRESCALER))*(x/1000.0))
#define PRELOAD_ERROR 0.25f

//------ Public function prototypes -------------------------------

void TMR1_init(void);
void TMR1_OVFINT_init(void);
void TMR1_start(void);
void TMR1_stop(void);

#endif	/* TIMER1_H */

