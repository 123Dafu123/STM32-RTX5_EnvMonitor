/*** 
 * @Author: Dafu Wang
 * @Date: 2022-04-21 22:13:10
 * @LastEditTime: 2022-04-21 22:15:57
 * @LastEditors: Dafu Wang
 * @FilePath: \USERc:\stm32Work\RTX5_1\SPI3\spi3.h
 */
#ifndef __SPI3_H
#define __SPI3_H
#include "cmsis_os2.h"
#include "stm32l4xx_hal.h"

typedef int32_t  s32;
typedef int16_t s16;
typedef int8_t  s8;

typedef const int32_t sc32;
typedef const int16_t sc16;
typedef const int8_t sc8;


typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

typedef const uint32_t uc32;
typedef const uint16_t uc16;
typedef const uint8_t uc8;



void SPI3_Init(void);
void SPI3_SetSpeed(u8 SPI_BaudRatePrescaler);
u8 SPI3_ReadWriteByte(u8 TxData);
u8 SPI3_WriteByte(u8 *TxData,u16 size);

#endif


