#include "ULTRASONIC.h"



static u8 Overflow_Counter =0 ;

void Ultrasonic_Init ( void)
{	
	
	LCD_Init(0);
	/*GPIO */
	DDRD |= (1<< Trig_pin); // Trig pin is output
	//DDRD &= (~ (1<<Echo_pin)); // Echo pin is input
	PORTD |= (1<< Echo_pin);
	/*Interrupt */
	sei(); //enable Global interrupt
	TIMSK = (1 << TOIE1);//Timer overflow interrupt enable 1
	
	
	/*Timer modes */
	TCCR1A = 0 ; // Normal Mode
	LCD_SetPosition(1,1);
	LCD_WriteStr("reading = ");
	
}

void Ultrasonic_Read ( void)
{	
	float  distance ;
	TCCR1B = 0x41 ; // No pre_scaler , Rising Edge
	PORTD |= (1<< Trig_pin);
	_delay_us(500) ;
	PORTD &=( ~(1<< Trig_pin));
	
	
	
	while (TIFR & (1<<ICF1)== 0) ;
	
	TCNT1 =0;  // clear timer counter --no problem in c
	TCCR1B = 0x01 ; // No pre_scaler , Falling edge
	TIFR |=(1<<ICF1); // clr input capture flag
	Overflow_Counter =0;
	
	while (TIFR & (1<<ICF1)== 0) ; // polling on input capture flag
	
	
	distance =ICR1 +Overflow_Counter*65535;
	distance = distance /466.47;
	LCD_SetPosition(2,1);
	LCD_WriteNum(distance);
	LCD_WriteStr(" cm");
	_delay_ms(500);
	TIFR |=(1<<ICF1); // clr input capture flag
}
/*
ISR (TIMER1_OVF_vect)
{	
	if ( (TCCR1B & 0x40 ) == 0x00 ) //if high and looking for Falling edge
	{
		Overflow_Counter ++ ;
	}
	
}

*/

