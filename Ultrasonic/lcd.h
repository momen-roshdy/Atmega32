#ifndef LCD_H
#define LCD_H
#include "types.h"
#include <stdint-gcc.h> // m4 bya5od memory
void LCD_Init(u8 Eight_Bits);


void lcd_command (u8 command);

void LCD_WriteChar (u8 data);
void LCD_WriteStr (u8 * str);
void LCD_WriteNum (float data);

void LCD_Clk (void);

uint8_t StrLen(u8 * str);
int16_t NumToStr (int32_t num);


void LCD_FunctionSet (u8 NumLines , u8 Font);
void LCD_ClrDisp (void);
void LCD_EntryMode(u8 CursorDir,u8 DispShiftEn);
void LCD_DispCtrl (u8 Disp,u8 Curs ,u8 CursorBlink);
void LCD_ResetPos (void);
void LCD_Shift (u8 Dip_Cursor , u8 SHR);
void LCD_Set_CGR_Add (u8 address);
void LCD_SetPosition(u8 Row,u8 Col);
void LCD_ReadPosition(u8 * row , u8 * col);






#define	 ControlPort     PortC 
#define	 RS			     5
#define	 RW			     6
#define	 En			     7


#define DataPort		PortD
#define DataNib			LOW

#define En_us			1
#define FUNCTION_SET	( (1 << 5) | 0x1C )





#endif // LCD_H
