/* 
 * File:   ADC.c
 * Author: Mohamed Soliman
 *
 * Created on July 16, 2020, 9:29 PM
 */

#include "ADC.h"

void ADC_init(void)
{
    //select the A/D Conversion Clock Select bits
    //we use clock division of Fosc/16 as A/D conversion clock
    //(TAD) must be selected to ensure a minimum TAD time
    //of 1.6 us. 
    //and the used freq of CPU is 8MHz
    //ADCS2:0 --> 0b101
    ADCON0 = 0x00;
    ADCON1 = 0x00;
    ADCON0 |= (1 << ADCS0);
    ADCON1 |= (1 << ADCS2);

    SETBIT(ADCON0, ADON); // Turn on A/D module
    SETBIT(ADCON1, ADFM); // Result is Right justified
}

uint16 ADC_get_Sample(const uint8 ADC_channel)
{
    //select ADC channel
    ADCON0 |= (ADC_channel << 3);
    //Wait the required acquisition time.
    DELAY_US(DATA_ACQ_TIME);
    //Start conversion
    SETBIT(ADCON0, GO_DONE);
    // Wait for the conversion to complete
    // GO_DONE bit will be cleared once conversion is complete
    while (READBIT(ADCON0, GO_DONE) == 1);

    return ((ADRESH << 8) + ADRESL); // return right justified 10-bit result
}
