#include "app/pdiusb.h"

void d12_write_command(uint8 command)
{
	d12_set_command_addr();
	d12_clr_wr();
	d12_set_port_out();
	d12_set_data(command);
	d12_set_wr();
	d12_set_port_in();
}

uint8 d12_read_byte(void)
{
	uint8 temp;
	d12_set_data_addr();
	d12_clr_rd();
	temp = d12_get_data();
	d12_set_rd();
	return temp;
}

uint16 d12_read_id(void)
{
	uint16 id;
	d12_write_command(READ_ID);
	id = d12_read_byte();
	id |= ((uint16)d12_read_byte() << 8);
	return id;
}