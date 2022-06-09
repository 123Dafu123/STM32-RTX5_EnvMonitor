#include "uart.h"

#if 1
//��׼����Ҫ��֧�ֺ���
struct __FILE
{
    int handle;
};

FILE __stdout;
/**
 * @brief	����_sys_exit()�Ա���ʹ�ð�����ģʽ
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
 * @brief	�ض���fputc����
 *
 * @param	ch		����ַ���
 * @param	f		�ļ�ָ��
 *
 * @return  void
 */
int fputc(int ch, FILE *f)
{
    while((USART1->ISR & 0X40) == 0); //ѭ������,ֱ���������

    USART1->TDR = (u8) ch;
    return ch;
}
#endif


#if EN_UART1_RX
//�����жϽ������������ղ���������
//Ĭ�Ͻ�����'\r',���յ�����������ͷ�UART1_Sem�ź�������ʱ�û�����UART1_Get_Data��������Ի�ȡ���ڽ��յ���Ϣ
//������δ�������ݣ���UART1_Sem�ź����������û��߳�
//ʹ������ osKernelInitialize()->HAL_Init()->UART1_Init()->�û��߳�->���� UART1_Get_Data

osSemaphoreId_t UART1_Sem;//���ڽ������ݴ�����ź���

UART_HandleTypeDef UART1_Handler;//UART���

u8 ch;//���յĵ����ַ�

u8 buffer[UART_RX_MAX_LEN];//���ջ�����

int buffer_index=0;//��¼��ǰ����������λ��

int end_flag=0;//���ڽ�����Ƿ�


/**
 * @brief	��ʼ������1����������ʼ����Ϣ����,�Լ����ݴ���Ļ�����
 *
 * @param	bound	���ڲ�����
 *
 * @return	void
 */
void UART1_Init(u32 bound)
{
    //UART ��ʼ������
    UART1_Handler.Instance = USART1;					//USART1
    UART1_Handler.Init.BaudRate = bound;				//������
    UART1_Handler.Init.WordLength = UART_WORDLENGTH_8B; //�ֳ�Ϊ8λ���ݸ�ʽ
    UART1_Handler.Init.StopBits = UART_STOPBITS_1;	    //һ��ֹͣλ
    UART1_Handler.Init.Parity = UART_PARITY_NONE;		//����żУ��λ
    UART1_Handler.Init.HwFlowCtl = UART_HWCONTROL_NONE; //��Ӳ������
    UART1_Handler.Init.Mode = UART_MODE_TX_RX;		    //�շ�ģʽ
    HAL_UART_Init(&UART1_Handler);					    //HAL_UART_Init()��ʹ��UART1

    __HAL_UART_ENABLE_IT(&UART1_Handler, UART_IT_RXNE); //���������ж�
    HAL_NVIC_EnableIRQ(USART1_IRQn);					//ʹ��USART1�ж�ͨ��
    HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);            //��ռ���ȼ�0�������ȼ�0
	
    UART1_Sem=osSemaphoreNew(1,0,NULL);//��ʼ���ź���
}


/**
 * @brief	HAL�⴮�ڵײ��ʼ����ʱ��ʹ�ܣ��������ã��ж�����
 *
 * @param	huart	���ھ��
 *
 * @return  void
 */
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
    //GPIO�˿�����
    GPIO_InitTypeDef GPIO_Initure;

    if(huart->Instance == USART1) //����Ǵ���1�����д���1 MSP��ʼ��
    {
        __HAL_RCC_GPIOA_CLK_ENABLE();				//ʹ��GPIOAʱ��
        __HAL_RCC_USART1_CLK_ENABLE();				//ʹ��USART1ʱ��

        GPIO_Initure.Pin = GPIO_PIN_9;				//PA9
        GPIO_Initure.Mode = GPIO_MODE_AF_PP;		//�����������
        GPIO_Initure.Pull = GPIO_PULLUP;			//����
        GPIO_Initure.Speed = GPIO_SPEED_FAST;		//����
        GPIO_Initure.Alternate = GPIO_AF7_USART1;	//����ΪUSART1
        HAL_GPIO_Init(GPIOA, &GPIO_Initure);	   	//��ʼ��PA9

        GPIO_Initure.Pin = GPIO_PIN_10;				//PA10
        HAL_GPIO_Init(GPIOA, &GPIO_Initure);	   	//��ʼ��PA10
    }

}

/**
 * @brief	����1�жϷ�����򣬽��յ����ַ��������жϣ���Ϊ�������Ͱѻ��������͵���Ϣ����
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
 * @brief	����1�û��̷߳�����򣬽��������ݻ��������Ƶ��û���������ݵ�ַ��
 *          ������δ����������ʹ���ź��������û��߳�
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






