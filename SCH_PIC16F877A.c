/* 
 * File:   SCH_PIC16F877A.c
 * Author: Mohamed Soliman
 *
 * Created on July 17, 2020, 11:34 PM
 */

#include "SCH_PIC16F877A.h"

uint8 ERROR_Code = 0;

// The array of tasks structures
sTask SCH_tasks[SCH_MAX_TASKS];

void SCH_init_TMR1(void)
{
    uint8 i;
    for (i = 0; i < SCH_MAX_TASKS; i++)
        SCH_Delete_Task(i);

    // Reset the global error variable
    ERROR_Code = 0;

    // Now set up Timer1 (16-bit) for creating system ticks
    TMR1_init();
    TMR1_OVFINT_init();
    //Disable global interrupts
    GLOB_INT_DIS;
    // Crystal is assumed to be 8 MHz
    // The Timer 1 resolution is (0.5 ?s)
    // The required Timer 1 overflow is (1 ms)
    // - this takes 2000 timer ticks
    // Preload value is 65536 - 2000 = 63536
    TMR1 = TMR1_OVF_PRELOAD(SYSTEM_TICK);

    //Start Timer1
    TMR1_start();
}

/*
 * This is the scheduler update function that will be called in ISR. 
 * It is called at a rate
 * determined by the timer settings in the 'init' function.
 */
void SCH_Update_Task(void)
{
    uint8 Index;

    // Manually reload TMR1 register because there is automatic reload feature
    TMR1 = TMR1_OVF_PRELOAD(SYSTEM_TICK) - TMR1_OVF_PRELOAD(PRELOAD_ERROR);

    // Clear The Interrupt Flag Bit
    // This should be done to detect the next interrupt
    CLRBIT(PIR1, TMR1IF);

    // NOTE: calculations are in *TICKS* (not milliseconds)
    for (Index = 0; Index < SCH_MAX_TASKS; Index++)
    {
        // Check if there is a task at this location
        if (SCH_tasks[Index].ptr_Task)
        {
            if (SCH_tasks[Index].Delay == 0)
            {
                // The task is due to run
                SCH_tasks[Index].Run++;
                if (SCH_tasks[Index].Period)
                    // Schedule periodic tasks to run again
                    SCH_tasks[Index].Delay = SCH_tasks[Index].Period;
            }
            else
                // Not yet ready to run: just decrement the delay
                SCH_tasks[Index].Delay--;
        }
    }
}

/*
 * SCH_Add_Task() is used to add tasks to the task array
 * Input parameters to the function:
 * 1- Task_Name:
 *      the name of the function (task) that you wish to schedule.
 * 2- Delay:
 *      the delay (in ticks) before task is first executed. 
 *      If set to 0, the task is executed immediately.
 * 3- Period:
 *      the interval (in ticks) between repeated executions of the task.
 *      If set to 0, the task is executed only once.
 * 
 * Return value of the function
 *    Index:
 *      return task ID (the position in the task array) so that the
 *      task may be subsequently deleted,
 */
uint8 SCH_Add_Task(void (*ptr_fun)(), const uint16 Delay, const uint16 Period)
{
    uint8 Index = 0;
    // First find a gap in the array (if there is one)
    while ((SCH_tasks[Index].ptr_Task != 0) && (Index < SCH_MAX_TASKS))
        Index++;

    // Have we reached the end of the list?
    if (Index == SCH_MAX_TASKS)
    {
        //Task list is full and there is no place for new tasks
        ERROR_Code = ERROR_SCH_TOO_MANY_TASKS;
        //return the error code
        return SCH_MAX_TASKS;
    }
    SCH_tasks[Index].ptr_Task = ptr_fun;
    SCH_tasks[Index].Delay = Delay;
    SCH_tasks[Index].Period = Period;
    SCH_tasks[Index].Run = 0;

    return Index; // return position of task (to allow later deletion)
}

/*
 * When a task (function)
 * is due to run, SCH_Dispatch_Tasks() will run it.
 * This function must be called (repeatedly) from the main loop.
 */
void SCH_Dispatch_Tasks(void)
{
    uint8 Index;

    // Dispatches (runs) the next task (if one is ready
    for (Index = 0; Index < SCH_MAX_TASKS; Index++)
    {
        if (SCH_tasks[Index].Run > 0)
        {
            (*SCH_tasks[Index].ptr_Task)(); //Run the task
            SCH_tasks[Index].Run--; //Reset Run flag

            // Periodic tasks will automatically run again
            // - if this is a 'one shot' task, remove it from the array
            if (SCH_tasks[Index].Period == 0)
                SCH_Delete_Task(Index);
        }
    }
}

/*
 * This functions start scheduling by enabling global interrupts
 * allowing SCH_Update_Task() to be invoked
 */
void SCH_Start(void)
{
    //Enable Global interrupts
    GLOB_INT_EN;
}

void SCH_Delete_Task(const uint8 Task_Index)
{
    if (SCH_tasks[Task_Index].ptr_Task == 0)
        // No task at this location
        ERROR_Code = ERROR_SCH_CANNOT_DELETE_TASK;

    SCH_tasks[Task_Index].ptr_Task = 0;
    SCH_tasks[Task_Index].Delay = 0;
    SCH_tasks[Task_Index].Period = 0;
    SCH_tasks[Task_Index].Run = 0;
}

