#include "app/key_driver.h"
#include "app/led_driver.h"
#include <string.h>

Key_state key_st;

void key_driver_init(void)
{
	KEY_IO = 0xFF;
	memset(&key_st, 0x00, sizeof(key_st));
}

void key_scan(void)
{
	key_st.current = get_key_value();

	if (key_st.current != key_st.old)
	{
		key_st.no_change_time = 0;
		key_st.old = key_st.current;
		return;
	}
	else
	{
		key_st.no_change_time++;
		if (key_st.no_change_time > 10)
		{
			key_st.no_change_time = 0;
			key_st.press = key_st.old;
			key_st.down |= (~key_st.last) & (key_st.press);
			key_st.up &= key_st.last & (~key_st.press);
			key_st.last = key_st.press;
		}
	}
}

void key_main_loop(void)
{
	LEDS = ~key_st.press;
}