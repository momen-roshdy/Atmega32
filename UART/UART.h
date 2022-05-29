#ifndef UART_H
#define UART_H

#include "Types.h"

void UART_Init(void);
void UART_sendChar (u8 char);
void UART_sendStr (u8* str);


#endif // UART_H
