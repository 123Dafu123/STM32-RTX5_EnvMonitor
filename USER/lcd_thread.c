#include "lcd_thread.h"

osThreadId_t lcd_thread_id;

void lcd_thread(void *argument) {
    while (1) 
    {
        char tempStr[50] = {0};
        char humiStr[50] = {0};
        sprintf(tempStr, "Temp: %02d.%02d", (uint32_t)temperature, (uint32_t)(temperature * 10) % 10);
        sprintf(humiStr, "Humi: %02d.%02d", (uint32_t)humidity, (uint32_t)(humidity * 10) % 10);
        LCD_ShowString(0, 0, 200, 32, 32,tempStr);
        LCD_ShowString(0, 40, 200, 32, 32,humiStr);
        osDelay(100);
    }
}
