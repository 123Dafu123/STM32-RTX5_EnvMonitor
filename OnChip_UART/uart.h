#ifndef _UART_H
#define _UART_H
#include "cmsis_os2.h"
#include "stm32l4xx_hal.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define UART_RX_MAX_LEN  	200  	//�����������ֽ��� 200
#define EN_UART1_RX 		1	    //ʹ�ܣ�1��/��ֹ��0������1����
#define END_CHAR_1            '\r'    //�������ݽ�����
#define END_CHAR_2            '\n'    //�������ݽ�����

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

void UART1_Init(u32 bound);//���ڳ�ʼ��

void UART1_Get_Data(char *str);//�������ݽ���

#endif


