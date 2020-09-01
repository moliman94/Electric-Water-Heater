/* 
 * File:   EXT_INT_RB0.h
 * Author: Mohamed Soliman
 *
 * Created on July 17, 2020, 5:45 PM
 */

#ifndef EXT_INT_RB0_H
#define	EXT_INT_RB0_H

#include "main.h"
#include "INTERRUPT.h"

// Define the edge of interrupt
// Either RISING_EDGE or FALLING_EDGE
#define RISING_EDGE

//------ Public function prototypes -------------------------------
void EXT_INT_RB0_init(void);
void EXT_INT_RB0_EN(void);
void EXT_INT_RB0_DIS(void);

#endif	/* EXT_INT_RB0_H */

