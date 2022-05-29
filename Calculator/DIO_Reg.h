#ifndef DIO_REG_H
#define DIO_REG_H
#include "Types.h"

#define Reg_PortA     *((volatile u8* ) 0x3B)
#define Reg_DDRA      *((volatile u8* ) 0x3A)
#define Reg_PinA      *( (volatile u8* ) 0x39)

#define Reg_PortB    *( (volatile  u8* ) 0x38)
#define Reg_DDRB      *( ( volatile  u8* ) 0x37)
#define Reg_PinB       *( (volatile u8* ) 0x36)

#define Reg_PortC      *((volatile u8* ) 0x35)
#define Reg_DDRC     *( (volatile u8* ) 0x34)
#define Reg_PinC      *( (volatile u8* ) 0x33)

#define Reg_PortD      *((volatile  u8* ) 0x32)
#define Reg_DDRD     *((volatile u8* ) 0x31)
#define Reg_PinD       *((volatile  u8* ) 0x30)




#endif // DIO_REG_H
