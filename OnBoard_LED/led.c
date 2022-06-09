/*
 * @Author: Dafu Wang
 * @Date: 2022-04-21 20:46:17
 * @LastEditTime: 2022-04-21 22:09:53
 * @LastEditors: Dafu Wang
 * @FilePath: \USERc:\stm32Work\RTX5_1\LED\led.c
 */
#include "led.h"


/**
 * @brief	led�豸��ʼ��
 *
 * @param   void
 *
 * @return  void
 */
void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    __HAL_RCC_GPIOE_CLK_ENABLE();

    GPIO_InitStruct.Pin = GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
    HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9,GPIO_PIN_SET);
}

/**
 * @brief	��ƿ���
 *
 * @param   status	0��1��
 *
 * @return  void
 */
void LEDR(int status)
{
	status? HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,GPIO_PIN_RESET):HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,GPIO_PIN_SET);
}

/**
 * @brief	��Ʒ�ת
 *
 * @param   void
 *
 * @return  void
 */
void LEDR_TogglePin(void)
{
    HAL_GPIO_TogglePin(GPIOE,GPIO_PIN_7);
}

/**
 * @brief	�̵ƿ���
 *
 * @param   status	0��1��
 *
 * @return  void
 */
void LEDG(int status)
{
    status? HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,GPIO_PIN_RESET):HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,GPIO_PIN_SET);
}

/**
 * @brief	�̵Ʒ�ת
 *
 * @param   void
 *
 * @return  void
 */
void LEDG_TogglePin(void)
{
    HAL_GPIO_TogglePin(GPIOE,GPIO_PIN_8);
}

/**
 * @brief	���ƿ���
 *
 * @param   status	0��1��
 *
 * @return  void
 */
void LEDB(int status)
{
    status? HAL_GPIO_WritePin(GPIOE,GPIO_PIN_9,GPIO_PIN_RESET):HAL_GPIO_WritePin(GPIOE,GPIO_PIN_9,GPIO_PIN_SET);
}

/**
 * @brief	���Ʒ�ת
 *
 * @param   void
 *
 * @return  void
 */
void LEDB_TogglePin(void)
{
    HAL_GPIO_TogglePin(GPIOE,GPIO_PIN_9);
}





