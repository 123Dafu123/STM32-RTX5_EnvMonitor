#include "start_thread.h"

osThreadId_t start_t;

void start_thread(void *argument)
{
//��ʼ������
    DEVICE_Init();
	
// �û��߳�
	aht10_thread_id=osThreadNew(aht10_thread,NULL,NULL);
	lcd_thread_id=osThreadNew(lcd_thread,NULL,NULL);
	beep_thread_id=osThreadNew(beep_thread,NULL,NULL);
    uart_thread_id=osThreadNew(uart_thread,NULL,NULL);
}

