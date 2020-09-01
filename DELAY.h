/* 
 * File:   DELAY.h
 * Author: Mohamed Soliman
 *
 * Created on July 15, 2020, 4:40 PM
 */

#ifndef DELAY_H
#define	DELAY_H

#include "main.h"

// 8MHz clock means 8000000 cycles per second.
// So 1 cycle equals 1/8000000 seconds or 1/8us.
// To get 1 second delay, you need 8000000 cycles of 1/8us,
// so it means that you have to DELAY_MS(1000) which means number of cycles (8000000/1000)*1000 =8000000 cycles = 1 sec
// and it means that you have to DELAY_US(1000) which means number of cycles (8000000/1000000)*1000 =8000 cycles = 1 msec
// the "NOP" takes 1 Cycle only

#define ERROR_FACTOR 152
uint32 DelayCount;

#define DELAY_MS(x)\
		for(DelayCount = ((_XTAL_FREQ/1000)*x/ERROR_FACTOR); DelayCount>0; DelayCount--)\
				__asm("NOP");

#define DELAY_US(x)\
		for(DelayCount = ((_XTAL_FREQ/1000000)*x/ERROR_FACTOR); DelayCount>0; DelayCount--)\
				__asm("NOP");

#endif	/* DELAY_H */

