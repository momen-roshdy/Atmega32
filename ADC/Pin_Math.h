#ifndef PIN_MATH_H_INCLUDED
#define PIN_MATH_H_INCLUDED






#define Set_Pin( Var,PinNumber)        Var |= (1<<(PinNumber)) //void , call by address
#define Clr_Pin(Var,PinNumber)       Var &= ~(1<<(PinNumber)) //void , call by address
#define Toggle_Pin(Var,PinNumber)    Var ^= (1<<(PinNumber)) //void , call by address
#define Read_Pin(Var,PinNumber)     ((Var>>PinNumber) & 0x01) //return





#endif // PIN_MATH_H_INCLUDED
/* 
	use #define and put brackets ---> creating Macro function
	assigning to parameter , means that it's void calling by address
	running an operation , means that it's return function*/