/* 
 * File:   SLEEP.c
 * Author: Mohamed Soliman
 *
 * Created on July 17, 2020, 7:22 PM
 */

#include "SLEEP.h"

uint8 SLEEP_flag = 0;

void GOTO_SLEEP(void)
{
    //Disable all output current from ports
    PORTA = 0x00;
    PORTB = 0x00;
    PORTC = 0x00;
    PORTD = 0x00;
    PORTE = 0x00;
    
    //Call SLEEP instruction
    SLEEP();
}

