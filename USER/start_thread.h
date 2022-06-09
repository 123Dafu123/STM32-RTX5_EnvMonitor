#ifndef _START_THREAD_H_
#define _START_THREAD_H_

#include "cmsis_os2.h"
#include "device.h"
#include "aht10_thread.h"
#include "lcd_thread.h"
#include "beep_thread.h"
#include "uart_thread.h"

extern osThreadId_t start_t;

void start_thread(void *argument);

#endif
