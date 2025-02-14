#include "app/uart_driver.h"
#include "user/my_types.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

volatile uint8 sending = 0;
code uint8 hex_table[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void uart_init(void)
{
	TMOD &= 0x0F;
	TMOD |= 0x20;
	TH1 = TL1 = 256 - (22118400 / ((BIT_RATE) * 12 * 16));
	TR1 = 1;
	
	SCON = 0x50;
	PCON |= 0x80;
	REN = 1;
	ES = 1;
	EA = 1;
}

void uart_irq(void) interrupt 4 
{
	if(RI)
	{
		RI = 0;
	}
	else
	{
		TI = 0;
		sending = 0;
	}
}

void u_putchar(uint8 buf)
{
	SBUF = buf;
	sending = 1;
	while(sending);
}

void print_int(int num) 
{
	uint8 i = 0;
  char buffer[12];
  sprintf(buffer, "%d", num);
  for (i = 0; buffer[i] != '\0'; i++) 
	{
      u_putchar(buffer[i]);
  }
}

void print_hex(unsigned int num) 
{
	uint8 i = 0;
  char buffer[9];
  sprintf(buffer, "%x", num);
  for (i = 0; buffer[i] != '\0'; i++) 
	{
      u_putchar(buffer[i]);
  }
}

void print_string(const char *str) 
{
    while (*str) 
        u_putchar(*str++);
}

void u_printf(const char *format, ...)
{
	typedef char *va_list;
  va_list args;
	
  va_start(args, format);
  
	while (*format) 
	{
    if (*format == '%') {
        format++;
        switch (*format) {
            case 'd':
            case 'i':
                print_int(va_arg(args, int));
                break;
            case 'x':
                print_hex(va_arg(args, unsigned int));
                break;
            case 's':
                print_string(va_arg(args, const char*));
                break;
            case 'c':
                u_putchar(va_arg(args, int));
                break;
            default:
                u_putchar('%');
                u_putchar(*format);
                break;
        }
    } else {
        u_putchar(*format);
    }
    format++;
  }
  
  va_end(args);
}
