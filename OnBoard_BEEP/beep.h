#ifndef _BEEP_H_
#define _BEEP_H_

#include "stm32l4xx_hal.h"

void BEEP_Init(void);//蜂鸣器初始化

void BEEP(int status);//蜂鸣器控制

void BEEP_TogglePin(void);//蜂鸣器翻转

#endif
