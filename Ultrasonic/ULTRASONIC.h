#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Types.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "lcd.h"

void Ultrasonic_Init ( void);
void Ultrasonic_Read ( void);





#define Trig_pin	 5
#define Echo_pin	 6


#endif