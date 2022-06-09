#ifndef __LCD_THREAD_H__
#define __LCD_THREAD_H__

#include "cmsis_os2.h"
#include "device.h"
#include "aht10_thread.h"

extern osThreadId_t lcd_thread_id;

void lcd_thread(void *argument);

#endif
