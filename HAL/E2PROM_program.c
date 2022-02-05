#include "primitive_data_types.h"
#include "DIO_private.h"
uint8_t debug=7;

void EEPROM_VoidWriteDataByte(uint16_t Copy_U16LocationAddress,uint8_t Copy_U8Data)
{
	// start condition
	DDRB_REG =0xff;
	TWI_SendStartCondition();
	LCD_VoidDelay(10);
	TWI_SendSlaveAddressWithWrite(0b01010000);

	// this is the data
	  TWI_MstrSendDataByte(Copy_U16LocationAddress>>8);

	  TWI_MstrSendDataByte((uint8_t)Copy_U16LocationAddress);

	  TWI_MstrSendDataByte(Copy_U8Data);

	// stop codition
		TWI_SendStopCondition();

}
void EEPROM_VoidReadDataByte(uint16_t Copy_U16Address,uint8_t* Copy_U8Data)
{

	// start condition
	TWI_SendStartCondition();

	TWI_SendSlaveAddressWithWrite(0b01010000);

	TWI_MstrSendDataByte(Copy_U16Address>>8);
	TWI_MstrSendDataByte((uint8_t)Copy_U16Address);

	TWI_SendRepeatedStart();

	debug=	TWI_SendSlaveAddressWithRead(0b01010000 );
	  if(debug == 0)
	   {
		   PORTB_REG=0xFF;
	   }
	TWI_MstrReadDataByte(Copy_U8Data);

	// stop codition
	TWI_SendStopCondition();
}
