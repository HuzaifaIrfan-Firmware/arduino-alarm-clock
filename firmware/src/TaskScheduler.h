#ifndef TaskScheduler_h
#define TaskScheduler_h

#include "Arduino.h"

#include "TaskManagerIO.h"


void schedulerSetup(){

        taskManager.scheduleFixedRate(900, [] {
      clockLoop();
    });


}


void schedulerLoop(){
taskManager.runLoop();
}

#endif
