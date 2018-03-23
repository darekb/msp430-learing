//
// Created by dariusz on 23.03.18.
//

#include <msp430.h>
#include <stdint.h>
#include "led.h"

extern uint8_t ledBlinkingColorRegister;
extern uint8_t ledBlinkFlag;

void ledInit() {
    P1DIR |= BIT0 | BIT6; // set P1.0 and P1.6 as output
    P1OUT |= BIT0; // start with P1.0 on
    P1OUT &= ~BIT6; // and P1.6 off

    P1DIR |= BIT6;
    P3DIR |= BIT3;
    P3DIR |= BIT4;

    ledClear();
}

void ledClear() {
    ledGreenOff();
    ledRedOff();
    ledYellowOff();

    ledBlinkingColorRegister = 0;
}

void ledToggle() {
    P1OUT ^= BIT0 | BIT6;
}

void ledGreenBlink() {
    ledBlinkingColorRegister |= LED_GREEN;
    ledBlinkFlag = 1;
}

void ledGreenOn() {
    P1OUT |= BIT6;
}

void ledGreenOff() {
    P1OUT &= ~BIT6;
}


void ledRedBlink() {
    ledBlinkingColorRegister |= LED_RED;
    ledBlinkFlag = 1;
}

void ledRedOn() {
    P3OUT |= BIT3;
}

void ledRedOff() {
    P3OUT &= ~BIT3;
}


void ledYellowBlink() {
    ledBlinkingColorRegister |= LED_YELLOW;
    ledBlinkFlag = 1;
}

void ledYellowOn() {
    P3OUT |= BIT4;
}

void ledYellowOff() {
    P3OUT &= ~BIT4;
}