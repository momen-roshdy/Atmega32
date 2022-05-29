#include "DIO.h"




void DIO_PinMode       (u8 PinNumber , u8 Port ,u8 Direction )
{
     switch (Port)
    {
    case PortA :
        if (Direction == OUTPUT)
        {
            Set_Pin(Reg_DDRA,PinNumber);
        }

         else if (Direction == INPUT)
         {
              Clr_Pin(Reg_DDRA,PinNumber);
         }
         break ;

     case PortB :
        if (Direction == OUTPUT)
        {
            Set_Pin(Reg_DDRB,PinNumber);
        }

         else if (Direction == INPUT)
         {
              Clr_Pin(Reg_DDRB,PinNumber);
         }
         break ;

           case PortC :
        if (Direction == OUTPUT)
        {
            Set_Pin(Reg_DDRC,PinNumber);
        }

         else if (Direction == INPUT)
         {
              Clr_Pin(Reg_DDRC,PinNumber);
         }
         break ;

           case PortD :
        if (Direction == OUTPUT)
        {
            Set_Pin(Reg_DDRD,PinNumber);
        }

         else if (Direction == INPUT)
         {
              Clr_Pin(Reg_DDRD,PinNumber);
         }
         break ;

	}
    }
    //----------------------------------------PORT MODE ---------------------------------------------

    void DIO_PortMode        ( u8 Port ,u8 Direction )
{

         switch (Port)
    {
    case PortA :
       Reg_DDRA=Direction;
         break ;

     case PortB :
         Reg_DDRB=Direction;
         break ;

           case PortC :
           Reg_DDRC=Direction;
         break ;

           case PortD :
     if (Direction == OUTPUT)
        Reg_DDRD=Direction;
         break ;


    }

}
    //---------------------------------------Pin_Digital Mode--------------------------------

    void DIO_Pin_DigitalWrite        (u8 PinNumber , u8 Port ,u8 value )
    {
     switch (Port)
    {
    case PortA :
        if (value == HIGH)
        {
            Set_Pin(Reg_PortA,PinNumber);
        }

         else if (value == LOW)
         {
              Clr_Pin(Reg_PortA,PinNumber);
         }
         break ;

     case PortB :
    if (value == HIGH)
        {
            Set_Pin(Reg_PortB,PinNumber);
        }

         else if (value == LOW)
         {
              Clr_Pin(Reg_PortB,PinNumber);
         }
         break ;

           case PortC :
      if (value == HIGH)
        {
            Set_Pin(Reg_PortC,PinNumber);
        }

         else if (value == LOW)
         {
              Clr_Pin(Reg_PortC,PinNumber);
         }
         break ;

           case PortD :
        if (value == HIGH)
        {
            Set_Pin(Reg_PortD,PinNumber);
        }

         else if (value == LOW)
         {
              Clr_Pin(Reg_PortD,PinNumber);
         }
         break ;
    }

    }
    //-----------------------------------Port_DigitalWrite

    void DIO_Port_DigitalWrite        ( u8 Port ,u8 value )
      {
     switch (Port)
    {
    case PortA :
         Reg_PortA =value ;
         break ;

     case PortB :
       Reg_PortB =value ;
         break ;

           case PortC :
            Reg_PortC =value ;
         break ;

           case PortD :
         Reg_PortD =value ;
         break ;

    }
    }

    //-------------------------------Pin_DigitalRead------------------------------------------------------
    u8  DIO_Pin_DigitalRead    (u8 PinNumber , u8 Port)
   {


       if (Port == PortA)
       {

          return Read_Pin(Reg_PinA,PinNumber);
       }
       else if (Port == PortB)
        {

          return Read_Pin(Reg_PinB,PinNumber);
       }
        else if (Port == PortC)
        {

          return Read_Pin(Reg_PinC,PinNumber);
       }
        else
        {

          return Read_Pin(Reg_PinD,PinNumber);
       }

    }


    //-------------------------Port_DigitalRead
    u8   DIO_Port_DigitalRead    (u8 Port)
    {


       if (Port == PortA)
       {
          return Reg_PinA ;
       }
       else if (Port == PortB)
        {

          return Reg_PinB ;
       }
        else if (Port == PortC)
        {

          return Reg_PinC ;
       }
        else
        {
          return Reg_PinD ;

        }

    }
	
	void DIO_NibMode                 (u8 Nib, u8 Port ,u8 Direction ) 
	{   if (Nib)
		{
			Direction =Direction<<4;	
		}
		else
		{
			Direction &=0x0F;	
		}
		
		switch (Port)
		{	
			
			
			case PortA :
				if (Nib)
				{
					Reg_DDRA &=0x0F;					
				}
				else
				{
					Reg_DDRA &=0xF0;					
				}
				Reg_DDRA |=Direction;
				
				break;
			
			case PortB :
				if (Nib)
				{
					Reg_DDRB &=0x0F;
				}
				else
				{
					Reg_DDRB &=0xF0;
				}
				Reg_DDRB |=Direction;
				break;
			case PortC :
				if (Nib)
				{
					Reg_DDRC &=0x0F;
				}
				else
				{
					Reg_DDRC &=0xF0;
				}
				Reg_DDRC |=Direction;
				break;
			
			case PortD :
				if (Nib)
				{
					Reg_DDRD &=0x0F;
				}
				else
				{
					Reg_DDRD &=0xF0;
				}
				Reg_DDRD |=Direction;
				break;			
		}
	}
	void DIO_Nib_DigitalWrite        (u8 Nib, u8 Port ,u8 value )
		{  
			 if (Nib)
			 {
				 value=value<<4;
			 }
			 else
			 {
				 value &=0x0F;
			 }
			switch (Port)
			{
				case PortA :
				if (Nib)
				{
					Reg_PortA &=0x0F;
				}
				else
				{
					Reg_PortA &=0xF0;
				}
				Reg_PortA |=value;
				break;
				
				case PortB :
				
				if (Nib)
				{
					Reg_PortB &=0x0F;
				}
				else
				{
					Reg_PortB &=0xF0;
				}
				Reg_PortB |=value;
				break;
				case PortC :
				if (Nib)
				{
					Reg_PortC &=0x0F;
				}
				else
				{
					Reg_PortC &=0xF0;
				}
				Reg_PortC |=value;
				break;
				
				case PortD :
				if (Nib)
				{
					Reg_PortD &=0x0F;
				}
				else
				{
					Reg_PortD &=0xF0;
				}
				Reg_PortD |=value;
				break;
			}
		}
	
	u8  DIO_Nib_DigitalRead          (u8 Nib,u8 Port)
			{   u8 reading ;
				
				switch (Port)
				{
					case PortA :
					reading =Reg_PinA ;
					if (Nib)
					{
					return(reading>>4);	
				
					}
					else
					{	reading &=0x0F;
						return (reading);
					}

					break;
					
					case PortB :
					reading =Reg_PinB ;
					if (Nib)
					{
						return(reading>>4);
											
					}
					else
					{	reading &=0x0F;
						return (reading);
					}
					break;
					case PortC :
					reading =Reg_PinC;
					if (Nib)
					{
						return(reading>>4);
						
					}
					else
					{	reading &=0x0F;
						return (reading);
					}
					break;
					
					case PortD :
					reading =Reg_PinD ;
					if (Nib)
					{
						return(reading>>4);
						
					}
					else
					{	reading &=0x0F;
						return (reading);
					}
					break;
				}
				//return 0 ;
			}

