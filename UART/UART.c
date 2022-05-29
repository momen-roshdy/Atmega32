#include "UART.h"

void UART_Init(void)
{
	/*default Initialization
	TX and RX are enabled 
	8 bit data without parity and with 1 stop bit
	Asynchronous
	9600 baud rate for 8MHZ clk
	*/
	UCSRB = (1<<TXEN) | (1<<RXEN);
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	UBRRL=0x33;
}

void UART_sendChar (u8 char)
{
	while (! (UCSRA & (1<<UDRE)));
	UDR=char;
}

void UART_sendStr (u8* str)
{	
	u8 i=0,j=0;
	while (while str[i]!= '/0' && i <=30)
	{
		i++;
	}
	for (j;j<i;j++)
	{
		UART_sendChar(str[j]);
	}
}