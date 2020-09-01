/* 
 * File:   DISPLAY_TASK.h
 * Author: Mohamed Soliman
 *
 * Created on July 19, 2020, 1:08 PM
 */

#ifndef DISPLAY_TASK_H
#define	DISPLAY_TASK_H

#include "main.h"
#include "Port.h"
#include "STATES.h"
#include "SSD.h"

extern s_int8 Set_temp;
extern uint8 System_state;
extern s_int8 avg_temp_in_C;

void DISPLAY_TASK_init(void);
void DISPLAY_TASK(void);

#endif	/* DISPLAY_TASK_H */

