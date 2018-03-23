//
// Created by dariusz on 23.03.18.
//

#include "scheluder.h"
#include "led.h"

extern  struct Task ledTimingTask;

void scheluderExecuteTask(){
    ledTimingTask.elapsedTime++;
    if(ledTimingTask.elapsedTime >= ledTimingTask.period){
        ledRedOn();
        ledYellowOn();
        ledGreenOn();
    }
}