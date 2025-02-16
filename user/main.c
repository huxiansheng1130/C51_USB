#include <AT89X52.H>
#include "drivers.h"

void main(void)
{
	key_driver_init();
	tick0_init();
	uart_init();
	usb_disconnect();
	usb_connect();

	while(1)
	{
		usb_irp_loop();
	};
} 