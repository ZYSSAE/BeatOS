/*
 * BeatOS_ChipSupport.h
 *
 * INUTE 2013
 *
 * Chip Support File Of BeatOS
 */

#ifndef BEATOS_CHIPSUPPORT_H_
#define BEATOS_CHIPSUPPORT_H_

//Type:STM32_HD
#ifdef Config_CPU_STM32F10X_HD
	#define STM32F10X_HD
	#ifdef Config_Use_Library
		#define USE_STDPERIPH_DRIVER
		#include "stm32f10x.h"
	#endif
	#ifdef Config_HSE_Value
		#define HSE_VALUE Config_HSE_Value
	#endif
#endif

#endif /* BEATOS_CHIPSUPPORT_H_ */
