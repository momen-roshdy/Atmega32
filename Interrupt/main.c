/*
 * main.c
 *
 * Created: 9/14/2020 12:25:05 PM
 *  Author: lenovo
 */ 


#include "avr_interrupt.h"
#include "DIO.h"
 #define    F_CPU   16000000 
#include <util/delay.h>

int main(void)
{	
	DIO_PinMode(0,PortC,OUTPUT);
	INT_Init(INT0,LogicalChange);
	
    while(1)
    {	
		DIO_Pin_DigitalWrite(0,PortC,LOW);
        //TODO:: Please write your application code 
    }
}

ISR (INT0_vect)
{
	DIO_Pin_DigitalWrite(0,PortC,HIGH);
	_delay_ms(50);
}