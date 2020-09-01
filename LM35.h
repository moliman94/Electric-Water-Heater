/* 
 * File:   LM35.h
 * Author: Mohamed Soliman
 *
 * Created on July 17, 2020, 10:10 AM
 */

#ifndef LM35_H
#define	LM35_H

#include "main.h"
#include "Port.h"
#include "ADC.h"

// ------ Public constants ----------------------------------------
#define VREF              5.0     // VREF is 5V
#define ADC_MAX_READ      1023.0  //(2^n)-1
#define LM35_SCALE_FACTOR 100.0   // 10mV/°C or 100°C/V

#define LM35_ADC_CH       ADC2

//------ Public function prototypes -------------------------------
void LM35_init(void);

// Function that reads temperature in celsius degree
// LM35 sensor has a scale volt of 10mV/C 
// so when we sample the output of it using 10bit ADC which has values from 0 to 1023
// so to convert the sampled quantity to celsius degree:
// 1- Read the ADC value from LM35
// 2- convert it to the corresponding voltage out of the sensor
// 3- convert this volt to the corresponding measured temperature knowing that
//    the LM35 sensor has a scale factor of 10mV/C and VREF = 5V
// So the equation will be:
// Temperature(C) = ((ADC_read*5V)/1023)/10mV
void LM35_Read_Temp(void);

#endif	/* LM35_H */

