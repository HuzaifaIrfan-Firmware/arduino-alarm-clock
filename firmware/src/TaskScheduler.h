#ifndef TaskScheduler_h
#define TaskScheduler_h

#include "Arduino.h"

#include "TaskManagerIO.h"


void schedulerSetup(){

    taskManager.scheduleFixedRate(900, [] {
      clockLoop();
    });

taskManager.scheduleFixedRate(100, [] {
    controlsLoop();
    });


taskManager.scheduleFixedRate(1800, [] {
    buzzerLoop();
    });

}


void schedulerLoop(){
  taskManager.runLoop();
}

#endif
