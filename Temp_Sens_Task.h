/* 
 * File:   Temp_Sens_Task.h
 * Author: Mohamed Soliman
 *
 * Created on July 18, 2020, 9:03 PM
 */

#ifndef TEMP_SENS_TASK_H
#define	TEMP_SENS_TASK_H

#include "main.h"
#include "Port.h"
#include "STATES.h"
#include "LM35.h"
#include "HEATER.h"
#include "COOLER.h"
#include "LED.h"

// ------ Function prototypes ----------------------------------------
void Temp_Sens_Task_init(void);
void Temp_Sens_Task(void);
void Calc_avg_reading(uint8 *avg_arr);

#endif	/* TEMP_SENS_TASK_H */

