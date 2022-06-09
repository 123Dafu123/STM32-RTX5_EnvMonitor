#ifndef __BEEP_THREAD_H__
#define __BEEP_THREAD_H__

#include "cmsis_os2.h"
#include "device.h"
#include "aht10_thread.h"


extern osThreadId_t beep_thread_id;

void beep_thread(void *argument);

#endif

