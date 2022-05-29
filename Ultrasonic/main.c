/*
 * main.c
 *
 * Created: 1/24/2021 1:07:44 AM
 *  Author: lenovo
  */



#include <avr/io.h>
#include "lcd.h"
#include "ULTRASONIC_test.h"
#include "util/delay.h"
#define F_CPU 8000000UL
int main(void)
{	
	
	double Right_Reading = -1 ;
	double Left_Reading=-1 ;
	
	Ultrasonic_Init0();
    while(1)
    {	

		LCD_ClrDisp();
		Ultrasonic_Read0(&Left_Reading);
		
	 Ultrasonic_Read1(&Right_Reading);
	  	 LCD_SetPosition(1,1);
	  	 LCD_WriteNum(Left_Reading);
	  	 LCD_SetPosition(2,1);
	  	 LCD_WriteNum(Right_Reading);
		 _delay_ms(500);
	
        //TODO:: Please write your application code 
    }
}

/*
#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#include "lcd.h"	 Include LCD header file 
#define  Trigger_pin	PD5	 Trigger pin 
int TimerOverflow = 0;

ISR(TIMER1_OVF_vect)
{
	TimerOverflow++;	 Increment Timer Overflow count }

int main(void)
{
	char string[10];
	long count;
	double distance;
	
	DDRD = 1<<Trigger_pin;		 Make trigger pin as output 	PORTD = 0b01000000;		 Turn on Pull-up 	
	LCD_Init(0);
	
	
	sei();			 Enable global interrupt 	TIMSK = (1 << TOIE1);	 Enable Timer1 overflow interrupts 	TCCR1A = 0;		 Set all bit to zero Normal operation 
	while(1)
	{
		 Give 10us trigger pulse on trig. pin to HC-SR04 		PORTD |= (1 << Trigger_pin);
		_delay_us(10);
		PORTD &= (~(1 << Trigger_pin));
		
		TCNT1 = 0;	 Clear Timer counter 		TCCR1B = 0x41;	 Capture on rising edge, No prescaler		TIFR = 1<<ICF1;	 Clear ICP flag (Input Capture flag) 		TIFR = 1<<TOV1;	 Clear Timer Overflow flag 
		Calculate width of Echo by Input Capture (ICP) 		
		while ((TIFR & (1 << ICF1)) == 0); Wait for rising edge 		TCNT1 = 0;	 Clear Timer counter 		TCCR1B = 0x01;	 Capture on falling edge, No prescaler 		TIFR = 1<<ICF1;	 Clear ICP flag (Input Capture flag) 		TIFR = 1<<TOV1;	 Clear Timer Overflow flag 		TimerOverflow = 0; Clear Timer overflow count 
		while ((TIFR & (1 << ICF1)) == 0); Wait for falling edge 		count = ICR1 + (65535 * TimerOverflow);	 Take count 		 8MHz Timer freq, sound speed =343 m/s 		distance = (double)count / 466.47;
LCD_ClrDisp();
LCD_SetPosition(1,1);
LCD_WriteNum(distance);
		_delay_ms(200);
	}
}*/