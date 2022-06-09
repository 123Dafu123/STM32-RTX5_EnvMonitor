#include "uart.h"

#if 1
//标准库需要的支持函数
struct __FILE
{
    int handle;
};

FILE __stdout;
/**
 * @brief	定义_sys_exit()以避免使用半主机模式
 *
 * @param	void
 *
 * @return  void
 */
void _sys_exit(int x)
{
    x = x;
}
/**
 * @brief	重定义fputc函数
 *
 * @param	ch		输出字符量
 * @param	f		文件指针
 *
 * @return  void
 */
int fputc(int ch, FILE *f)
{
    while((USART1->ISR & 0X40) == 0); //循环发送,直到发送完毕

    USART1->TDR = (u8) ch;
    return ch;
}
#endif


#if EN_UART1_RX
//串口中断接收驱动，接收不定长数据
//默认结束符'\r',接收到结束符后会释放UART1_Sem信号量，此时用户调用UART1_Get_Data函数便可以获取串口接收的消息
//若串口未接收数据，则UART1_Sem信号量会阻塞用户线程
//使用流程 osKernelInitialize()->HAL_Init()->UART1_Init()->用户线程->调用 UART1_Get_Data

osSemaphoreId_t UART1_Sem;//串口接收数据处理的信号量

UART_HandleTypeDef UART1_Handler;//UART句柄

u8 ch;//接收的单个字符

u8 buffer[UART_RX_MAX_LEN];//接收缓冲区

int buffer_index=0;//记录当前缓冲区操作位置

int end_flag=0;//串口结束标记符


/**
 * @brief	初始化串口1函数，并初始化消息队列,以及数据处理的互斥量
 *
 * @param	bound	串口波特率
 *
 * @return	void
 */
void UART1_Init(u32 bound)
{
    //UART 初始化设置
    UART1_Handler.Instance = USART1;					//USART1
    UART1_Handler.Init.BaudRate = bound;				//波特率
    UART1_Handler.Init.WordLength = UART_WORDLENGTH_8B; //字长为8位数据格式
    UART1_Handler.Init.StopBits = UART_STOPBITS_1;	    //一个停止位
    UART1_Handler.Init.Parity = UART_PARITY_NONE;		//无奇偶校验位
    UART1_Handler.Init.HwFlowCtl = UART_HWCONTROL_NONE; //无硬件流控
    UART1_Handler.Init.Mode = UART_MODE_TX_RX;		    //收发模式
    HAL_UART_Init(&UART1_Handler);					    //HAL_UART_Init()会使能UART1

    __HAL_UART_ENABLE_IT(&UART1_Handler, UART_IT_RXNE); //开启接收中断
    HAL_NVIC_EnableIRQ(USART1_IRQn);					//使能USART1中断通道
    HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);            //抢占优先级0，子优先级0
	
    UART1_Sem=osSemaphoreNew(1,0,NULL);//初始化信号量
}


/**
 * @brief	HAL库串口底层初始化，时钟使能，引脚配置，中断配置
 *
 * @param	huart	串口句柄
 *
 * @return  void
 */
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
    //GPIO端口设置
    GPIO_InitTypeDef GPIO_Initure;

    if(huart->Instance == USART1) //如果是串口1，进行串口1 MSP初始化
    {
        __HAL_RCC_GPIOA_CLK_ENABLE();				//使能GPIOA时钟
        __HAL_RCC_USART1_CLK_ENABLE();				//使能USART1时钟

        GPIO_Initure.Pin = GPIO_PIN_9;				//PA9
        GPIO_Initure.Mode = GPIO_MODE_AF_PP;		//复用推挽输出
        GPIO_Initure.Pull = GPIO_PULLUP;			//上拉
        GPIO_Initure.Speed = GPIO_SPEED_FAST;		//高速
        GPIO_Initure.Alternate = GPIO_AF7_USART1;	//复用为USART1
        HAL_GPIO_Init(GPIOA, &GPIO_Initure);	   	//初始化PA9

        GPIO_Initure.Pin = GPIO_PIN_10;				//PA10
        HAL_GPIO_Init(GPIOA, &GPIO_Initure);	   	//初始化PA10
    }

}

/**
 * @brief	串口1中断服务程序，接收单个字符，进行判断，若为结束符就把缓冲区发送到消息队列
 *
 * @param   void
 *
 * @return  void
 */
void USART1_IRQHandler(void)
{
    if(__HAL_UART_GET_FLAG(&UART1_Handler,UART_FLAG_RXNE)!=RESET)
    {
        HAL_UART_Receive(&UART1_Handler,&ch,sizeof(ch),1000);
        if(ch==END_CHAR_1)
        {
            int j;
            for(j=buffer_index;j<UART_RX_MAX_LEN;j++)
            {
                buffer[j]='\0';
            }
            end_flag=1;
            return;
        }
        else if(ch==END_CHAR_2&&end_flag)
        {
            buffer_index=0;
            osSemaphoreRelease(UART1_Sem);
            return;
        }
        end_flag=0;
        buffer[buffer_index++]=ch;
    }
}

/**
 * @brief	串口1用户线程服务程序，将串口数据缓冲区复制到用户传入的数据地址，
 *          若串口未发送数据则使用信号量阻塞用户线程
 *
 * @param   void
 *
 * @return  void
 */
void UART1_Get_Data(char *str)
{
    osSemaphoreAcquire(UART1_Sem,osWaitForever);
    strcpy(str,(const char*)buffer);
}


#endif






