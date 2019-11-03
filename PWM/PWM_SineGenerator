#include <avr/io.h>
#include<util/delay.h>

void WGMconfig();
int i=0,j=4;
int tab[]={10000,12000,14000,16000,
           18000,20000,18000,
          16000,14000,12000,10000,
          8000,6000,4000,2000,0};
          
int main(void)
{

DDRB|=0xFF;
WGMconfig();
ICR1=19999;

while(1){
  
  for(i=0;i<sizeof(tab);i++){
    if(j+i>sizeof(tab))i=0;
    OCR1A=ICR1-tab[i+j];
    }
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
