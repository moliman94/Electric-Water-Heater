/* 
 * File:   STATES.h
 * Author: Mohamed Soliman
 *
 * Created on July 19, 2020, 7:40 AM
 */

#ifndef STATES_H
#define	STATES_H



//System states
#define OFF_STATE    0
#define SENSING_TEMP 1
#define SET_TEMP     2

//Read Buttons Task states
#define UP_PRESSED      2
#define DOWN_PRESSED    4
#define NOT_PRESSED     5

//Temp sensing task states
#define IDLE       0
#define HEATER_ON  1
#define COOLER_ON  2

//Display states
#define DISPLAY_CURRENT_TEMP 0
#define DISPLAY_SET_TEMP     1



#endif	/* STATES_H */

