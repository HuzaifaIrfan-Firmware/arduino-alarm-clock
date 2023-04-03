#ifndef TaskScheduler_h
#define TaskScheduler_h

#include "Arduino.h"

#include "TaskManagerIO.h"



#include "Utils.h"


#include "Storage.h"

#include "BluetoothSerial.h"
#include "SerialCom.h"

#include "Display.h"
#include "Clock.h"
#include "Buzzer.h"
#include "Alarm.h"
#include "Controls.h"

#include "BluetoothControls.h"





void schedulerSetup(){

    taskManager.scheduleFixedRate(500, [] {
      alarmLoop();
    });

taskManager.scheduleFixedRate(50, [] {
    controlsLoop();
    });


taskManager.scheduleFixedRate(10, [] {


    bluetoothControlsLoop(bluetoothSerialLoop());
    });


taskManager.scheduleFixedRate(200, [] {
    buzzerLoop();
    });


}


void schedulerLoop(){
  taskManager.runLoop();
}

#endif
