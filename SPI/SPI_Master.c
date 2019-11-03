/*
* Bellabaci Nazim 
* DeadLine Tech
* CodeBlocks
*/

#include <avr/io.h>
#include <util/delay.h>
#include "MySpi.h"

int main(void)
{
    //slave control register
    DDRD=0xFF;
    DDRC=0xFF;
    char value=0;
    char i=0;
    char cs[3]={0xBF,0xDF,0x7F};

    spi_MasterInit();

    while(1){
         
           for(i=0;i<3;i++){
            PORTD=cs[i];
            value=SPI_Read();
            PORTC=value;
            _delay_ms(120);
           }
    }
    return 0;
}
