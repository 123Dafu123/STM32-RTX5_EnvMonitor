#ifndef _KEY_H_
#define _KEY_H_

#include "cmsis_os2.h"
#include "stm32l4xx_hal.h"

#define KEY0        HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_10)
#define KEY1        HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_9)
#define KEY2        HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_8)
#define WK_UP       HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13)

#define KEY0_PRES 		1
#define KEY1_PRES		2
#define KEY2_PRES		3
#define WKUP_PRES   	4

void KEY_Init(void);//按键初始化

uint8_t KEY_Scan(void);//按键扫描

#endif
