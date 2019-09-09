//
// Created by dariusz on 23.03.18.
//

#include <msp430.h>
#include <stdio.h>
#include "timer.h"

uint8_t timerCount = 0;
extern uint8_t ledToggleFlag;
extern uint8_t executeTaskFlag;

void timerInit() {
  //seting up timer
  CCTL0 = CCIE;  //Enable interrupt in capture and control register
  CCR0 = 4096;//Set capture and control threshold to 1/8 of 32kHz clock
  TACTL |= TASSEL_1;//choose ACLK precyzyjny timer na 32kHz
  TACTL |= MC_1; //Count up mode
  TACTL |= TACLR; //Clear the timer
}

#pragma vector=TIMER0_A0_VECTOR

__interrupt void TIMER0_A0_ISR(void) {
  timerCount++;
  if (timerCount >= 8) {
    timerCount = 0;
    ledToggleFlag = 1;
  }
  executeTaskFlag = 1;
  //Wake up
  __bic_SR_register_on_exit(LPM0_bits);
}