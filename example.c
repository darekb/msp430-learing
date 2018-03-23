// example program for launchpad, blink two leds, how original!

#include <msp430.h>
#include <stdio.h>
#include "timer.h"
#include "led.h"


int main()
{
    WDTCTL = WDTPW | WDTHOLD; // disable watchdog
    timerInit();
    ledInit();
    __bis_SR_register(LPM0_bits + GIE);//enable interupts
}
