//
// Created by dariusz on 23.03.18.
//

#ifndef EXAMPLE_SCHELUDER_H
#define EXAMPLE_SCHELUDER_H

#include <stdint.h>

#define TASK_MAX    16

typedef struct Task {
  void (*taskFunction)(void); //Function that task execute
  uint16_t period;      //How often it happen in timer tics
  uint8_t repeat;       //If task should be repeat
  uint16_t elapsedTime; //Keep track of how many timer tics have elapsed
} Task;

void scheluderDeleteTask(uint8_t index);

void scheluderCreateTask(void (*func)(void), uint16_t period, uint8_t repeat);

void scheluderExecuteTask();

#endif //EXAMPLE_SCHELUDER_H
