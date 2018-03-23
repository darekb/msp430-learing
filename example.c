// example program for launchpad, blink two leds, how original!

#include <msp430.h>
#include <stdio.h>

uint8_t timerCount = 0;

int main()
{
    WDTCTL = WDTPW | WDTHOLD; // disable watchdog

    //seting up timer
    TA0CTL |= TASSEL_1; //choose ACLK precyzyjny timer na 32kHz
    TA0CTL |= MC_1; //Count up mode
    TA0CTL |= TACLR; //Clear the timer
    TA0CCR0 = 4096;   //Set capture and control threshold to 1/8 of 32kHz clock
    TA0CCTL0 |= CCIFG; //Enable interrupt in capture and control register


    P1DIR |= BIT0 | BIT6; // set P1.0 and P1.6 as output

    P1OUT |= BIT0; // start with P1.0 on
    P1OUT &= ~BIT6; // and P1.6 off

    __bis_SR_register(LPM0_bits + GIE);//enable interupts

}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR(void){
    timerCount++;
    if(timerCount >= 8){
        timerCount = 0;
        P1OUT ^= BIT0 | BIT6;
    }
}