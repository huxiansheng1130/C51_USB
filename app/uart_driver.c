#include "app/uart_driver.h"
#include "user/user_config.h"
#include "user/my_types.h"

volatile uint8 sending;

void uart_init(void)
{
	// set time1 init
	TMOD |= 0x20;
	TH1 = TL1 = 256 - FOSC / (BIT_RATE * 12 * 16);
	TR1 = 1;
	
	// set serial communication mode1
	SCON = 0x50; 
	
	// set serial power baud rate 
	PCON |= 0x80;
	
	// allow serial capture
	REN = 1;
	
	// enable serial Interrupt 
	ES = 1;
	
	// enable all Interrupt 
	EA = 1;
}

void uart_iqr(void) interrupt 4 
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

void uart_send_byte(uint8 buf)
{
    SBUF = buf;
    sending = 1;
    while (sending);
}

void uart_send_str(uint8 *str)
{
    while (*str)
        uart_send_byte(*str++);
}