// example program for launchpad, blink two leds, how original!

#include <msp430.h>
#include <stdio.h>
#include "timer.h"
#include "led.h"
#include "scheluder.h"

uint8_t ledToggleFlag = 0;
uint8_t executeTaskFlag = 0;
struct Task ledTimingTask;

int main() {
    WDTCTL = WDTPW | WDTHOLD; // disable watchdog
    timerInit();
    ledInit();
    ledGreenOn();
    ledRedOn();
    ledYellowOn();
    ledTimingTask.period = 3 * 8;
    ledTimingTask.elapsedTime = 0;
    while (1) {
        if (ledToggleFlag == 1) {
            ledToggleFlag = 0;
            ledToggle();
        }
        if(executeTaskFlag == 1){
            executeTaskFlag == 0;
            scheluderExecuteTask();
        }
        //go to sleep
        __bis_SR_register(LPM0_bits + GIE);//enable interupts
    }
    return 0;
}
