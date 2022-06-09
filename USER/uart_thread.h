#ifndef _UART_THREAD_
#define _UART_THREAD_

#include "cmsis_os2.h"
#include "device.h"
#include "aht10_thread.h"
#include "string.h"

#define HUMI_CMD "get humidity"
#define TEMP_CMD "get temperature"

extern osThreadId_t uart_thread_id;

void uart_thread(void *argument);

#endif
