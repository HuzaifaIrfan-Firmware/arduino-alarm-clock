
#ifndef Storage_h
#define Storage_h

#include "Arduino.h"
#include "EEPROM.h"

void storageSetup()
{
}

void storageLoop()
{
}



bool loadAlarmSet()
{
    short storedValue = 0;
    EEPROM.get(10, storedValue);
    if (storedValue == 0 or storedValue == 1)
    {
        return storedValue;
    }
    else
    {
        return false;
    }
}

void saveAlarmSet(short value){
    EEPROM.put(10, value);
}

short loadAlarmHour()
{
    short storedValue = 0;
    EEPROM.get(20, storedValue);

    if (storedValue < 24 and storedValue >= 0)
    {
        return storedValue;
    }
    else
    {
        return 0;
    }
}

void saveAlarmHour(short value){
    EEPROM.put(20, value);
}


short loadAlarmMinute()
{
    short storedValue = 0;
    EEPROM.get(30, storedValue);
    if (storedValue < 60 and storedValue >= 0)
    {
        return storedValue;
    }
    else
    {
        return 0;
    }
}

void saveAlarmMinute(short value){
    EEPROM.put(30, value);
}


#endif
