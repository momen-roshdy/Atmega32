#include "AVR_ADC.h"
void ADC_Init (u8 VREF ,u8 Channel , u8 Prescalar , u8 Mode)
{	
	
	/******** FIRST DEALING WITH ADMUX ********/
	
	ADMUX &= 0x00;/* Any way initial value is zeroos */
	
	switch (VREF)
	{
		case AVCC :
			ADMUX |= (AVCC<<6);
			break;
			
		case Internal_VRef :
			ADMUX |= (Internal_VRef <<6);
			break;
			/* No need for AREF */		
	}
	
	
	/**** For ADLAR ***/
	
	Set_Pin(ADMUX,ADLAR) ;
	/*** Channel Selection ***/
	switch (Channel)
	{
		case ADC0 :
			ADMUX |= ADC0 ;
			Clr_Pin (DDRA,0);
			break;
		
		case ADC1 :
		Clr_Pin (DDRA,1);
		ADMUX |= ADC1 ;
		break;
		
		case ADC2 :
		Clr_Pin (DDRA,2);
		ADMUX |= ADC2 ;
		break;
		
		case ADC3 :
		Clr_Pin (DDRA,3);
		ADMUX |= ADC3 ;
		break;
		
		case ADC4 :
		Clr_Pin (DDRA,4);
		ADMUX |= ADC4 ;
		break;
		
		case ADC5 :
		Clr_Pin (DDRA,5);
		ADMUX |= ADC5;
		break;
		
		case ADC6 :
		Clr_Pin (DDRA,6);
		ADMUX |= ADC6 ;
		break;
		
		case ADC7 :
		Clr_Pin (DDRA,7);
		ADMUX |= ADC7;
		break;	
		
		
		
		
		case ADC00_Diff_Gain10	:
		Clr_Pin (DDRA,0);
			ADMUX |= ADC00_Diff_Gain10 ;
			break ;
		
		
		case	ADC10_Diff_Gain10	:
		Clr_Pin (DDRA,0);
		Clr_Pin (DDRA,1);
		ADMUX |= ADC10_Diff_Gain10 ;
		break;
		
		
		
		
/*******************************************************/		
		
		case	ADC22_Diff_Gain10:
		Clr_Pin (DDRA,2);
			ADMUX |= ADC22_Diff_Gain10 ;
			break;
			
		case	ADC32_Diff_Gain10	:
		Clr_Pin (DDRA,2);
		Clr_Pin (DDRA,3);
		ADMUX |= ADC32_Diff_Gain10 ;
		break;
		
		
		case	ADC00_Diff_Gain200	:
		Clr_Pin (DDRA,0);
		ADMUX |= ADC00_Diff_Gain200 ;
		break;
		
		
		case	ADC10_Diff_Gain200:
		Clr_Pin (DDRA,0);
		Clr_Pin (DDRA,1);
		ADMUX |= ADC10_Diff_Gain200 ;
		break;
		
		
		case	ADC22_Diff_Gain200:
		Clr_Pin (DDRA,2);
		ADMUX |= ADC22_Diff_Gain200 ;
		break;
		
		
		case	ADC32_Diff_Gain200:
		Clr_Pin (DDRA,3);
		Clr_Pin (DDRA,2);
		ADMUX |=  ADC32_Diff_Gain200;
		break;
		
/*********************************************************/		
		case	ADC42	:
		Clr_Pin (DDRA,4);
		Clr_Pin (DDRA,2);
		ADMUX |=	ADC42 ;
		break;	
		
		case	ADC32:
		Clr_Pin (DDRA,3);
		Clr_Pin (DDRA,2);
		ADMUX |= ADC32 ;
		break;
		
		
		case	ADC22:
		Clr_Pin (DDRA,2);
		ADMUX |= ADC22 ;
		break;
		
		case	ADC12 :
		Clr_Pin (DDRA,2);
		Clr_Pin (DDRA,1);
		ADMUX |=  ADC12;
		break;
		
		case	ADC02:
		Clr_Pin (DDRA,0);
		Clr_Pin (DDRA,2);
		ADMUX |=  ADC02;
		break;
		
		case	ADC71	:
		Clr_Pin (DDRA,7);
		Clr_Pin (DDRA,1);
		ADMUX |= ADC71 ;
		break;
		
		case	ADC61	:
		Clr_Pin (DDRA,6);
		Clr_Pin (DDRA,1);
		ADMUX |= ADC61 ;
		break;
		
		case	ADC51:
		Clr_Pin (DDRA,5);
		Clr_Pin (DDRA,1);
		ADMUX |= ADC51 ;
		break;
		
		case	ADC41:
		Clr_Pin (DDRA,4);
		Clr_Pin (DDRA,1);
		ADMUX |=  ADC41;
		break;
		
		case	ADC31:
		Clr_Pin (DDRA,3);
		Clr_Pin (DDRA,1);
		ADMUX |= ADC31 ;
		break;
		
		case	ADC21:
		Clr_Pin (DDRA,2);
		Clr_Pin (DDRA,1);
		ADMUX |=  ADC21;
		break;
		
		case	ADC11:
		Clr_Pin (DDRA,1);
		ADMUX |= ADC11 ;
		break;
		
		case	ADC01	:
		Clr_Pin (DDRA,0);
		Clr_Pin (DDRA,1);
		ADMUX |= ADC01 ;
		break;		
				 
	}
	
/*********** DEALING WITH ADSCRA *************/
ADCSRA	&=0x00 ;/* Any way initial value is zeroos */


	/*ENABLING THE ADC */
	
	
	Set_Pin(ADCSRA,ADEN) ;
	
	switch (Prescalar)
	{
		case ADC_CLK_2 :
		ADCSRA |= ADC_CLK_2 ;
		break ;
			
		case  ADC_CLK_4:
		ADCSRA |=  ADC_CLK_4;
		break;
		
		
		case ADC_CLK_8 :
		ADCSRA |= ADC_CLK_8 ;
		break;
		
		case  ADC_CLK_16:
		ADCSRA |= ADC_CLK_16 ;
		break;
		
		case	ADC_CLK_32  :
		ADCSRA |= ADC_CLK_32 ;
		break;
		
		case  ADC_CLK_64:
		ADCSRA |= ADC_CLK_64 ;
		break;
		
		case  ADC_CLK_128:
		ADCSRA |= ADC_CLK_128 ;
		break;
		
			
	}
	
	
	switch (Mode)
	{
		case ADC_FreeRunning :
			Set_Pin(ADCSRA,ADATE) ;
			SFIOR	|=ADC_FreeRunning ;
			break ;
			
		case ADC_AnalogComp :
		Set_Pin(ADCSRA,ADATE) ;
		SFIOR	|= ADC_AnalogComp;
		break ;	
		
		case ADC_INT0 :
		Set_Pin(ADCSRA,ADIE) ;
		Set_Pin(ADCSRA,ADATE) ;
		SFIOR	|= ADC_INT0;
		break ;
		
		
		case  ADC_Timer0_OCM:
		Set_Pin(ADCSRA,ADATE) ;
		SFIOR	|= ADC_Timer0_OCM;
		break ;
		
		
		
		case ADC_Timer0_Overflow :
		Set_Pin(ADCSRA,ADATE) ;
		SFIOR	|=ADC_Timer0_Overflow ;
		break ;
		
		case  ADC_Timer1_OCM:
		Set_Pin(ADCSRA,ADATE) ;
		SFIOR	|= ADC_Timer1_OCM;
		break ;
		
		case ADC_Timer1_Overflow :
		Set_Pin(ADCSRA,ADATE) ;
		SFIOR	|= ADC_Timer1_Overflow;
		break ;
		
			
		case  ADC_Timer1_Capture:
		Set_Pin(ADCSRA,ADATE) ;
		SFIOR	|=ADC_Timer1_Capture ;
		break ;	
		
		case ADSC :
		Set_Pin(ADCSRA,ADSC);
		break ;
	
			
	}
		
}


