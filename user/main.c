#include <AT89X52.H>
#include "user/my_types.h"
#include "user/user_config.h"
#include "app/time_driver.h"
#include "app/key_driver.h"
#include "app/led_driver.h"
#include "app/uart_driver.h"
void main(void)
{
	tick0_init();
	uart_init();
	key_driver_init();
	uart_send_str(__FILE__);
	while(1)
	{
		key_main_loop();
	};
} 