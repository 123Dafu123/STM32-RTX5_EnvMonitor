#ifndef _BEEP_H_
#define _BEEP_H_

#include "stm32l4xx_hal.h"

void BEEP_Init(void);//��������ʼ��

void BEEP(int status);//����������

void BEEP_TogglePin(void);//��������ת

#endif
