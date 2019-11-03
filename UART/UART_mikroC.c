unsigned char receive;


void main() {

UART1_Init_Advanced(4800, _UART_NOPARITY, _UART_ONE_STOPBIT);
Delay_ms(100);

while(1){
           
           UART_Write('1');
           UART_Write('2');
           UART_Write('3');
         
         if (UART1_Data_Ready() == 1) {

           receive = UART1_Read();
           UART_Write(receive);
           receive = UART1_Read();
           UART_Write(receive); 
           receive = UART1_Read();
           UART_Write(receive);
           UART_Write('\r');
           UART_Write('\n');

         }
          
          Delay_ms(500);
}
