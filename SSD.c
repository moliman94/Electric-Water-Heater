/* 
 * File:   SSD.c
 * Author: Mohamed Soliman
 *
 * Created on July 16, 2020, 1:58 PM
 */

#include "SSD.h"

// ------ Port pins -----------------------------------------------
/* Connections to SSD_PORT
    DP  G   F   E   D   C   B   A = SSD display pins
    |   |   |   |   |   |   |   |
   PD7 PD6 PD5 PD4 PD3 PD2 PD1 PD0 = Port pins

SSD codes for each number
0 = abcdef  => 00111111 = 0x3F
1 = bc      => 00000110 = 0x06
2 = abdeg   => 01011011 = 0x5B
3 = abcdg   => 01001111 = 0x4F
4 = bcfg    => 01100110 = 0x66
5 = acdfg   => 01101101 = 0x6D
6 = acdefg  => 01111101 = 0x7D
7 = abc     => 00000111 = 0x07
8 = abcdefg => 01111111 = 0x7F
9 = abcdfg  => 01101111 = 0x6F
To display decimal point, add 10 (decimal) to the above values */
// if you want to edit the connected pin, refer to Port.h file

uint8 const SSD_codes[20] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F,
    0xBF, 0x86, 0xDB, 0xCF, 0xE6, 0xED, 0xFD, 0x87, 0xFF, 0xEF};

// Global data formatted for display (initially 0,0)
uint8 SSD_Data[SSD_NUM_DIGITS] = {0x3F, 0x3F};

void SSD_init(void)
{
    //setting SSD direction register as output
    SSD_DIR = 0x00;
    //setting SSD selection pins direction register as output
    SSD_SEL_DIR &= ~((1 << SSD_DIGIT0_SEL) | (1 << SSD_DIGIT1_SEL));
}

void SSD_update(void)
{
    static uint8 digit = 0;
    if (++digit == SSD_NUM_DIGITS)
        digit = 0;

    switch (digit)
    {
    case 0:
        SETBIT(SSD_SEL_PORT, SSD_DIGIT0_SEL);
        CLRBIT(SSD_SEL_PORT, SSD_DIGIT1_SEL);
        break;
    case 1:
        SETBIT(SSD_SEL_PORT, SSD_DIGIT1_SEL);
        CLRBIT(SSD_SEL_PORT, SSD_DIGIT0_SEL);
        break;
    }
    SSD_PORT = SSD_Data[digit];
}

void SSD_print_2dig(uint8 val)
{
    if(val <= 99)
    {
        SSD_Data[1] = SSD_codes[val / 10];
        SSD_Data[0] = SSD_codes[val % 10];
        SSD_update();
    }
    else
        return;
}

void SSD_turn_off(void)
{
    CLRBIT(SSD_SEL_PORT, SSD_DIGIT0_SEL);
    CLRBIT(SSD_SEL_PORT, SSD_DIGIT1_SEL);
}
