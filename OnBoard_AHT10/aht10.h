#ifndef __AHT10_H
#define __AHT10_H

#include "cmsis_os2.h"
#include "stm32l4xx_hal.h"
#include "iic.h"

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

#define AHT10_IIC_ADDR	0x38			//AHT10 IIC地址

#define AHT10_CALIBRATION_CMD 	0xE1 	//校准命令(上电后只需要发送一次)
#define AHT10_NORMAL_CMD 		0xA8 	//正常工作模式
#define AHT10_GET_DATA 			0xAC 	//读取数据命令

u8 AHT10_Init(void);
float AHT10_Read_Temperature(void);
float AHT10_Read_Humidity(void);

#endif



