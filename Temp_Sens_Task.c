/* 
 * File:   Temp_Sens_Task.c
 * Author: Mohamed Soliman
 *
 * Created on July 18, 2020, 9:03 PM
 */

#include "Temp_Sens_Task.h"

extern uint8 temp_in_C;
extern s_int8 Set_temp;
extern uint8 System_state;

// ------ Private constants ----------------------------------------
#define TEMP_READING_COUNT 10
//as this task is invoked every 100msec, so to get duration of 1sec, we set counter of 10
#define HEATING_LED_DURATION (10)   

// ------ Private variables ----------------------------------------
// The state of the temperature sensing task
static uint8 Heating_Cooling_state = IDLE;
static uint8 First_Reading_flag = 0;
static uint8 LED_heating_time = 0;
static uint8 readings_arr[TEMP_READING_COUNT] = {0};

// ------ Public variables ----------------------------------------
s_int8 avg_temp_in_C;

void Temp_Sens_Task(void)
{
    static uint8 reading_count = 0;
    switch (System_state)
    {
    case SET_TEMP:
        heater_off();
        cooler_off();
        break;
    case SENSING_TEMP:
        LM35_Read_Temp();
        readings_arr[reading_count] = temp_in_C;

        if (++reading_count == TEMP_READING_COUNT)
        {
            reading_count = 0;
            Calc_avg_reading(readings_arr);
            First_Reading_flag = 1;
        }
        if (First_Reading_flag)
        {
            switch (Heating_Cooling_state)
            {
            case IDLE:
                heater_off();
                cooler_off();
                LED_off();

                if ((avg_temp_in_C - Set_temp) < -5)
                    Heating_Cooling_state = HEATER_ON;
                else //if ((avg_temp_in_C - Set_temp) >= 5)
                    Heating_Cooling_state = COOLER_ON;
                break;

            case HEATER_ON:
                cooler_off();
                heater_on();

                if (++LED_heating_time == HEATING_LED_DURATION)
                {
                    LED_tog();
                    LED_heating_time = 0;
                }
                
                if ((avg_temp_in_C - Set_temp) >= 5)
                    Heating_Cooling_state = COOLER_ON;
                break;

            case COOLER_ON:
                heater_off();
                cooler_on();

                LED_on();

                if ((avg_temp_in_C - Set_temp) < -5)
                    Heating_Cooling_state = HEATER_ON;
                break;
            }
        }
    }
}

void Calc_avg_reading(uint8 *avg_arr)
{
    uint8 count;
    uint16 sum_temp = 0;
    for (count = 0; count < TEMP_READING_COUNT; count++)
    {
        sum_temp += avg_arr[count];
    }
    avg_temp_in_C = sum_temp / TEMP_READING_COUNT;
}

void Temp_Sens_Task_init()
{
    LED_init();
    heater_init();
    cooler_init();
    LM35_init();
}