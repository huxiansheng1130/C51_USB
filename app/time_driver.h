#ifndef _TIME_DRIVER_H_
#define _TIME_DRIVER_H_

#include <AT89X52.H>
#include "user/my_types.h"

extern void tick0_init(void);
extern void WaitMs(uint16 value);
#endif 