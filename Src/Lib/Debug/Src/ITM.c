#include "ITM.h"

int _write_trace_swo(char* ptr, int len)
{
  int i = 0;
  for (; i < len; i++)
    {
	  ITM_SendChar(*ptr++);
    }

  return len;
}

int _write(int fd, char* ptr, int len)
{
  if (fd == 1)
    {
      return _write_trace_swo(ptr, len);
    }
  return -1;
}

void _init()
{
	return;
}
