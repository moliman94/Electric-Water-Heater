/* 
 * File:   INTERRUPT.h
 * Author: Mohamed Soliman
 *
 * Created on July 17, 2020, 2:21 PM
 */

#ifndef INTERRUPT_H
#define	INTERRUPT_H

/*
 * Interrupts control registers bits definitions
 */

//INTCON register
#define RBIF   0
#define INTF   1
#define TMR0IF 2
#define RBIE   3
#define INTE   4
#define TMR0IE 5
#define PEIE   6
#define GIE    7

//PIR1 register
#define TMR1IF 0
#define TMR2IF 1
#define CCP1IF 2
#define SSPIF  3
#define TXIF   4
#define RCIF   5
#define ADIF   6
#define PSPIF  7

//PIE1 register
#define TMR1IE 0
#define TMR2IE 1
#define CCP1IE 2
#define SSPIE  3
#define TXIE   4
#define RCIE   5
#define ADIE   6
#define PSPIE  7

//OPTION_REG register
#define INTEDG 6

#define GLOB_INT_EN  SETBIT(INTCON, GIE)
#define GLOB_INT_DIS CLRBIT(INTCON, GIE)


#endif	/* INTERRUPT_H */

