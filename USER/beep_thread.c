#include "beep_thread.h"

osThreadId_t beep_thread_id;

void beep_thread(void *argument){
    while(1)
    {
        while(humidity>70||temperature>35)
        {
            BEEP(1);
			if(KEY_Scan()==KEY0_PRES)
            {
                BEEP(0);
                osDelay(30000);
			}
        }
        osDelay(100);
    }
}
