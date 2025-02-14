#include <AT89X52.H>
#include "user/my_types.h"
#include "app/time_driver.h"
#include "app/key_driver.h"
#include "app/uart_driver.h"
#include "app/pdiusb.h"

void main(void)
{
	key_driver_init();
	tick0_init();
	uart_init();

	u_printf("pdiusb %x \r\n",d12_read_id());
	while(1)
	{
		
	};
} 