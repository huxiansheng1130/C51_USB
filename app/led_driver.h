#ifndef _LED_DRIVER_H_
#define _LED_DRIVER_H_

#include <AT89X52.H>

#define LEDS P2

sbit LEDS1 = LEDS ^ 0;
sbit LEDS2 = LEDS ^ 1;
sbit LEDS3 = LEDS ^ 2;
sbit LEDS4 = LEDS ^ 3;
sbit LEDS5 = LEDS ^ 4;
sbit LEDS6 = LEDS ^ 5;
sbit LEDS7 = LEDS ^ 6;
sbit LEDS8 = LEDS ^ 7;

#define Onled1() LEDS1 = 0
#define Onled2() LEDS2 = 0
#define Onled3() LEDS3 = 0
#define Onled4() LEDS4 = 0
#define Onled5() LEDS5 = 0
#define Onled6() LEDS6 = 0
#define Onled7() LEDS7 = 0
#define Onled8() LEDS8 = 0


#define Offled1() LEDS1 = 1
#define Offled2() LEDS2 = 1
#define Offled3() LEDS3 = 1
#define Offled4() LEDS4 = 1
#define Offled5() LEDS5 = 1
#define Offled6() LEDS6 = 1
#define Offled7() LEDS7 = 1 
#define Offled8() LEDS8 = 1

#define ToggleLed1() (LEDS1 ^= 1)
#define ToggleLed2() (LEDS2 ^= 1)
#define ToggleLed3() (LEDS3 ^= 1)
#define ToggleLed4() (LEDS4 ^= 1)
#define ToggleLed5() (LEDS5 ^= 1)
#define ToggleLed6() (LEDS6 ^= 1)
#define ToggleLed7() (LEDS7 ^= 1)
#define ToggleLed8() (LEDS8 ^= 1)

#endif 