/* 
 * File:   LM35.c
 * Author: Mohamed Soliman
 *
 * Created on July 17, 2020, 10:10 AM
 */

#include "LM35.h"

// ------ Public variable definitions ------------------------------
uint8 temp_in_C = 0;

void LM35_init()
{
    SETBIT(LM35_PORT, LM35_pin); //configure sensor pin as input
    ADC_init();
}

void LM35_Read_Temp()
{
    temp_in_C = ((ADC_get_Sample(LM35_ADC_CH) * VREF) / ADC_MAX_READ) * LM35_SCALE_FACTOR;
}