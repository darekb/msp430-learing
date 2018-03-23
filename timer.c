//
// Created by dariusz on 23.03.18.
//

#include <msp430.h>
#include <stdio.h>
#include "timer.h"
#include "led.h"

uint8_t timerCount = 0;

void timerInit(){
    //seting up timer
    TA0CTL |= TASSEL_1; //choose ACLK precyzyjny timer na 32kHz
    TA0CTL |= MC_1; //Count up mode
    TA0CTL |= TACLR; //Clear the timer
    TA0CCR0 = 4096;   //Set capture and control threshold to 1/8 of 32kHz clock
    TA0CCTL0 |= CCIFG; //Enable interrupt in capture and control register
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR(void){
    timerCount++;
    if(timerCount >= 8){
        timerCount = 0;
        ledToggle();
    }
}