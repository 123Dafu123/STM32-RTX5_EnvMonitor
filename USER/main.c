#include "cmsis_os2.h"
#include "start_thread.h"

int main()
{	
    osKernelInitialize();	
           
    start_t=osThreadNew(start_thread,NULL,NULL);
    
    osKernelStart();
    		
} 

