/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/main.c
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include <stdio.h>



/***********************************************************************************
Keil 5 工程名字修改教程
1.重命名工程目录USER文件夹下的Template.uvprojx、Template.uvoptx和Template.uvguix
2.删除Listings和Objects文件夹下的所有文件；
3.以文本格式打开.uvprojx文件，将Template全部替换为新工程名；
4.点击.uvprojx打开工程；
5.单机魔法棒，然后在弹出的Option?for?Target?对话框中选择Debug选项卡，重新设置仿真器参数；
6.重新编译工程，即可Download运行。
*************************************************************************************/

/* Private functions ---------------------------------------------------------*/
void SoftwareDelay(uint32_t Cnt)
{
    while(Cnt--);
}

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
    /*!< At this stage the microcontroller clock setting is already configured,
         this is done through SystemInit() function which is called from startup
         file (startup_stm32f10x_xx.s) before to branch to application main.
         To reconfigure the default setting of SystemInit() function, refer to
         system_stm32f10x.c file
       */

    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE);

		GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0;                        //引脚
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;//GPIO_Speed_50MHz;//GPIO_Speed_10MHz;                  //频率(10M)
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;                   //输出类型(推挽式输出)
    GPIO_Init(GPIOB, &GPIO_InitStructure);


    /* Infinite loop */
    while (1)
    {
        GPIOB->ODR ^= GPIO_Pin_0;                                  //LED变化
        SoftwareDelay(0x100000);                     //软件延时
    }
}


#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
    /* User can add his own implementation to report the file name and line number,
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

    /* Infinite loop */
    while (1)
    {
    }
}
#endif
