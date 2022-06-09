#include "key.h"

/**
 * @brief	按键初始化
 *
 * @param   void
 *
 * @return  void
 */
void KEY_Init(void)
{
    /*
		KEY0 	- PD10
		KEY1 	- PD9
		KEY2 	- PD8
		WK_UP 	- PC13
	*/
	
    GPIO_InitTypeDef GPIO_Initure;

    __HAL_RCC_GPIOC_CLK_ENABLE();           
    __HAL_RCC_GPIOD_CLK_ENABLE();         

    GPIO_Initure.Pin = GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 ;	
    GPIO_Initure.Mode = GPIO_MODE_INPUT;    
    GPIO_Initure.Pull = GPIO_PULLDOWN;      
    GPIO_Initure.Speed = GPIO_SPEED_HIGH;   
    HAL_GPIO_Init(GPIOD, &GPIO_Initure);

    GPIO_Initure.Pin = GPIO_PIN_13;         
    GPIO_Initure.Mode = GPIO_MODE_INPUT;   
    GPIO_Initure.Pull = GPIO_PULLUP;        
    GPIO_Initure.Speed = GPIO_SPEED_HIGH;   
    HAL_GPIO_Init(GPIOC, &GPIO_Initure);
}

/**
 * @brief	按键扫描,支持连按
 *
 * @param   void
 *
 * @return  void
 */
uint8_t KEY_Scan(void)
{
    static uint8_t key_up = 1;
    
    if(key_up &&(KEY0 == 0 || KEY1 == 0 || KEY2 == 0 || WK_UP == 1))
    {
        osDelay(10);
        
        key_up = 0;

        if(KEY0 == 0)       return KEY0_PRES;

        else if(KEY1 == 0)  return KEY1_PRES;

        else if(KEY2 == 0)  return KEY2_PRES;

        else if(WK_UP == 1) return WKUP_PRES;
    }
    else if(KEY0 == 1 && KEY1 == 1 && KEY2 == 1 && WK_UP == 0)key_up = 1;
    
    return 0;
}
