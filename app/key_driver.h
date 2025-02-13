#ifndef _KEY_DRIVER_H_
#define _KEY_DRIVER_H_

#include "app/key_config.h"

#define KEY_IO P1
#define get_key_value() (~KEY_IO)

#define KEY1 0x01
#define KEY2 0x02
#define KEY3 0x04
#define KEY4 0x08
#define KEY5 0x10
#define KEY6 0x20
#define KEY7 0x40
#define KEY8 0x80

typedef struct {
    volatile uint8 current;
    volatile uint8 old;
    volatile uint8 no_change_time;
    volatile uint8 press;
    volatile uint8 down;
    volatile uint8 up;
    volatile uint8 last;
    volatile uint8 can_change;
}Key_state;
extern Key_state key_st;

extern void key_driver_init(void);
extern void key_scan(void);
extern void key_main_loop(void);

#endif