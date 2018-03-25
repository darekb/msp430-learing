// example program for launchpad, blink two leds, how original!

#include <msp430.h>
#include <stdio.h>
#include "timer.h"
#include "led.h"

uint8_t ledToggleFlag = 0;

int main()
{
    WDTCTL = WDTPW | WDTHOLD; // disable watchdog
    timerInit();
    ledInit();
    while(1){
        if(ledToggleFlag == 1){
            ledToggleFlag = 0;
            ledToggle();
        }
        //go to sleep
        __bis_SR_register(LPM3_bits + GIE);       // Enter LPM3 w/ interrupt
    }
    return 0;
}