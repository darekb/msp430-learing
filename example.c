// example program for launchpad, blink two leds, how original!

#include <msp430.h>
#include <stdio.h>
#include "timer.h"
#include "led.h"
#include "scheluder.h"

uint8_t ledToggleFlag = 0;
uint8_t executeTaskFlag = 0;
uint8_t ledBlinkFlag = 0;
uint8_t ledBlinkingColorRegister = 0;

int main() {
  WDTCTL = WDTPW | WDTHOLD; // disable watchdog
  timerInit();
  ledInit();

  scheluderCreateTask(ledGreenBlink, 1, 3);
  scheluderCreateTask(ledYellowBlink, 2, 3);
  scheluderCreateTask(ledRedBlink, 3, 3);

  while (1) {
    if (ledToggleFlag == 1) {
      ledToggleFlag = 0;
      ledToggle();
    }
    if (executeTaskFlag == 1) {
      executeTaskFlag = 0;
      scheluderExecuteTask();
    }
    if (ledBlinkFlag == 1) {
      ledBlinkFlag = 0;
      if (ledBlinkingColorRegister & LED_GREEN) {
        ledGreenOn();
      }
      if (ledBlinkingColorRegister & LED_RED) {
        ledRedOn();
      }
      if (ledBlinkingColorRegister & LED_YELLOW) {
        ledYellowOn();
      }
    } else {
      ledClear();
    }
    //go to sleep
    __bis_SR_register(LPM3_bits + GIE);//enable interupts
  }
  return 0;
}
