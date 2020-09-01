/* 
 * File:   SCH_PIC16F877A.h
 * Author: Mohamed Soliman
 *
 * Created on July 17, 2020, 11:34 PM
 */

#ifndef SCH_PIC16F877A_H
#define	SCH_PIC16F877A_H

#include "main.h"
#include "TIMER1.h"
#include "INTERRUPT.h"

/*
 * Scheduler data structure
 */
typedef struct Tasks
{
    // Pointer to the task
    void (*ptr_Task)(void);
    // Delay (ticks) until the function will (next) be run
    uint16 Delay;
    // Interval (ticks) between subsequent runs.
    uint16 Period;
    // Incremented (by scheduler) when task is due to execute
    uint8 Run;
}sTask;

// The maximum number of tasks required at any one time
// during the execution of the program
#define SCH_MAX_TASKS (3)
#define SYSTEM_TICK   (5)   //system tick in msec

// Error codes that may arise
#define ERROR_SCH_TOO_MANY_TASKS (1)
#define ERROR_SCH_CANNOT_DELETE_TASK (2)

//------ Public function prototypes -------------------------------

void SCH_init_TMR1(void);
void SCH_Delete_Task(const uint8 Task_Index);
void SCH_Update_Task(void);
uint8 SCH_Add_Task(void (*ptr_fun)(), const uint16 Delay, const uint16 Period);
void SCH_Dispatch_Tasks(void);
void SCH_Start(void);


#endif	/* SCH_PIC16F877A_H */

