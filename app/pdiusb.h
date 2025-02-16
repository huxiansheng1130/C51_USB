#ifndef _PDIUSB_H_
#define _PDIUSB_H_

#include <AT89X52.H>
#include "user/my_types.h"

#define READ_ID								  0xFD
#define D12_COMMAND_ADD	        1
#define D12_DATA_ADD		        0
#define D12_DATA				        P0
#define D12_A0					        P3_5
#define D12_WR					        P3_6
#define D12_RD					        P3_7
#define D12_INT					        P3_2

#define d12_set_command_addr()	D12_A0 = D12_COMMAND_ADD
#define d12_set_data_addr()			D12_A0 = D12_DATA_ADD
#define d12_set_wr()						D12_WR = 1
#define d12_clr_wr()						D12_WR = 0
#define d12_set_rd()						D12_RD = 1
#define d12_clr_rd()						D12_RD = 0
#define d12_get_int_st()				D12_INT
#define d12_get_data()					D12_DATA
#define d12_set_data(value)			D12_DATA = (value)
#define d12_set_port_in()				D12_DATA = 0xFF
#define d12_set_port_out()

extern void d12_write_command(uint8 command);
extern void d12_write_byte(uint8 value);
extern uint16 d12_read_id(void);
extern uint8 d12_read_byte(void);

#endif 