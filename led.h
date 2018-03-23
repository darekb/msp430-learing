//
// Created by dariusz on 23.03.18.
//

#ifndef EXAMPLE_LED_H
#define EXAMPLE_LED_H


#define LED_GREEN   0x01
#define LED_YELLOW  0x02
#define LED_RED     0x04

void ledInit();

void ledToggle();

void ledClear();

void ledGreenBlink();

void ledGreenOn();

void ledGreenOff();

void ledRedBlink();

void ledRedOn();

void ledRedOff();

void ledYellowBlink();

void ledYellowOn();

void ledYellowOff();

#endif //EXAMPLE_LED_H
