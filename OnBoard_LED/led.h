#ifndef _LED_H
#define _LED_H

#include "cmsis_os2.h"
#include "stm32l4xx_hal.h"

void LED_Init(void);//��ʼ��

void LEDR(int status);//��ƿ���

void LEDR_TogglePin(void);//��Ʒ�ת

void LEDG(int status);//�̵ƿ���

void LEDG_TogglePin(void);//�̵Ʒ�ת

void LEDB(int status);//���ƿ���

void LEDB_TogglePin(void);//���Ʒ�ת

#endif




