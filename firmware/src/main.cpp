#include "Arduino.h"

#include "Utils.h"

#include "Storage.h"
#include "SerialCom.h"

#include "Display.h"
#include "Clock.h"
#include "Buzzer.h"
#include "Alarm.h"
#include "Controls.h"



#include "TaskScheduler.h"

void setup()
{   
    storageSetup();
    serialSetup();

    displaySetup();
    clockSetup();
    buzzerSetup();
    alarmSetup();
    controlsSetup();

    schedulerSetup();
}

void loop()
{
    schedulerLoop();
}
