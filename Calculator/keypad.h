#ifndef KEYPAD_H
#define KEYPAD_H
#include "DIO.h"
#define F_CPU 16000000UL
#include <util/delay.h>

void Keypad_Init (void);

u8	Keypad_ReadButton (void);


//
u8 Button_PullUp_Read (u8 PinNumber,u8 Port );
#define Debounce_time_ms 20


#define keypad_rows	4
#define Keypad_cols 4


#ifndef Keypad_Port
#define Keypad_Port PortA
#endif





#endif // KEYPAD_H
