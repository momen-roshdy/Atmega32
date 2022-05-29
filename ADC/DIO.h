#ifndef DIO_H
#define DIO_H

#include "Pin_Math.h"
#include "DIO_Reg.h"
#include "Types.h"


#define PortA 0
#define PortB 1
#define PortC 2
#define PortD 3

#define OUTPUT 0xFF
#define INPUT  0x00

#define HIGH 0xFF
#define LOW 0x00

void DIO_PinMode                 (u8 PinNumber , u8 Port ,u8 Direction ) ;
void DIO_Pin_DigitalWrite        (u8 PinNumber , u8 Port ,u8 value );
u8   DIO_Pin_DigitalRead    (u8 PinNumber , u8 Port);

void DIO_PortMode                 ( u8 Port ,u8 Direction ) ;
void DIO_Port_DigitalWrite        ( u8 Port ,u8 value );
u8  DIO_Port_DigitalRead          (u8 Port);

void DIO_NibMode                 (u8 Nib, u8 Port ,u8 Direction ) ;
void DIO_Nib_DigitalWrite        (u8 Nib, u8 Port ,u8 value );
u8  DIO_Nib_DigitalRead          (u8 Nib,u8 Port);








#endif // DIO_H
