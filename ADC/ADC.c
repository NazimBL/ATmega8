/*  
* Bellabaci Nazim
* 30/12/2017 DeadLine Technologies
* Code Blocks AVR program
*/
#include <avr/io.h>
#include "myADC.h"

int main(void)
{

    ADC_Init();
    int value;

    DDRD=0xFF;
    DDRB=0xFF;

    while(1){
        value=ADC_Read(0);
        PORTD=value;
        PORTB=value>>8;
    }
    return 0;
}
