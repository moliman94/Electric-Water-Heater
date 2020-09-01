/* 
 * File:   LED.h
 * Author: Mohamed Soliman
 *
 * Created on July 14, 2020, 9:13 PM
 */

#ifndef LED_H
#define	LED_H

#include "main.h"
#include "Port.h"

//------ Public function prototypes -------------------------------

void LED_init(void);
void LED_on(void);
void LED_off(void);
void LED_tog(void);

#endif	/* LED_H */