void	ADC_ChannelSelect (u8 Channel)
{
	ADMUX &=0b11100000;
	/*** Channel Selection ***/
	switch (Channel)
	{
		case ADC0 :
		ADMUX |= ADC0 ;
		break;
		
		case ADC1 :
		ADMUX |= ADC1 ;
		break;
		
		case ADC2 :
		ADMUX |= ADC2 ;
		break;
		
		case ADC3 :
		ADMUX |= ADC3 ;
		break;
		
		case ADC4 :
		ADMUX |= ADC4 ;
		break;
		
		case ADC5 :
		ADMUX |= ADC5;
		break;
		
		case ADC6 :
		ADMUX |= ADC6 ;
		break;
		
		case ADC7 :
		ADMUX |= ADC7;
		break;
		
		
		
		
		case ADC00_Diff_Gain10	:
		ADMUX |= ADC00_Diff_Gain10 ;
		break ;
		
		
		case	ADC10_Diff_Gain10	:
		ADMUX |= ADC10_Diff_Gain10 ;
		break;
		
		
		
		
		/*******************************************************/
		
		case	ADC22_Diff_Gain10:
		ADMUX |= ADC22_Diff_Gain10 ;
		break;
		
		case	ADC32_Diff_Gain10	:
		ADMUX |= ADC32_Diff_Gain10 ;
		break;
		
		
		case	ADC00_Diff_Gain200	:
		ADMUX |= ADC00_Diff_Gain200 ;
		break;
		
		
		case	ADC10_Diff_Gain200:
		ADMUX |= ADC10_Diff_Gain200 ;
		break;
		
		
		case	ADC22_Diff_Gain200:
		ADMUX |= ADC22_Diff_Gain200 ;
		break;
		
		
		case	ADC32_Diff_Gain200:
		ADMUX |=  ADC32_Diff_Gain200;
		break;
		
		/*********************************************************/
		case	ADC42	:
		ADMUX |=	ADC42 ;
		break;
		
		case	ADC32:
		ADMUX |= ADC32 ;
		break;
		
		
		case	ADC22:
		ADMUX |= ADC22 ;
		break;
		
		case	ADC12 :
		ADMUX |=  ADC12;
		break;
		
		case	ADC02:
		ADMUX |=  ADC02;
		break;
		
		case	ADC71	:
		ADMUX |= ADC71 ;
		break;
		
		case	ADC61	:
		ADMUX |= ADC61 ;
		break;
		
		case	ADC51:
		ADMUX |= ADC51 ;
		break;
		
		case	ADC41:
		ADMUX |=  ADC41;
		break;
		
		case	ADC31:
		ADMUX |= ADC31 ;
		break;
		
		case	ADC21:
		ADMUX |=  ADC21;
		break;
		
		case	ADC11:
		ADMUX |= ADC11 ;
		break;
		
		case	ADC01	:
		ADMUX |= ADC01 ;
		break;
		
	}
}


u16		ADC_Read (void)
{

/* LAZM T2ra el ADCL al awl , b3d kda ADCH
	b3d keda hybtdy y48l el counter tany 
	aw momken t2ra el ADCH bs b3d kda hy48l 
	el counter ...
	lw ktbt el ADCH el awl b3d keda el ADCL 
	m4 hy2ra .. */	
	if (Read_Pin (ADMUX ,ADLAR) )
	{
		return ((ADCL>>6)| (ADCH<<2)  );
	}
	else
	{
		return (   (ADCL)| ( (ADCH & 0x03) <<8) );
	}
}


		
u8 ADC_Flag (void)
		
{
	return ( (ADCSRA >>ADIF) & 0x01)  ;
}
