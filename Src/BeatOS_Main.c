#include "BeatOS_Main.h"

/*
 * Semihosting STM32F1 led blink sample.
 *
 * In debug configurations, demonstrate how to print a greeting message
 * on the standard output. In release configurations the message is
 * simply discarded. By default the trace messages are forwarded to
 * the semihosting output.
 *
 * Then demonstrates how to blink a led with 1Hz, using a
 * continuous loop and SysTick delays.
 *
 * On DEBUG, the uptime in seconds is also displayed on the standard output.
 *
 * The external clock frequency is specified as a preprocessor definition
 * passed to the compiler via a command line option (see the 'C/C++ General' ->
 * 'Paths and Symbols' -> the 'Symbols' tab, if you want to change it).
 * The value selected during project creation was HSE_VALUE=7200000.
 *
 * Note: The default clock settings take the user defined HSE_VALUE and try
 * to reach the maximum possible system clock. For the default 8MHz input
 * the result is guaranteed, but for other values it might not be possible,
 * so please adjust the PLL settings in libs/CMSIS/src/system_stm32f10x.c
 *
 * The build uses the startup files; on Release it does not use
 * any standard library function (on Debug the printf() brings lots of
 * functions; removing it should also use no other standard lib functions).
 *
 * To use the special initialisation code present in librdimon.a, for
 * semihosting, the definition USE_STARTUP_FILES is added for the
 * startup code.
 *
 */

// ----------------------------------------------------------------------------

static void
Delay(__IO uint32_t nTime);

static void
TimingDelay_Decrement(void);

void
SysTick_Handler(void);

/* ----- SysTick definitions ----------------------------------------------- */

#define SYSTICK_FREQUENCY_HZ       1000

/* ----- LED definitions --------------------------------------------------- */

/* Olimex STM32-H103 LED definitions */
/* Adjust them for your own board. */

#define BLINK_PORT      GPIOF
#define BLINK_PIN       6
#define BLINK_RCC_BIT   RCC_APB2Periph_GPIOF

#define BLINK_TICKS     SYSTICK_FREQUENCY_HZ/2

// ----------------------------------------------------------------------------

int main()
{
#if defined(DEBUG)

  printf("Hello ARM World!\n");

#endif

  /*
   * At this stage the microcontroller clock setting is already configured,
   * this is done through SystemInit() function which is called from startup
   * file (startup_cm.c) before to branch to application main.
   * To reconfigure the default setting of SystemInit() function, refer to
   * system_stm32f10x.c file
   */

  /* Use SysTick as reference for the timer */
  SysTick_Config(SystemCoreClock / SYSTICK_FREQUENCY_HZ);

  /* GPIO Periph clock enable */
  RCC_APB2PeriphClockCmd(BLINK_RCC_BIT, ENABLE);

  GPIO_InitTypeDef GPIO_InitStructure;

  /* Configure pin in output push/pull mode */
  GPIO_InitStructure.GPIO_Pin = (1 << BLINK_PIN);
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(BLINK_PORT, &GPIO_InitStructure);

  int seconds = 0;

  /* Infinite loop */
  while (1)
    {
      /* Assume the LED is active low */

      /* Turn on led by setting the pin low */
      GPIO_ResetBits(BLINK_PORT, (1 << BLINK_PIN));

      Delay(BLINK_TICKS);

      /* Turn off led by setting the pin high */
      GPIO_SetBits(BLINK_PORT, (1 << BLINK_PIN));

      Delay(BLINK_TICKS);

      ++seconds;

#if defined(DEBUG)
      /*
       * Count seconds on the debug channel.
       */
      printf("Second %d\n", seconds);
#endif
    }
}

// ----------------------------------------------------------------------------

static __IO uint32_t uwTimingDelay;

/**
 * @brief  Inserts a delay time.
 * @param  nTime: specifies the delay time length, in SysTick ticks.
 * @retval None
 */
void
Delay(__IO uint32_t nTime)
{
  uwTimingDelay = nTime;

  while (uwTimingDelay != 0)
    ;
}

/**
 * @brief  Decrements the TimingDelay variable.
 * @param  None
 * @retval None
 */
void
TimingDelay_Decrement(void)
{
  if (uwTimingDelay != 0x00)
    {
      uwTimingDelay--;
    }
}

// ----------------------------------------------------------------------------

/**
 * @brief  This function is the SysTick Handler.
 * @param  None
 * @retval None
 */
void
SysTick_Handler(void)
{
  TimingDelay_Decrement();
}

// ----------------------------------------------------------------------------

