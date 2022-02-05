/*
 * E2prom_interface.h
 *
 *  Created on: 28/6/2021
 *      Author: AHMED IBRAHIM
 */
#ifndef E2PROM_INTERFACE_H_
#define E2PROM_INTERFACE_H_

void EEPROM_VoidWriteDataByte(uint16_t Copy_U16LocationAddress,uint8_t Copy_U8Data);
void EEPROM_VoidReadDataByte(uint16_t Copy_U16Address,uint8_t* Copy_U8Data);

#endif
