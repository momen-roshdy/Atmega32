#ifndef PIN_MATH_H_INCLUDED
#define PIN_MATH_H_INCLUDED






#define Set_Pin( Var,PinNumber)        Var |= (1<<(PinNumber)) //void , call by address
#define Clr_Pin(Var,PinNumber)       Var &= ~(1<<(PinNumber)) //void , call by address
#define Toggle_Pin(Var,PinNumber)    Var ^= (1<<(PinNumber)) //void , call by address
#define Read_Pin(Var,PinNumber)     ((Var>>PinNumber) & 0x01) //return





#endif // PIN_MATH_H_INCLUDED
