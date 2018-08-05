#include <avr/io.h>
#include<util/delay.h>

void WGMconfig();

int main(void)
{
DDRB|=0xFF;
WGMconfig();

ICR1=19999;
OCR1A=ICR1-2000;

while(1){

}
    return 0;
}
void WGMconfig(){
//set clk change enable to one and set prescaler to 16 (to get 1 Mhz)
CLKPR=0xFF;
//set clk change enable to zero
CLKPR=0x0F;
//set pwm fast mode
TCCR1A|= 1 << WGM11 | 1 << COM1A1 | 1 << COM1A0;
TCCR1B|= 1 << WGM13 | 1 << WGM12 | 1<< CS10;
//set max count
}

