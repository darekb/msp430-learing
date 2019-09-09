//
// Created by dariusz on 23.03.18.
//

#include "scheluder.h"
#include "led.h"

Task taskList[TASK_MAX];
uint8_t taskCount = 0;

void scheluderDeleteTask(uint8_t index) {
  uint8_t i;
  for (i = index; i < taskCount - 1; i++) {
    taskList[i] = taskList[i + 1];
  }
  taskCount--;
}

void scheluderCreateTask(void (*func)(void), uint16_t period, uint8_t repeat) {
  Task taskToAdd;
  taskToAdd.taskFunction = func;
  taskToAdd.period = period * 8;
  taskToAdd.repeat = repeat;
  taskToAdd.elapsedTime = 0;
  taskList[taskCount++] = taskToAdd;
}

void scheluderExecuteTask() {
  uint8_t i;
  for (i = 0; i < taskCount; i++) {
    taskList[i].elapsedTime++;
    if (taskList[i].elapsedTime >= taskList[i].period) {
      taskList[i].elapsedTime = 0;
      taskList[i].taskFunction();
      if (taskList[i].repeat == 0) {
        scheluderDeleteTask(i);
      }
    }
  }
}
