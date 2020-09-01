/* 
 * File:   HEATER.c
 * Author: Mohamed Soliman
 *
 * Created on July 14, 2020, 10:51 PM
 */

// ------ Port pins -----------------------------------------------
// Heater is connected to portC pin 5
// to turn on heater, set the connected pin
// to turn off heater, clear the connected pin
// if you want to edit the connected pin, refer to Port.h file

#include "HEATER.h"

void heater_init(void)
{
    //set the direction pin of the heater as output
    CLRBIT(HEATER_DIR, HEATER_pin);
    //Turn off the heater as initial state of the heater
    heater_off();
}
void heater_on(void)
{
    //Turn on the heater
    SETBIT(HEATER_PORT, HEATER_pin);
}
void heater_off(void)
{
    //Turn off the heater
    CLRBIT(HEATER_PORT, HEATER_pin);
}