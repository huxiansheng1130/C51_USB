#ifndef _UART_DRIVER_H_
#define _UART_DRIVER_H_

#include <AT89X52.H>
#include "user/my_types.h"

#define BIT_RATE 9600UL

extern void print_int(int num);
extern void uart_init(void);
extern void u_printf(const char *format, ...);

#endif 