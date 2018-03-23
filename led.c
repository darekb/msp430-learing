//
// Created by dariusz on 23.03.18.
//

#include <msp430.h>
#include "led.h"


void ledInit(){
    P1DIR |= BIT0 | BIT6; // set P1.0 and P1.6 as output
    P1OUT |= BIT0; // start with P1.0 on
    P1OUT &= ~BIT6; // and P1.6 off
}

void ledToggle(){
    P1OUT ^= BIT0 | BIT6;
}