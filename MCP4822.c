unsigned pot;
void Setup();
void writeDAC(unsigned dac,unsigned char channel);

void main(){

//MCP4822 DAC interface
//this programs maps potentiometer value to DAC output
Setup();
 
	while(1){
           
		   //blink C1 bit
           PORTC1_bit=~PORTC1_bit;
		   
           //test dac with pot
           pot=ADC_Read(0);
		   //map 10 bit ADC to DACs 12 bits
           writeDAC(pot*4,1);                    
           Delay_ms(50);
		}
}

void Setup(){

	//GPIOs Setup
	DDC0_bit = 0;
	DDC1_bit = 1;
	DDB0_bit = 1;
	DDB1_bit = 1;
	DDB2_bit = 1;

	PORTB0_bit=0;
	PORTB2_bit=1;
	PORTC0_bit=0;
	
	ADC_Init();
	
	SPI1_Init_Advanced(_SPI_MASTER,_SPI_FCY_DIV32,_SPI_CLK_LO_LEADING);
	Delay_ms(200);
	
}

//DAC interface function, channel 0 is voltage , channel 1 is current
void writeDAC(unsigned dac,unsigned char channel){
    
	char lowB,highB;
	
	lowB=dac & 0xFF;
	highB=dac >> 8;
	//add command word
	highB+=16;
	highB+=(channel*128);
	PORTB2_bit=0;
	SPI1_Write(highB);
	SPI1_Write(lowB);
	PORTB2_bit=1;
}