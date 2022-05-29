#ifndef ADC_CONFIGURE
#define ADC_CONFIGURE





/**************** ADMUX REGISTER **********************************************/

/******* For VREF ******************/
#define		AREF			0x00
#define		AVCC			0x01
#define		Internal_VRef   0x03

/****** FOR ADLAR-WRITTEN in AVR IO--- ****/


/******** FOR CHANNEL *******/
/***** SINGLE INPUT ********/
#define ADC0	0x00
#define ADC1	0x01
#define ADC2	0x02
#define ADC3	0x03
#define ADC4	0x04
#define ADC5	0x05
#define ADC6	0x06
#define ADC7	0x07

/********* DIFF INPUT with GAIN *****/
#define		ADC00_Diff_Gain10		0x08
#define		ADC10_Diff_Gain10		0x09
#define		ADC22_Diff_Gain10		0x0C
#define		ADC32_Diff_Gain10		0x0D

#define		ADC00_Diff_Gain200		0x0A
#define		ADC10_Diff_Gain200		0x0B
#define		ADC22_Diff_Gain200		0x0E
#define		ADC32_Diff_Gain200		0x0F


/************ DIFF INPUT **********/
#define		ADC01		0x10
#define		ADC11		0x11
#define		ADC21		0x12
#define		ADC31		0x13
#define		ADC41		0x14
#define		ADC51		0x15
#define		ADC61		0x16
#define		ADC71		0x17
#define		ADC02		0x18
#define		ADC12		0x19
#define		ADC22		0x1A
#define		ADC32		0x1B
#define		ADC42		0x1C

/******************************************************************************************/


/*********** ADCSRA *********************************/
/* WRITTEN IN AVR IO *****\
#define ADEN	7
#define ADSC	6
#define ADATE	5
#define ADIF	4

/*/

#define ADC_CLK_2	0x01		
#define ADC_CLK_4	0x02
#define ADC_CLK_8	0x03
#define ADC_CLK_16	0x04
#define ADC_CLK_32	0x05
#define ADC_CLK_64	0x06
#define ADC_CLK_128	0x07


/***************** SFIOR FOR TRIGGER SELECT   ********************/
#define		ADC_FreeRunning		(0x00<<5)
#define		ADC_AnalogComp		(0x01<<5)
#define		ADC_INT0			(0x02<<5)
#define		ADC_Timer0_OCM		(0x03<<5)
#define		ADC_Timer0_Overflow	(0x04<<5)
#define		ADC_Timer1_OCM		(0x05<<5)
#define		ADC_Timer1_Overflow	(0x06<<5)
#define		ADC_Timer1_Capture	(0x07<<5)








#endif