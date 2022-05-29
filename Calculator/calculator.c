#include "calculator.h"

int16_t calculator_array[16]={0};//must be big as int16_t
u8 Calculator_OperatorFlag =0;
void calculator_Init()
{	
	LCD_Init(LOW);
	Keypad_Init(PortA);
		
}


void calculator()
{	calculator_array[0]='\0';
	
	int16_t Answer =0;	
	u8 reading ='\0';
		reading = Keypad_ReadButton();
		static u8 i =0 ;
		if (reading != '\0')
		{
			
			//storing the number
			if (reading <= '9' && reading >='0')
			{	
				LCD_WriteChar(reading);
				Calculator_OperatorFlag =0;
				reading =reading-'0';//from char to Num
				calculator_array[i]=calculator_array[i]*10 +reading;
				i++;
			}
			else if (reading == '=')
			{	if (Calculator_OperatorFlag == '0')
				{	//ending the array
					i++;
					calculator_array[i]='\0';
					Calculator_OperatorFlag =0;
					//Solve
					LCD_SetPosition(2,1);
					Answer=calculator_Solve();
					LCD_WriteNum(Answer);
					
				}
			}
			else if (reading == 'C')
			{	Answer = 0;
				calculator_array[0]='\0';//must be big as int16_t
				Calculator_OperatorFlag =0;
				LCD_ClrDisp();
				i=0;
				LCD_SetPosition(1,1);
			}
			else//mathematical operation
			{	//preventing two consecutive operations or starting with Mul or div operators
				if (Calculator_OperatorFlag == '0')
				{	
					if( ( reading == '*' || reading == '/') && i == 0 )
					{
						
					}
					else// operators 
					{
						Calculator_OperatorFlag =1;
						LCD_WriteChar(reading);	
						i++;
						calculator_array[i]=reading;
						i++;
					}
				}
					
			}
			
		}
}

int16_t calculator_Solve()
{	
	u8 i =0;
	int16_t answer =0;
	
	//asigning negative to numbers
	
	//deleting element
	
	//searching for priority operators
	for (i; i<16; i++)
	{	//checking before the end
		while (calculator_array[i] != '\0' )// 3ady ykon int16 w t3ml check 3la char dh implicit casting
		{	
			if (calculator_array[i] =='*'  )
			{
				answer +=calculator_array[i-1]*calculator_array[i+1]; 
				//deleting elements
				Delete_ArrayElement (i-1 , calculator_array);
				Delete_ArrayElement (i-1 , calculator_array);
				Delete_ArrayElement (i-1 , calculator_array);
				
			}
			else if (calculator_array[i] =='/'  )
			{
				answer +=calculator_array[i-1]/calculator_array[i+1];	
				//deleting elements
				
				Delete_ArrayElement (i-1 , calculator_array);
				Delete_ArrayElement (i-1 , calculator_array);
				Delete_ArrayElement (i-1 , calculator_array);				
			}
		}
		i++;
		
	}
	
		//addition and subtraction
		i==0;
		for (i; i<16; i++)
		{	//checking before the end
			while (calculator_array[i] != '\0' )// 3ady ykon int16 w t3ml check 3la char dh implicit casting
			{
				if (calculator_array[i] =='+'  )
				{
					answer +=calculator_array[i-1]+calculator_array[i+1];
					//deleting elements
					Delete_ArrayElement (i-1 , calculator_array);
					Delete_ArrayElement (i-1 , calculator_array);
					Delete_ArrayElement (i-1 , calculator_array);
					
				}
				else if (calculator_array[i] =='-'  )
				{	
					//starts with negative
					if(i == 0)
					{
						Delete_ArrayElement (i , calculator_array);
						calculator_array[i] *= -1 ;
					}
					answer +=calculator_array[i-1]-calculator_array[i+1];
					//deleting elements
					
					Delete_ArrayElement (i-1 , calculator_array);
					Delete_ArrayElement (i-1 , calculator_array);
					Delete_ArrayElement (i-1 , calculator_array);
				}
			}
			i++;
			
		}
	
	return answer;
	
}

void Delete_ArrayElement (u8 element , int16_t * Array)
{ 
	u8 i = element;
	while (Array[i+1] != '\0')
	{
		Array[i]=Array[i+1];
		i++;
	}
	Array[i]=Array[i+1];
	
}