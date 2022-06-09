#include "beep.h"

/**
 * @brief	初始化蜂鸣器函数
 *
 * @param	void	
 *
 * @return	void
 */
void BEEP_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    __HAL_RCC_GPIOB_CLK_ENABLE();

    //PB2
    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
}

/**
 * @brief	蜂鸣器控制
 *
 * @param   status	0关1开
 *
 * @return  void
 */
void BEEP(int status)
{
    status?HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
}

/**
 * @brief	蜂鸣器翻转
 *
 * @param   status	0关1开
 *
 * @return  void
 */
void BEEP_TogglePin(void)
{
    HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_2);
}
