/*
 * LCD_Trial.c
 *
 * Created: 7/29/2020 7:43:49 PM
 *  Author: lenovo
 */ 


#include "DIO.h"
#include "lcd.h"
#define F_CPU 16000000UL
#include <util/delay.h>
int main(void)
{
	LCD_Init(0);
LCD_WriteNum(-256.712);	
/*
u8 * r;
u8 * c ;
* r =0 ;
* c=0;
	
	 LCD_Init(0);
	 LCD_FunctionSet(1,1);
	 LCD_WriteStr("Hello ,");
	LCD_SetPosition(2,1);
	LCD_WriteStr("");
	_delay_ms(2);
	LCD_WriteStr("beautiful Stacy");
	
	
	LCD_ReadPosition(r ,c);
	
	
	DIO_PinMode(*r,PortA,OUTPUT);
	DIO_PinMode(*c,PortB,OUTPUT);
	
	DIO_Pin_DigitalWrite(*r,PortA,HIGH);
	DIO_Pin_DigitalWrite(*c,PortB,HIGH);
	*/
    
}