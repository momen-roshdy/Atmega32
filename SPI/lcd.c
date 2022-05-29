
#define F_CPU 16000000UL
#include <util/delay.h>
#include "DIO.h"
#include "lcd.h"


///////////////////////////////////////////////////////////////////////////////////////////////'.


int8_t LCD_8Bits_Flag = 0;
///////////////////////////////////////////////////////////////////////////////////////////////
void LCD_Clk (void)
{
	DIO_Pin_DigitalWrite(En,ControlPort,HIGH);
	_delay_us(En_us);
	DIO_Pin_DigitalWrite(En,ControlPort,LOW);
	_delay_us(En_us);
	DIO_Pin_DigitalWrite(En,ControlPort,HIGH);
}
///////////////////////////////////////////////////////////////////////////////////////////////

void LCD_Command (u8 command)
{
	DIO_Pin_DigitalWrite(RS,ControlPort,LOW);
	DIO_Pin_DigitalWrite(RW,ControlPort,LOW);
	
	if (LCD_8Bits_Flag !=0)
	{
		DIO_PortMode(DataPort,0xFF);//output
		DIO_Port_DigitalWrite(DataPort,command);
		LCD_Clk();
	}
	else
	{
		
		DIO_NibMode(DataNib,DataPort,0x0F);//output
		DIO_Nib_DigitalWrite(DataNib,DataPort,command>>4);
		LCD_Clk();
		DIO_Nib_DigitalWrite(DataNib,DataPort,command);
		LCD_Clk();
		
	}
}
	//////////////////////////////////////////////////////////////////////////////////////////////
	// LCD_SendChar ('0'); u send the ASCII
	void LCD_WriteChar (u8 data)
	{
		DIO_Pin_DigitalWrite(RS,ControlPort,HIGH);
		DIO_Pin_DigitalWrite(RW,ControlPort,LOW);
		if (LCD_8Bits_Flag != 0)
		{
			DIO_PortMode(DataPort,0xFF);
			DIO_Port_DigitalWrite(DataPort,data);
			LCD_Clk ( );
			
		}
		else
		{
			DIO_NibMode(DataNib,DataPort,0x0F);
			DIO_Nib_DigitalWrite(DataNib,DataPort,data>>4);
			LCD_Clk ( );
			DIO_Nib_DigitalWrite(DataNib,DataPort,data);
			LCD_Clk ( );
		}

		_delay_us(50);
	}

	//////////////////////////////////////////////////////////////////////////////////////////////
	uint8_t StrLen(u8* str)
	{	uint8_t num =0;
		uint8_t* ptr =str ;
		
		while(*ptr !='\0')
		{	ptr++;
			num++;
		}
		return num ;
	}



	void LCD_WriteStr (u8* str)
	{
		DIO_Pin_DigitalWrite(RS,ControlPort,HIGH);
		DIO_Pin_DigitalWrite(RW,ControlPort,LOW);
		
		int8_t i =0;
		//for (i; i<StrLen(str)) kda kol mra hy7sb mn awl w gded ,, w el value hyt8yr kol mra
		uint8_t num=StrLen(str);
		for (i;i<num;i++)
		{
			LCD_WriteChar(str[i]);
		}
	}
	///////////////////////////////////////////////////////////////////////////////////////////

	int8_t LCD_Str[32]={0};

	int16_t NumToStr (int32_t num)
	{	u8 neg_flag =0;
		if(num <0)
		{	neg_flag=1;
			num*=-1;
		}
		int16_t NumDigits =0 ;
		int32_t temp =num;
		if (num ==0)
		{	LCD_Str[0]='0';
			LCD_Str[1]='\0';
			return 1;
		}
		// num of digits
		while (temp != 0)
		{
			temp/=10 ;
			NumDigits ++;
		}
		if (neg_flag)
		{
			LCD_Str[NumDigits+1]='\0';
			LCD_Str[NumDigits]='-';
			LCD_WriteChar(LCD_Str[NumDigits]);
		}
		else
		{
			LCD_Str[NumDigits]='\0';
		}
		
		
		int16_t i =NumDigits-1;
		for (i; i>=0; i--)
		{
			LCD_Str[i]=(num%10) +'0' ;
			num/=10;
		}
		return NumDigits;
	}

	void LCD_WriteNum(float data)
	{	
		int32_t temp =data;
		int16_t NumDigits=NumToStr(temp);
		int8_t i =0;
		for (i ; i<NumDigits; i++)
		{
			LCD_WriteChar(LCD_Str[i]);
		}
		LCD_WriteChar('.');
		data =data-temp;
		data*=10000;
		if(data < 0)
		{
			data *=-1;
		}
		temp =data;
		if (temp ==0)
		{
			LCD_WriteChar('0');
		}
		else
		{
			
		
		NumDigits=NumToStr(temp);
		i =0;
		for (i ; i<NumDigits; i++)
		{
			LCD_WriteChar(LCD_Str[i]);
		}
		}
		
	}

	///////////////////////////////////////////////////////////////////////////////


	void LCD_Init(u8 Eight_Bits)
	{
		DIO_PinMode(RS,ControlPort,OUTPUT);
		DIO_PinMode(RW,ControlPort,OUTPUT);
		DIO_PinMode(En,ControlPort,OUTPUT);
		
		LCD_8Bits_Flag =Eight_Bits;
		if (LCD_8Bits_Flag != 0)
		{
			DIO_PortMode(DataPort,0xFF);
		}
		else
		{
			DIO_NibMode(DataNib,DataPort,0x0F);
		}

		_delay_ms(50);
		LCD_FunctionSet (HIGH, HIGH);
		LCD_DispCtrl (HIGH,LOW ,LOW);
		LCD_ClrDisp ();
		LCD_EntryMode(HIGH,LOW);
		
	}


	void LCD_FunctionSet (u8 NumLines , u8 Font)//sets 8bits ,num of lines , font
	{	if (LCD_8Bits_Flag !=0)
		{
			LCD_Command((0x03<<4)|(NumLines<<3)|(Font<<2));
		}
		else
		{
			LCD_Command(0x02);//not mistake , it's important
			LCD_Command((0x02<<4)|(NumLines<<3)|(Font<<2));
			
		}
		
		_delay_us(50);
	}
	void LCD_ClrDisp (void) //clear the screen
	{
		LCD_Command(0x01);
		_delay_ms(2);
	}

	void LCD_EntryMode(u8 CursorDir,u8 DispShiftEn) //cursor dir,and disp shift
	{
		LCD_Command((0x01<<2)|(CursorDir <<1)|(DispShiftEn));
		_delay_us(50);
	}

	void LCD_DispCtrl (u8 Disp,u8 Curs ,u8 CursorBlink) // disp on/off ,, cursor on/off,,blink on/off
	{
		LCD_Command((0x01 <<3)|(Disp<<2)|(Curs<<1)|(CursorBlink));
		_delay_us(50);
	}

	void LCD_ResetPos (void)
	{
		LCD_Command(0x02);
		_delay_ms(2);
	}
	void LCD_Shift (u8 Dip_Cursor , u8 SHR)
	{
		LCD_Command((0x01<<4)|(Dip_Cursor<<3)|(SHR<<2));
		_delay_us(50);
	}
	void LCD_Set_CGR_Add (u8 address)
	{	address &=0b01111111;
		address |=0b01000000;
		LCD_Command(address);
		_delay_us(50);
	}
	void LCD_SetPosition(u8 Row,u8 Col)
	{
		if (Row ==1)
		{
			LCD_Command(0x80+(Col-1));
		}
		else
		{
			LCD_Command(0x80+0x40+(Col-1));
		}
		_delay_us(50);
	}

	void LCD_ReadPosition(u8 * row ,u8 * col)
	{	u8 Reading;
		
		DIO_Pin_DigitalWrite(RS,ControlPort,HIGH);
		DIO_Pin_DigitalWrite(RW,ControlPort,HIGH);
		if (LCD_8Bits_Flag != 0)
		{
			DIO_PortMode(DataPort,0x00);//input
			
			//reading at falling Edge
			DIO_Pin_DigitalWrite(En,ControlPort,HIGH);
			_delay_us(En_us);
			Reading=DIO_Port_DigitalRead(DataPort);
			DIO_Pin_DigitalWrite(En,ControlPort,LOW);
			_delay_us(En_us);
			

		}
		else
		{
			DIO_NibMode(DataNib,DataPort,0x00);//input
			
			DIO_Pin_DigitalWrite(En,ControlPort,HIGH);
			_delay_us(En_us);
			Reading=DIO_Nib_DigitalRead(DataNib,DataPort);
			Reading=Reading<<4;
			DIO_Pin_DigitalWrite(En,ControlPort,LOW);
			_delay_us(En_us);
			
			DIO_Pin_DigitalWrite(En,ControlPort,HIGH);
			_delay_us(En_us);
			Reading |=(DIO_Nib_DigitalRead(DataNib,DataPort));
			DIO_Pin_DigitalWrite(En,ControlPort,LOW);
			_delay_us(En_us);
			
			
		}
		//clear BF
		Reading &= 0x80;
		
		if (Reading <=(0x80| 0x40))
		{	* row =1;
			* col = Reading-0x80+1;
		}
		else
		{
			* row =2;
			* col=Reading - 0x80-0x40+1;
		}

		
		_delay_us(50);
		
	}


	///////////////////////////////////////////////////////////////////
