/*
 * LCD_Trial.c
 *
 * Created: 7/29/2020 7:43:49 PM
 *  Author: lenovo
 */ 


#include "DIO.h"
#include "lcd.h"
#define F_CPU 1000000UL
#include <util/delay.h>
int main(void)
{
	LCD_Init(0);//write 0 for 4 bits and any other number for 8 bits
	LCD_WriteStr("Hello ,Alissa");
	/*_delay_ms(1000);
	LCD_ClrDisp();//clear screen
	
	int8_t i=1 ;
	for (i;i<=10;i++)//printing from 1 to 10
	{
		LCD_SetPosition(2,1);//2nd row and 1st column
		
		LCD_WriteNum(i);
		_delay_ms(500);
	}*/
	

while (1)
{
}

    
}