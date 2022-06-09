#include "aht10_thread.h"

float temperature;
float humidity;
osThreadId_t aht10_thread_id;

void aht10_thread(void *argument)
{
    while(1)
	{
        temperature = AHT10_Read_Temperature();
        humidity = AHT10_Read_Humidity();
        osDelay(100);
	}
}

