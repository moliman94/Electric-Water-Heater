/*
 * File:   main.c
 * Author: Mohamed Soliman
 *
 * Created on July 13, 2020, 10:39 PM
 */

#include "SCH_PIC16F877A.h"
#include "Temp_Sens_Task.h"
#include "SLEEP.h"
#include "SYSTEM_STATE_UPDATE_TASK.h"
#include "SSD.h"
#include "DISPLAY_TASK.h"


#define _1st_RUNTIME_FLAG_ADDR 0x80
#define _1st_RUNTIME_SET_TEMP 60

uint8 _1st_RUNTIME_CHECK_PATTERN = 0xBC;


extern uint8 SLEEP_flag;
void SYSTEM_init(void);

//Set temperature value that is set n set mode
s_int8 Set_temp;

void main(void)
{
    
    SYSTEM_init();
    SCH_init_TMR1();
    
    /*
     * Code to check the first time to run the code
     * If it's the first time, it will write to Set_temp location value of 60 as an initial value
     * If it's not the first time to run, it will retrieve the last value saved in EEPROM
     */
    if(EEPROM_Read(_1st_RUNTIME_FLAG_ADDR) != _1st_RUNTIME_CHECK_PATTERN)
    {
        DELAY_MS(1);
        EEPROM_Write(EEPROM_address, _1st_RUNTIME_SET_TEMP);
        DELAY_MS(1);
        EEPROM_Write(_1st_RUNTIME_FLAG_ADDR, _1st_RUNTIME_CHECK_PATTERN);
    }
    DELAY_MS(1);
    Set_temp = EEPROM_Read(EEPROM_address);
    DELAY_MS(1);
    
    /*
     * Add the tasks to the scheduler
     * The system tick is 5msec
     */
    //SYSTEM_STATE_UPDATE_TASK will run periodically every 4 system ticks or 20ms
    //as the system responses to each press to the buttons
    SCH_Add_Task(SYSTEM_STATE_UPDATE_TASK, 0, 4);
    
    //Temp_Sens_Task will run periodically every 20 system ticks or 100ms
    //as system requirement
    SCH_Add_Task(Temp_Sens_Task, 0, 20);
    
    //DISPLAY_TASK will run periodically every 1 system ticks or 5ms
    //So the seven segment display doesn't flicker.
    SCH_Add_Task(DISPLAY_TASK, 0, 1);
    
    
    SCH_Start();

    while (1)
    {
        if(!SLEEP_flag)
            GOTO_SLEEP();
        SCH_Dispatch_Tasks(); 
    }
    
    return;
}

void SYSTEM_init(void)
{
    SYSTEM_UPDATE_init();
    Temp_Sens_Task_init();
    DISPLAY_TASK_init();
    EXT_INT_RB0_init();
    EXT_INT_RB0_EN();
}

void __interrupt() ISR()
{
    if(READBIT(PIR1, TMR1IF))
    {
        //Run the update task API every system tick to fire the flag for
        //the next task to run
        SCH_Update_Task();
    }
    
    /*
     * Check if ON/OFF push button is released to change the sleep flag state
     * and wake up the system if the system in sleep mode
     */
    if(READBIT(INTCON, INTF) == 1)
    {
        SLEEP_flag = !SLEEP_flag;
        CLRBIT(INTCON, INTF);
    }
}