#ifndef MYSPI_H_INCLUDED
#define MYSPI_H_INCLUDED

void spi_MasterInit(){

//SPCR=0x00;
DDRB= (1<<5)|(1<<3)|(1<<2);
SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
//SPCR = (1<<SPIE)|(1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<CPHA);
}
void spi_SlaveInit(){
  //SPCR=0x00;
  DDRB= (1<<4);
  SPCR = (1<<SPE)|(1<<SPIE)|(1<<CPHA);
   //SPCR = (1<<SPE)|(1<<SPIE)|(1<<CPHA)|(1<<SPR0);
}
void SPI_Write(char data)    /* SPI write data function */
{
  char flush_buffer;
  SPDR = data;      /* Write data to SPI data register */
  while(!(SPSR & (1<<SPIF))); /* Wait till transmission complete */
  flush_buffer = SPDR;    /* Flush received data */
/* Note: SPIF flag is cleared by first reading SPSR (with SPIF set) and then accessing SPDR hence flush buffer used here to access SPDR after SPSR read */
}
char SPI_Read()        /* SPI read data function */
{
  SPDR = 0xFF;
  while(!(SPSR & (1<<SPIF))); /* Wait till reception complete */
  return(SPDR);     /* Return received data */
}




#endif // MYSPI_H_INCLUDED
