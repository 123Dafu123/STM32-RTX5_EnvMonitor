#include "beep.h"

/**
 * @brief	��ʼ������������
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
 * @brief	����������
 *
 * @param   status	0��1��
 *
 * @return  void
 */
void BEEP(int status)
{
    status?HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
}

/**
 * @brief	��������ת
 *
 * @param   status	0��1��
 *
 * @return  void
 */
void BEEP_TogglePin(void)
{
    HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_2);
}
