void Setup();
char output[4]={'0','0','0','0'};
char send;
unsigned char i=0;

//Interupt service routine , this is called when a receive uart interupt is detected

ISR(USART_RXC_vect)
{
  if(i==4)i=0;
	test=UART_Read();
	if(temp!='\0')
	{
		output[i++]=temp;
	}
	UART_Write_Text(output);
}

void main() {

UART1_Init_Advanced(19200, _UART_NOPARITY, _UART_ONE_STOPBIT);
Delay_ms(100);
UART1_Write_Text("Setup ");

 

while(1){
          
           sendUart();        
                        
}

void sendUart(){

     UART1_Write('0');
     UART1_Write('a');
     UART1_Write('b');
     UART1_Write('c');
     UART1_Write('\0');

}




