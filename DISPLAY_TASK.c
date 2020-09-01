/* 
 * File:   DISPLAY_TASK.c
 * Author: Mohamed Soliman
 *
 * Created on July 19, 2020, 1:08 PM
 */

#include "DISPLAY_TASK.h"

// ------ Private constants ----------------------------------------
//as this task is invoked every 5msec, so to get duration of 1sec, we set counter of 120
#define SSD_BLINK_DURATION (120)

static uint8 SSD_blinking_time = 0;
static uint8 blinking_state = FALSE;
void DISPLAY_TASK_init(void)
{
    SSD_init();
}

void DISPLAY_TASK(void)
{
    
    switch (System_state)
    {
    case SENSING_TEMP:
        SSD_print_2dig(avg_temp_in_C);
        break;
        
    case SET_TEMP:
        if(++SSD_blinking_time == SSD_BLINK_DURATION)
        {
            
            blinking_state = !blinking_state;
            SSD_blinking_time = 0;
        }
        if(blinking_state == TRUE)
        {
            SSD_print_2dig(Set_temp);
        }
            
        else if(blinking_state == FALSE)
        {
            SSD_turn_off();
        }
    }
}