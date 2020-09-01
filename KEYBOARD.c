/* 
 * File:   KEYBOARD.h
 * Author: Mohamed Soliman
 *
 * Created on July 15, 2020, 1:29 AM
 */

// ------ Port pins -----------------------------------------------
// ON/OFF switch is connected to portB pin 0
// UP switch is connected to portB pin 2
// DOWN switch is connected to portB pin 1
// if you want to edit the connected pins, refer to Port.h file

#include "KEYBOARD.h"

// ------ Public variable definitions ------------------------------
uint8 ON_OFF_SW_pressed_st = FALSE; //The current switch status
uint8 UP_SW_pressed_st = FALSE; //The current switch status
uint8 DOWN_SW_pressed_st = FALSE; //The current switch status

// ------ Private constants ----------------------------------------
// Allows NO or NC switch to be used (or other wiring variations)
#define SW_PRESSED (0)
// SW_THRES must be > 1 for correct debounce behaviour
#define SW_THRES (2)

// ------ Private variables ----------------------------------------
static uint8 UP_Sw_press_duration_G = 0;
static uint8 DOWN_Sw_press_duration_G = 0;
static uint8 UP_Sw_blocked_G = 0;
static uint8 DOWN_Sw_blocked_G = 0;

void keyboard_init(void)
{
    //set the direction pins of switches as input
    KEYBOARD_DIR |= (1 << ON_OFF_SW) | (1 << UP_SW) | (1 << DOWN_SW);
    // Switches are initially OFF
    UP_SW_pressed_st = FALSE;
    DOWN_SW_pressed_st = FALSE;
    UP_Sw_press_duration_G = 0;
    UP_Sw_blocked_G = 0;
    DOWN_Sw_press_duration_G = 0;
    DOWN_Sw_blocked_G = 0;
}

void UP_switch_update(void)
{
    // If the switch is blocked, decrement the count and return
    // without checking the switch pin status.
    // This is done to give the user time to remove their finger
    // from the switch - otherwise if they keep their finger on
    // the switch for more than 0.4s the light will switch off again.
    if (UP_Sw_blocked_G)
    {
        UP_Sw_blocked_G--;
        return;
    }
    if (READBIT(KEYBOARD_PORT, UP_SW) == SW_PRESSED)
    {
        UP_Sw_press_duration_G++;
        if (UP_Sw_press_duration_G > SW_THRES)
        {
            UP_Sw_press_duration_G = SW_THRES;
            // Change switch state
            UP_SW_pressed_st = TRUE;
            // Allow no other changes for ~0.5 second
            UP_Sw_blocked_G = 20;
            return;
        }
        // Switch pressed, but not yet for long enough
        UP_SW_pressed_st = FALSE;
        return;
    }
    // Switch not pressed - reset the count
    UP_Sw_press_duration_G = 0;
    UP_SW_pressed_st = FALSE;
}

void DOWN_switch_update(void)
{
    // If the switch is blocked, decrement the count and return
    // without checking the switch pin status.
    // This is done to give the user time to remove their finger
    // from the switch - otherwise if they keep their finger on
    // the switch for more than 0.4s the light will switch off again.
    if (DOWN_Sw_blocked_G)
    {
        DOWN_Sw_blocked_G--;
        return;
    }
    if (READBIT(KEYBOARD_PORT, DOWN_SW) == SW_PRESSED)
    {
        DOWN_Sw_press_duration_G++;
        if (DOWN_Sw_press_duration_G > SW_THRES)
        {
            DOWN_Sw_press_duration_G = SW_THRES;
            // Change switch state
            DOWN_SW_pressed_st = TRUE;
            // Allow no other changes for ~0.5 second
            DOWN_Sw_blocked_G = 20;
            return;
        }
        // Switch pressed, but not yet for long enough
        DOWN_SW_pressed_st = FALSE;
        return;
    }
    // Switch not pressed - reset the count
    DOWN_Sw_press_duration_G = 0;
    DOWN_SW_pressed_st = FALSE;
}



