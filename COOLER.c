/* 
 * File:   COOLER.c
 * Author: Mohamed Soliman
 *
 * Created on July 14, 2020, 10:10 PM
 */

// ------ Port pins -----------------------------------------------
// Cooler is connected to portC pin 2
// to turn on cooler, set the connected pin
// to turn off cooler, clear the connected pin
// if you want to edit the connected pin, refer to Port.h file

#include "COOLER.h"

void cooler_init(void)
{
    //set the direction pin of the cooler as output
    CLRBIT(COOLER_DIR, COOLER_pin);
    //Turn off the cooler as initial state of the cooler
    cooler_off();
}
void cooler_on(void)
{
    //Turn on the cooler
    SETBIT(COOLER_PORT, COOLER_pin);
}
void cooler_off(void)
{
    //Turn off the cooler
    CLRBIT(COOLER_PORT, COOLER_pin);
}