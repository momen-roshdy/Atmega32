/*
 * SPI.h
 *
 * Created: 4/18/2021 9:35:24 PM
 *  Author: lenovo
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>

void SPI_MasterInit(void );
void SPI_SlaveInit(void) ;
void SPI_SendChar (char data) ;
char SPI_ReadChar (void);
void SPI_SendStr (const char *str);
SPI_ReadStr (char * str, unsigned char str_size);


#define MISO	6
#define MOSI	5
#define SS		4
#define SCK		7


#endif /* SPI_H_ */