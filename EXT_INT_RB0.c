/* 
 * File:   EXT_INT_RB0.h
 * Author: Mohamed Soliman
 *
 * Created on July 17, 2020, 5:45 PM
 */

#include "EXT_INT_RB0.h"

void EXT_INT_RB0_init(void)
{
#ifdef RISING_EDGE
    SETBIT(OPTION_REG, INTEDG);
#endif
#ifdef FALLING_EDGE
    CLRBIT(OPTION_REG, INTEDG);
#endif
    
    //clearing ext interrupt flag bit
    CLRBIT(INTCON, INTF);
    
    // Peripherals Interrupts Enable
    SETBIT(INTCON, PEIE);
    // Global Interrupts Enable
    GLOB_INT_EN;
}

void EXT_INT_RB0_EN(void)
{
    //clearing ext interrupt flag bit
    CLRBIT(INTCON, INTF);
    //enable ext interrupt on RB0
    SETBIT(INTCON, INTE);
}

void EXT_INT_RB0_DIS(void)
{
    //disable ext interrupt on RB0
    CLRBIT(INTCON, INTE);
}
