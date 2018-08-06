/*
 Bellabaci Nazim 30/12/2017 ESquad Babeee
 */

#include <avr/io.h>
#include "myADC.h"
#include "MySpi.h"

int main(void)
{

    ADC_Init();
    spi_SlaveInit();

    int value;
    char lowB,highB;

     DDRD=0xFF;

    while(1){


        value=ADC_Read(0);
        lowB=value;
        highB=(value>>8);
        SPI_Write(lowB);
        //SPI_Write(highB);


    }

    return 0;
}
