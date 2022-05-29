/*
 * main.c
 *
 * Created: 9/27/2020 12:17:10 A
 *  Author: lenovo
 */ 



#include "DIO.h"
#include "AVR_ADC.h"
#include "lcd.h"
#define  F_CPU 16000000 
#include <util/delay.h>


int main(void)
{	u8 reading ;
	LCD_Init(LOW );
	ADC_Init(Internal_VRef,ADC0,ADC_CLK_128,ADSC);
	LCD_WriteStr("TEMP = ");
    while(1)
    {	
		
		
		ADC_StartConversion();
		while (! ADC_Flag() );
		
		reading=ADC_Read();
		LCD_SetPosition(1,8);
		LCD_WriteNum(reading>>2);
		LCD_WriteStr(" C");
		_delay_ms(50);
		
		
       
    }
}