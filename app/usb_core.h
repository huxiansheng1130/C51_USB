#ifndef _USB_CORE_H_
#define _USB_CORE_H_

#include <AT89X52.H>
#include "user/drivers.h"

#define D12_READ_BUFFER                 0xF0
#define D12_ACKNOWLEDGE_SETUP           0xF1
#define D12_CLEAR_BUFFER                0xF2
#define D12_SET_MODE                    0xF3
#define READ_INTERRUPT_REGISTER         0xF4
#define READ_LAST_ENDPOINT_OUT_STATUS   0x40

#define ENDPOINT_OUT                    0x00
#define ENDPOINT_IN                     0x01
        
extern void usb_disconnect(void);
extern void usb_connect(void);
extern void usb_irp_loop(void);
uint8 d12_read_endpoint_last_status(uint8 endp);
void d12_acknowledge_setup(void);
void d12_clear_buffer(void);
extern uint8 d12_read_endpoint_buffer(uint8 endp, uint8 len, uint8 *buf);

#endif 