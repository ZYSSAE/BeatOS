/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
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
#include "stm32f10x_it.h"

/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{ 
    printf ("################Hard fault handler]################\r\n"); 
    unsigned int CFSR = *((volatile unsigned long *)(0xE000ED28));
    printf ("CFSR = 0x%08x\r\n", CFSR); 
    printf (" BFARVALID   :%d\r\n",CFSR&(1<<15)?1:0);
    printf (" STKERR      :%d\r\n",CFSR&(1<<12)?1:0);
    printf (" UNSTKERR    :%d\r\n",CFSR&(1<<11)?1:0);
    printf (" IMPRECISERR :%d\r\n",CFSR&(1<<10)?1:0);
    printf (" PRECISERR   :%d\r\n",CFSR&(1<<9)?1:0);
    printf (" IBUSERR     :%d\r\n",CFSR&(1<<8)?1:0);
    printf (" MMARVALID   :%d\r\n",CFSR&(1<<7)?1:0);
    printf (" MSTKERR     :%d\r\n",CFSR&(1<<4)?1:0);
    printf (" MUNSTKERR   :%d\r\n",CFSR&(1<<3)?1:0);
    printf (" DACCVIOL    :%d\r\n",CFSR&(1<<1)?1:0);
    printf (" IACCVIOL    :%d\r\n",CFSR&(1<<0)?1:0);
    printf (" DIVBYZERO   :%d\r\n",CFSR&(1<<25)?1:0);
    printf (" UNALIGNED   :%d\r\n",CFSR&(1<<24)?1:0);
    printf (" NOCP        :%d\r\n",CFSR&(1<<19)?1:0);
    printf (" INVPC       :%d\r\n",CFSR&(1<<18)?1:0);
    printf (" INVSTATE    :%d\r\n",CFSR&(1<<17)?1:0);
    printf (" UNDEFINSTR  :%d\r\n",CFSR&(1<<16)?1:0);
    unsigned int HFSR = *((volatile unsigned long *)(0xE000ED2C));
    printf ("HFSR = 0x%08x\r\n", HFSR); 
    printf (" DEBUGEVT    :%d\r\n",HFSR&((u32)1<<31)?1:0);
    printf (" FORCED      :%d\r\n",HFSR&(1<<30)?1:0);
    printf (" VECTBL      :%d\r\n",HFSR&(1<<1)?1:0);
    while(1);
}


/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
*/
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

void SDIO_IRQHandler(void)
{

}

void USART1_IRQHandler(void)
{

}

void EXTI9_5_IRQHandler(void)
{

}
/**
  * @}
  */ 


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
