void Setup();
void writeDAC(unsigned dac,unsigned channel);

char lowB,highB;

void main() {

Setup();
writeDAC(2000,1);
         
}

void Setup(){

DDB0_bit = 1;
SPI1_Init_Advanced(_SPI_MASTER,_SPI_FCY_DIV32,_SPI_CLK_LO_LEADING);
}

void writeDAC(unsigned dac){

      lowB=dac & 0xFF;
      highB=dac >> 8;
      //add command word
      highB+=16;
      highB+=(channel*128); 
         
      PORTB0_bit=0;
      SPI1_Write(highB);
      SPI1_Write(lowB);
      PORTB0_bit=1;
}
