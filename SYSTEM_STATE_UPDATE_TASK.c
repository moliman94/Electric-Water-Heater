/* 
 * File:   SYSTEM_STATE_UPDATE_TASK.c
 * Author: Mohamed Soliman
 *
 * Created on July 18, 2020, 11:41 PM
 */

#include "SYSTEM_STATE_UPDATE_TASK.h"

extern s_int8 Set_temp;
extern uint8 UP_SW_pressed_st;
extern uint8 DOWN_SW_pressed_st;

// ------ Private constants ----------------------------------------
//as this task is invoked every 20msec, so to get duration of 5sec, we set counter of 250
#define UP_DOWN_BUTTONS_TIMEOUT (250)
//#define UP_DOWN_BUTTONS_DEBOUNCE (2)

#define TEMP_TOP_BOUND 75
#define TEMP_BOTTOM_BOUND 35
#define TEMP_SET_STEP 5

// ------ Private variables ----------------------------------------
// The state of the temperature sensing task
static uint8 Read_Button_state; //initial state
static uint8 Timeout_button = 0;

// ------ Public variables ----------------------------------------
uint8 System_state = SENSING_TEMP;

void SYSTEM_STATE_UPDATE_TASK(void)
{
    
    UP_switch_update();
    DOWN_switch_update();
    
    switch (System_state)
    {
    case SENSING_TEMP:
        if ((UP_SW_pressed_st == TRUE) || (DOWN_SW_pressed_st == TRUE))
        {
            System_state = SET_TEMP;

            UP_SW_pressed_st = FALSE;
            DOWN_SW_pressed_st = FALSE;
        }
        break;

    case SET_TEMP:
        if ((UP_SW_pressed_st == FALSE) && (DOWN_SW_pressed_st == FALSE))
        {
            if (++Timeout_button == UP_DOWN_BUTTONS_TIMEOUT)
            {
                System_state = SENSING_TEMP;
                Timeout_button = 0;
                
                break;
            }

        }
        else
        {
            if (UP_SW_pressed_st == TRUE)
            {
                Read_Button_state = UP_PRESSED;
                Timeout_button = 0; //resetting timeout again
            }

            if (DOWN_SW_pressed_st == TRUE)
            {
                Read_Button_state = DOWN_PRESSED;
                Timeout_button = 0; //resetting timeout again
            }
        }
        //break; 


        switch (Read_Button_state)
        {
        case UP_PRESSED:
            UP_SW_pressed_st = FALSE;
            Read_Button_state = NOT_PRESSED;
            if (Set_temp >= TEMP_TOP_BOUND)
                Set_temp = TEMP_TOP_BOUND;
            else
                Set_temp += TEMP_SET_STEP;
            EEPROM_Write(EEPROM_address, Set_temp);
            
            break;


        case DOWN_PRESSED:
            DOWN_SW_pressed_st = FALSE;
            Read_Button_state = NOT_PRESSED;
            if (Set_temp <= TEMP_BOTTOM_BOUND)
                Set_temp = TEMP_TOP_BOUND;
            else
                Set_temp -= TEMP_SET_STEP;
            EEPROM_Write(EEPROM_address, Set_temp);
           
            break;

        case NOT_PRESSED:
            UP_SW_pressed_st = FALSE;
            DOWN_SW_pressed_st = FALSE;
        }
    }
}

void SYSTEM_UPDATE_init(void)
{
    keyboard_init();
    I2C_Master_Init();
}
