#ifndef _UART_DRIVER_H_
#define _UART_DRIVER_H_

#include <user/my_types.h>

#define BIT_RATE 9600UL

extern void uart_init(void);
extern void uart_send_byte(uint8 buf);
extern void uart_send_str(uint8 *str);
#endif 