/* 
 * File:   SYSTEM_STATE_UPDATE_TASK.h
 * Author: Mohamed Soliman
 *
 * Created on July 18, 2020, 11:41 PM
 */

#ifndef READ_BUTTONS_TASK_H
#define	READ_BUTTONS_TASK_H

#include "main.h"
#include "Port.h"
#include "STATES.h"
#include "KEYBOARD.h"
#include "EEPROM_I2C.h"

#define EEPROM_address 0x00

void SYSTEM_STATE_UPDATE_TASK(void);
void SYSTEM_UPDATE_init(void);


#endif	/* READ_BUTTONS_TASK_H */

