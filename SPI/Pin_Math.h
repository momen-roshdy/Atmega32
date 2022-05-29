#ifndef PIN_MATH_H_INCLUDED
#define PIN_MATH_H_INCLUDED






#define Set_Pin( Port,PinNumber)        Port |= (1<<(PinNumber)) //void , call by address
#define Clr_Pin(Port,PinNumber)       Port &= ~(1<<(PinNumber)) //void , call by address
#define Toggle_Pin(Port,PinNumber)    Port ^= (1<<(PinNumber)) //void , call by address
#define Read_Pin(Port,PinNumber)     ((Port>>PinNumber) & 0x01) //return







#endif // PIN_MATH_H_INCLUDED
