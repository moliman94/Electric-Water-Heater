/* 
 * File:   SSD.h
 * Author: Mohamed Soliman
 *
 * Created on July 16, 2020, 1:56 PM
 */

#ifndef SSD_H
#define	SSD_H

#include "main.h"
#include "Port.h"

//------ Public function prototypes -------------------------------
void SSD_init(void);

/*------------------------------------------------------------------*-
void SSD_update(void)
Updates (two) multiplexed 8-segment LED displays.
Usually aim to be called at around 5 ms intervals
-*------------------------------------------------------------------*/
void SSD_update(void);
void SSD_print_2dig(uint8 val);
void SSD_turn_off(void);

#endif	/* SSD_H */

