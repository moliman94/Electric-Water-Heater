/* 
 * File:   TIMER1.c
 * Author: Mohamed Soliman
 *
 * Created on July 17, 2020, 2:19 PM
 */

#include "TIMER1.h"

void TMR1_init(void)
{
    // Clear The Timer1 Register. To start counting from 0
    TMR1 = 0x00;
    // Choose the local clock source (timer mode)
    CLRBIT(T1CON, TMR1CS);
    // Choose the desired prescaler ratio
    T1CON &= ~((1 << T1CKPS1) | (1 << T1CKPS0));
#if PRESCALER == 1
    T1CON &= ~((1 << T1CKPS1) | (1 << T1CKPS0));
#elif PRESCALER == 2
    T1CON |= (1 << T1CKPS0);
#elif PRESCALER == 4
    T1CON |= (1 << T1CKPS1);
#elif PRESCALER == 8
    T1CON |= (1 << T1CKPS1) | (1 << T1CKPS0);
#endif
}

void TMR1_OVFINT_init(void)
{
    // Clear The Interrupt Flag Bit
    CLRBIT(PIR1, TMR1IF);
    // Timer1 Interrupt Enable
    SETBIT(PIE1, TMR1IE);
    // Peripherals Interrupts Enable
    SETBIT(INTCON, PEIE);
    // Global Interrupts Enable
    GLOB_INT_EN;
}

void TMR1_start(void)
{
    SETBIT(T1CON, TMR1ON);
}

void TMR1_stop(void)
{
    CLRBIT(T1CON, TMR1ON);
}
