#include "avr_interrupt.h"

void INT_Init(u8 INT , u8 Event )
{
	
	INT_GIE();//enable GIE
	
	
	
	switch (INT)
	{	
		case INT0 :
		
					Clr_Pin (Reg_DDRD,2);//input
					Set_Pin (Reg_PortD,2);//pull up
					Set_Pin (GICR,6); //enable PIE
					if (Event == LowLevel)
					{
						Clr_Pin(MCUCR,0);
						Clr_Pin(MCUCR,1);
					}
					else if (Event == RisingEdge)
					{	
						Set_Pin(MCUCR,0);
						Set_Pin(MCUCR,1);
			
					}
					else if (Event == LogicalChange)
					{
						Set_Pin(MCUCR,0);
						Clr_Pin(MCUCR,1);
					}
					else // fallingedge , once pressed
					{
						Clr_Pin(MCUCR,0);
						Set_Pin(MCUCR,1);
			
					}
		
		
	
		break;
		
		case INT1 :
		
					Clr_Pin (Reg_DDRD,3);//input
					Set_Pin (Reg_PortD,3);//pull up
					Set_Pin (GICR,7); //enable PIE
					if (Event == LowLevel)
					{
						Clr_Pin(MCUCR,2);
						Clr_Pin(MCUCR,3);
					}
					else if (Event == RisingEdge)
					{
						Set_Pin(MCUCR,2);
						Set_Pin(MCUCR,3);
						
					}
					else if (Event == LogicalChange)
					{
						Set_Pin(MCUCR,2);
						Clr_Pin(MCUCR,3);
					}
					else // fallingedge , once pressed
					{
						Clr_Pin(MCUCR,2);
						Set_Pin(MCUCR,3);
						
					}
					
		break;
		
		case INT2 :
							Clr_Pin (Reg_DDRB,2);//input
							Set_Pin (Reg_PortB,2);//pull up
							Set_Pin (GICR,5); //enable PIE

							if (Event == RisingEdge)
							{
								Set_Pin(MCUCSR,6);
								
								
							}

							else // fallingedge , once pressed
							{
								Clr_Pin(MCUCSR,6);
							
								
							}
							
							
							
							
		
		break;
		

		
	}
	
	
}

void INT_EIE (u8 INT ,u8 State)
{
	switch (INT)
	{
		case INT0 :
		if (State == HIGH)
		{
		Set_Pin (GICR,6);
		}
		else
		{
			Clr_Pin (GICR,6);	
		}
		
		break;
		
		case INT1 :
		
		
				if (State == HIGH)
				{
				   Set_Pin (GICR,7);
				}
				else
				{
					Clr_Pin (GICR,7);
				}
		
		break ;
		
		case INT2 :
		
						if (State == HIGH)
						{
							Set_Pin (GICR,5);
						}
						else
						{
							Clr_Pin (GICR,5);
						}
		
		break;
	}
	
}