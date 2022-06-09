#ifndef _DEVICE_H_
#define _DEVICE_H_

#include "stm32l4xx_hal.h"
//OnChip_Device 芯片设备
#include "uart.h"
#include "spi3.h"
#include "iic.h"

//OnBoard_Device 板上设备
#include "key.h"
#include "led.h"
#include "beep.h"
#include "lcd.h"
#include "aht10.h"

void DEVICE_Init(void);

void OnChip_DEVICE_Init(void);

void OnBoard_DEVICE_Init(void);

#endif
