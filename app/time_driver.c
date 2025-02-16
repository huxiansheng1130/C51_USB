#include "app/time_driver.h"
#include "app/led_driver.h"
#include "user/my_types.h"
#include "app/key_driver.h"
#include "user/user_config.h"

uint32 count = 0;

void WaitMs(uint16 value)
{
	uint16 i, j;
	for(i = 0; i < value; i++) 
		for (j = 0; j < 220; j++);
}

void tick0_reload(void)
{
	TL0 = T1MS;
	TH0 = T1MS >> 8;
}

void tick0_init(void)
{
	TMOD |= 0x01;    // 定时器0，16位全用
	TR0 = 0x01;
	ET0 = 0x01;
	EA = 0x01;
	tick0_reload();
}

void tick0_irq() interrupt 1 using 1
{
	tick0_reload();
	
	key_scan();
}