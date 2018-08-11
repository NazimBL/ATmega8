void Setup();
char current_duty=122;
unsigned int adc_rd;
float d=0;

void main() {

Setup();
 
while(1){

           
           adc_rd = ADC_Read(0);
           d=(float)adc_rd/1023;
           d=d*255;
           PWM2_Set_Duty(d);
          
         
       }
}
void Setup(){

ADC_Init();

// Set PORTB pin 3 as output pin for the PWM (according to datasheet)
DDB3_bit = 1;
PWM2_Init(_PWM2_FAST_MODE, _PWM2_PRESCALER_128, _PWM2_NON_INVERTED, 255);
PWM2_Set_Duty(current_duty);

Delay_ms(100);

}
