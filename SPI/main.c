/*
 * main.c
 *
 * Created: 4/18/2021 9:33:25 PM
 *  Author: lenovo
 */ 


#include "SPI.h"
#define F_CPU 8000000UL
#include <util/delay.h>	
#include "lcd.h"
#include <stdio.h>
int main(void)
{	
	LCD_Init(0);
	
	/******* FIRST ***********************
		SENDING DATA TO PORTA
		MISO will not receive anything so , the 
		shift register won't change the data in SPDR
		SPI_MasterInit();
		DDRA=0xff;
		PORTA=0x00;
	
		DDRB|=(1<<MOSI)|(1<<SCK);
		SPCR =(1<<MSTR)|(1<<SPE);
		SPDR='E';
		PORTA=SPDR;/* PORTA shows 0x0E
		_delay_ms(2000);
		
		
		while(!(SPSR &(1<<SPIF)));
		PORTA=SPDR;
		/**/ 
		/*after shifting PORTA shows 0xFF*/
		/*mission failed
		*/
		
		SPI_MasterInit();
		DDRA=0xff;
		
		int i ;
		
		PORTA=0xff;
		_delay_ms(1000);
		PORTA=0x00;
		
    while(1)
    {	
		i =1;
		
		for(i;i<=10;i++)
		{
			SPI_SendChar(i);
			PORTA=SPDR;
			_delay_ms(2000);
		}
		
		
		
        //TODO:: Please write your application code 
    }
}