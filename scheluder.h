//
// Created by dariusz on 23.03.18.
//

#ifndef EXAMPLE_SCHELUDER_H
#define EXAMPLE_SCHELUDER_H

#include <stdint.h>

typedef struct Task {
    uint16_t period;      //How often it happen in timer tics
    uint16_t elapsedTime; //Keep track of how many timer tics have elapsed
} Task;

void scheluderExecuteTask();

#endif //EXAMPLE_SCHELUDER_H
