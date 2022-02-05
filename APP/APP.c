/*
 * APP.c
 *
 *  Created on: Jan 29, 2022
 *      Author: abdalah
 */

#include "primitive_data_types.h"
#include "DIO_interface.h"
#include "E2PROM_interface.h"
#include "LCD_interface.h"
#include "TWI_interface.h"
int main()
{

	LCD_VoidInit4b();
   USART_VoidInit(PORTD,PIN1,PIN0);

	TWI_voidMasterInit();
while(1)
{
	uint8_t Copy_U8state[6] ="";
	uint8_t Copy_U8addres[9] ="";
	uint8_t  DATA=0;
	uint8_t Read_data=0;

	UART_U8ReciveBufferSyn(Copy_U8state,5);

	if(Copy_U8state[0] == 'w' &&
	   Copy_U8state[1] == 'r' &&
	   Copy_U8state[2] == 'i' &&
	   Copy_U8state[3] == 't' &&
	   Copy_U8state[4] == 'e'
                                  )
    {
		UART_U8ReciveBufferSyn(Copy_U8addres,8);
		   /*convert from char to int*/
		uint8_t x=0;
		uint8_t counter =1;
		uint8_t res=0;
		uint8_t i=0;
		while(Copy_U8addres[i]!='\0')
		{
			res=Copy_U8addres[7-i]-48;    //
			x+=res*counter;
			counter*=2;
			i++;
		}
        UART_U8GetData(&DATA);

		EEPROM_VoidWriteDataByte(x,DATA);
		UART_U8SendBufferSyn("OK",2);
	}
	else if(Copy_U8state[0] == 'r' &&
	        Copy_U8state[1] == 'e' &&
	        Copy_U8state[2] == 'a' &&
	        Copy_U8state[3] == 'd'
                                  )
	{
		UART_U8ReciveBufferSyn(Copy_U8addres,8);
		uint8_t x=0;
		uint8_t counter =1;
		uint8_t res=0;
		uint8_t i=0;
		while(Copy_U8addres[i]!='\0')
		{
			res=Copy_U8addres[7-i]-48;    //
			x+=res*counter;
			counter*=2;
			i++;
		}

		EEPROM_VoidReadDataByte(x ,&Read_data);
		UART_U8_SendData(&Read_data);
	}



	LCD_WriteData4b(Read_data+48);

	}
return 0;

}
