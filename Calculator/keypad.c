#include "keypad.h"
#include "lcd.h"
 
u8 Keypad_Array[keypad_rows][Keypad_cols]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'C','0','=','+'}};


void Keypad_Init ()
{   
	
	//setting rows as inputs with internal pull ups
	DIO_NibMode(LOW,Keypad_Port,INPUT);
	DIO_Nib_DigitalWrite(LOW,Keypad_Port,HIGH);
	
	// setting columns as outputs with 5V (non functional push buttons)
	DIO_NibMode(HIGH,Keypad_Port,OUTPUT);
	DIO_Nib_DigitalWrite(HIGH,Keypad_Port,HIGH);
	
}

/* I can't use current and previous readings here cuz it's checking
different buttons */
u8	Keypad_ReadButton (void)
{	
	u8 reading=HIGH;
	
	volatile u8 j =4;
	for(j;j<8;j++)
	{	//activating col j buttons
		DIO_Pin_DigitalWrite(j,Keypad_Port,LOW);
		
			
		volatile u8 i =0;//error :don't declare it before the first loop
		//reading col i buttons
		for (i;i<keypad_rows;i++)
		{
			reading=DIO_Pin_DigitalRead(i,Keypad_Port);
			if (reading ==0)
			{
				while (reading==0)
				{
					_delay_ms(Debounce_time_ms);
					reading=DIO_Pin_DigitalRead(i,Keypad_Port);//error :u forgot to write that 
					//LCD_SetPosition(1,8);//position set for real reading
				}
				if(i==3 && (j-4)==0)
				{	static u8 temp =HIGH;
					temp=~temp;
					LCD_DispCtrl(~temp,LOW,LOW);//light's on but without showing any info
					
				}
				else
				{
					
				
				return Keypad_Array[i][j-4];//error : j-4
				}
			}
			
		}
		
		DIO_Pin_DigitalWrite(j,Keypad_Port,HIGH);//error:u must return it as it's
		
	}
	//to prevent garbage return
	//return 'c' ; error : after returning the real reading this replaced it 
	//LCD_SetPosition(1,1);//position set for fake reading to prevent real reading replacement
	return '\0';
}

//