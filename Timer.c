/*
Nazim BL
mikroC PRO for AVR
Blinking LED through Timer
*/

void Timer_Setup();

//Timer ISR
void Timer0Overflow_ISR() org IVT_ADDR_TIMER0_OVF {
  PORTB0_bit=~PORTB0_bit;  
}


void main() {

DDB0_bit = 1;
PORTB0_bit=0;
}


void Timer_Setup(){

SREG_I_bit = 1;               // Interrupt enable
TOIE0_bit  = 1;               // Timer0 overflow interrupt enable
TCCR0  = 5;                   // Start timer with 1024 prescaler
}
