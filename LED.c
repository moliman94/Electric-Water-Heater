/* 
 * File:   LED.c
 * Author: Mohamed Soliman
 *
 * Created on July 14, 2020, 9:13 PM
 */

// ------ Port pins -----------------------------------------------
// LED is connected to portB pin 7
// to turn on LED, set the connected pin
// to turn off LED, clear the connected pin
// if you want to edit the connected pin, refer to Port.h file

#include "LED.h"

void LED_init(void)
{
    //set the direction pin of the LED as output
    CLRBIT(LED_DIR, LED_pin);
    //Turn off the LED as initial state of the LED
    LED_off();
}

void LED_on(void)
{
    //Turn on the LED
    SETBIT(LED_PORT, LED_pin);
}

void LED_off(void)
{
    //Turn off the LED
    CLRBIT(LED_PORT, LED_pin);
}

void LED_tog(void)
{
    //Toggle the current state of the LED
    TOGBIT(LED_PORT, LED_pin);
}