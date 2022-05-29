#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "DIO.h"
#include "lcd.h"


void calculator_Init(void);
void calculator(void);
int16_t calculator_Solve(void);
void Delete_ArrayElement (u8 element , int16_t * Array);


#endif // CALCULATOR_H
