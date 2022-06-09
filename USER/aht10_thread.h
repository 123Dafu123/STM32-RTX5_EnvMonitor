#ifndef __AHT10_THREAD_H__
#define __AHT10_THREAD_H__

#include "cmsis_os2.h"
#include "device.h"

extern float temperature;
extern float humidity;
extern osThreadId_t aht10_thread_id;

void aht10_thread(void *argument);

#endif

