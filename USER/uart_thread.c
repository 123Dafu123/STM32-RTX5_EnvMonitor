#include "uart_thread.h"

osThreadId_t uart_thread_id;

void uart_thread(void *argument)
{
    char uart1_data[200]={0};
    while(1)
    {           
        UART1_Get_Data(uart1_data);
        if(strcmp(uart1_data,TEMP_CMD)==0)
        {
            printf("TEMP:%.2f\r",temperature);
        }
        else if(strcmp(uart1_data,HUMI_CMD)==0)
        {
            printf("HUMI:%.2f\r",humidity);
        }
    }
}
