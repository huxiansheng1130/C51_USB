#include "app/usb_core.h"

void usb_disconnect(void)
{
    u_printf("--->>> usb disconnect\r\n");
    d12_write_command(D12_SET_MODE);
    d12_write_byte(0x06);               
    d12_write_byte(0x47);
    WaitMs(1000);
}

void usb_connect(void)
{
    u_printf("--->>> usb connect\r\n");
    d12_write_command(D12_SET_MODE);
    d12_write_byte(0x16);               
    d12_write_byte(0x47);
}

void usb_bus_suspend(void)
{
    u_printf("--->>> usb_bus_suspend\r\n");
}

void usb_bus_reset(void)
{
    u_printf("--->>> usb_bus_reset\r\n");
}

void usb_ep0_out(void)
{
		uint8 buf[8] = {0};
    u_printf("--->>> usb_ep0_out\r\n");
    if(d12_read_endpoint_last_status(0) & 0x20)
    {
        u_printf("--->>> setup packet\r\n");
        d12_read_endpoint_buffer(0, 16, buf);
        d12_acknowledge_setup();
        d12_clear_buffer();
    }
    else
    {
        d12_read_endpoint_buffer(0, 16, buf);
        d12_clear_buffer();
    }
}

void usb_ep0_in(void)
{
    u_printf("--->>> usb_ep0_in\r\n");
}

void usb_ep1_out(void)
{
    u_printf("--->>> usb_ep1_out\r\n");
}

void usb_ep1_in(void)
{
    u_printf("--->>> usb_ep1_in\r\n");
}

void usb_ep2_out(void)
{
    u_printf("--->>> usb_ep2_out\r\n");
}

void usb_ep2_in(void)
{
    u_printf("--->>> usb_ep2_in\r\n");
}

void usb_select_endpoint(uint8 endp)
{
    d12_write_command(endp);
}

void d12_clear_buffer(void)
{
    d12_write_command(D12_CLEAR_BUFFER);
}

uint8 d12_read_endpoint_last_status(uint8 endp)
{
    d12_write_command(READ_LAST_ENDPOINT_OUT_STATUS + endp);
    return d12_read_byte();
}

void d12_acknowledge_setup(void)
{
    usb_select_endpoint(ENDPOINT_IN);
    d12_write_command(D12_ACKNOWLEDGE_SETUP);
    usb_select_endpoint(ENDPOINT_OUT);
    d12_write_command(D12_ACKNOWLEDGE_SETUP);
}

uint8 d12_read_endpoint_buffer(uint8 endp, uint8 len, uint8 *buf)
{
    uint8 i, j;
    usb_select_endpoint(endp);
    d12_write_command(D12_READ_BUFFER);
    d12_read_byte();
    j = d12_read_byte();
    j = (j > len) ? len : j;
    u_printf("--->>> read point :%i\r\n", endp/2);
    u_printf("--->>> buffer len :%i\r\n", j);
    u_printf("--->>> buffer data: ");
    for (i = 0; i < j; i++) {
       d12_clr_rd();
       *(buf + i) = d12_get_data();
       d12_set_rd();
       u_printf("0x%x, ",  *(buf + i));
    }
    u_printf("\r\n");
    return j; 
}


void usb_irp_loop(void)
{
    uint8 interrupt_source;
    d12_write_command(READ_INTERRUPT_REGISTER);
    interrupt_source = d12_read_byte();
    if (interrupt_source & 0x80)
        usb_bus_suspend();
    if (interrupt_source & 0x40)
        usb_bus_reset();
    if (interrupt_source & 0x01)
        usb_ep0_out();
    if (interrupt_source & 0x02)
        usb_ep0_in();
    if (interrupt_source & 0x04)
        usb_ep1_out();
    if (interrupt_source & 0x08)
        usb_ep1_in();
    if (interrupt_source & 0x10)
        usb_ep2_out();
    if (interrupt_source & 0x20)
        usb_ep2_in();
}

