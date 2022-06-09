#include "device.h"

/**
 * @brief	�豸��ʼ��
 *
 * @param   void
 *
 * @return  void
 */
void DEVICE_Init(void)
{
    HAL_Init();
    OnChip_DEVICE_Init();
    OnBoard_DEVICE_Init();
}

/**
 * @brief	оƬ�豸��ʼ��
 *
 * @param   void
 *
 * @return  void
 */
void OnChip_DEVICE_Init(void)
{
    UART1_Init(115200);
    SPI3_Init();
    IIC_Init();
}


/**
 * @brief	�����豸��ʼ��
 *
 * @param   void
 *
 * @return  void
 */
void OnBoard_DEVICE_Init(void)
{
    KEY_Init();
    LED_Init();
    BEEP_Init();
    LCD_Init();
    AHT10_Init();
}
