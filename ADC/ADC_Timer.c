void Timer_Setup();
void Setup();
unsigned adc_value;
char val1[6];
float v=0;
unsigned i=0;

void Timer0Overflow_ISR() org IVT_ADDR_TIMER0_OVF {
	
	   TIFR.TOV0_bit=0;
       adc_value = ADC_Get_Sample(0); 
       v=adc_value/1023;       
}

void main() {
	    
		//This is the program for a Timer interrupt driven ADC sampling
		
        Setup();
        Timer_Setup();
          
         while(1){
         
         UART1_Write_Text("ADC Value 1: ");
         FloatToStr(v,val1); 
		 
         //IntToStr(adc_value,val1);        
         UART1_Write_Text(val1);
         UART1_Write('\r');
         UART1_Write('\n');
        }
}

void Setup(){

DDC0_bit = 0;
DDB0_bit = 1;

for(i=0;i<6;i++)val1[i]='0';

PORTB0_bit=0;

ADC_Init();
UART1_Init_Advanced(4800, _UART_NOPARITY, _UART_ONE_STOPBIT);
Delay_ms(100);
}

void Timer_Setup(){
SREG_I_bit = 1;               // Interrupt enable
TOIE0_bit  = 1;               // Timer0 overflow interrupt enable
TCCR0  = 5;                   // Start timer with 1024 prescaler
}