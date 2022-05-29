/*
 * SPI.c
 *
 * Created: 4/18/2021 9:35:40 PM
 *  Author: lenovo
 */ 
#include "SPI.h"




void SPI_MasterInit(void )
{	
	/*Setting outputs */
	DDRB |=(1<<MOSI) | (1<<SCK) | (1<<SS);
	/* setting inputs*/
	DDRB &= (~(1<<MISO));
	/*setting the SPCR : master - idle zero-first edge(Rising EDGE) -LSB -F/4 */
	SPCR |=(1<<SPE)|(1<<MSTR);

	/* SET slave select */
	/*WE WERE LIED TO*/
	//PORTB |= (1<<SS);
	
}
void SPI_SendChar (char data)
{	
	
	/*we want to send a char and then wait for the 
		Transmission to be complete to avoid collisions
		and then we have to clear the SPIF */
	/*clearing SPIF require reading The SPSR while SPIF is set and then 
		reading the SPDR */
	char flush_buffer ;
	/*as soon as u put new data in SPDR and SS is set , it starts sending */
	SPDR =data;
	while (!(SPSR &(1<<SPIF)));
	flush_buffer=SPDR;
	
}

char SPI_ReadChar (void)
{	
	/* wait for the 
		Transmission to be complete to avoid interruption
		and then we have to clear the SPIF */
	/*clearing SPIF require reading The SPSR while SPIF is set and then 
		reading the SPDR */
	while ( !(SPSR &(1<<SPIF)));
	return SPDR;
}

void SPI_SlaveInit(void) 
{
	/*Setting outputs */
	DDRB |=(1<<MISO) ;
	/* setting inputs*/
	DDRB &= ~((1<<MOSI) |(1<<SS) |(1<<SCK));
	/*setting the SPCR : master - idle zero-first edge(Rising EDGE) -LSB -F/4 */
	SPCR =(1<<SPE);
	
   PORTB |= (1<<SS);//we were lied to 
	
}

void SPI_SendStr (const char *str)
{
	int i=0;
	while (str[i] !='\0')
	{
		SPI_SendChar(str[i]);
		i++;
	}
}
SPI_ReadStr (char * str, unsigned char str_size)
{
	/*if the transmitter sends a string with a size bigger 
		than what we have , then we should stop storing at str[size-2]
		and store '\0' at str[size-1] */
	unsigned char i=0;
	
	for (i;i<str_size-1;i++)/*last to enter is str[size-2]*/
	{	
		
		
		str[i]=SPI_ReadChar();
		if (str[i]=='\0')
		{
			break;
		}
		
	}
	str[i]='\0';
	
}