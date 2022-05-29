#ifndef AVR_INTERRUPT_H
#define AVR_INTERRUPT_H


#include <avr/interrupt.h>
#include "Pin_Math.h"
#include "Types.h"
#include "DIO_Reg.h"

void INT_Init(u8 INT , u8 Event );
void INT_EIE (u8 INT ,u8 State);//external interrupt enable






#define		HIGH	0xFF
#define		LOW		0x00	

#define		INT_GIE()	sei() // GIE enabled
#define		INT_GID()	cli() // GIE Disabled	




#define		LowLevel		0
#define		RisingEdge		1
#define		FallingEdge		2
#define		LogicalChange	4	


	





#endif // INTERRUPT_H
