#ifndef _LED_H
#define _LED_H

#include "cmsis_os2.h"
#include "stm32l4xx_hal.h"

void LED_Init(void);//初始化

void LEDR(int status);//红灯控制

void LEDR_TogglePin(void);//红灯翻转

void LEDG(int status);//绿灯控制

void LEDG_TogglePin(void);//绿灯翻转

void LEDB(int status);//蓝灯控制

void LEDB_TogglePin(void);//蓝灯翻转

#endif




