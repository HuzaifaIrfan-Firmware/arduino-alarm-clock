#ifndef TaskScheduler_h
#define TaskScheduler_h

#include "Arduino.h"

#include "TaskManagerIO.h"


void schedulerSetup(){

    taskManager.scheduleFixedRate(900, [] {
      alarmLoop();
    });

taskManager.scheduleFixedRate(50, [] {
    controlsLoop();
    });


taskManager.scheduleFixedRate(10, [] {
    serialLoop();
    });


taskManager.scheduleFixedRate(200, [] {
    buzzerLoop();
    });


}


void schedulerLoop(){
  taskManager.runLoop();
}

#endif
