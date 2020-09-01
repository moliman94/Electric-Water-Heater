/* 
 * File:   ADC.h
 * Author: Mohamed Soliman
 *
 * Created on July 16, 2020, 9:29 PM
 */

#ifndef ADC_H
#define	ADC_H

#include "main.h"
#include "Port.h"

//ADC channels
#define ADC0 0   
#define ADC1 1   
#define ADC2 2   
#define ADC3 3   
#define ADC4 4   
#define ADC5 5   
#define ADC6 6   
#define ADC7 7   

//ADC registers bits
//ADCON0
#define ADON 0
#define GO_DONE 2
#define CHS0 3
#define CHS1 4
#define CHS2 5
#define ADCS0 6
#define ADCS1 7

//ADCON1
#define ADCS2 6
#define ADFM 7

#define DATA_ACQ_TIME 25 //data acquisition time is 25us


//------ Public function prototypes -------------------------------
        
void ADC_init(void);
uint16 ADC_get_Sample(const uint8 ADC_channel);

#endif	/* ADC_H */

