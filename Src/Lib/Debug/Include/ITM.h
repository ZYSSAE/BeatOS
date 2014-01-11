/*
 * ITM.h
 *
 * INUTE STM32 ITM Debugging
 */

#ifndef ITM_H_
#define ITM_H_

#include "BeatOS_PublicInclude.h"

#define ITM_Port8(n) (*((volatile unsigned char *)(0xE0000000+4*n)))
#define ITM_Port16(n) (*((volatile unsigned short *)(0xE0000000+4*n)))
#define ITM_Port32(n) (*((volatile unsigned long *)(0xE0000000+4*n)))
#define DEMCR (*((volatile unsigned long *)(0xE000EDFC)))
#define TRCENA 0x01000000

int _write_trace_swo(char* ptr, int len);

#endif /* ITM_H_ */
