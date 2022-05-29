#ifndef AVR_ADC
#define AVR_ADC

#include <avr/io.h>
#include "Pin_Math.h"
#include "Types.h"
#include "ADC_Configure.h"


		

#define	ADC_StartConversion()		 Set_Pin(ADCSRA,ADSC)

void	ADC_Init (u8 VREF ,u8 Channel , u8 Prescalar , u8 Mode);


u16		ADC_Read (void);


void	ADC_ChannelSelect (u8 Channel);

u8 ADC_Flag (void);


#endif