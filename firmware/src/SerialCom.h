
#ifndef SerialCom_h
#define SerialCom_h

#include "Arduino.h"

void serialSetup()
{
    Serial.begin(115200);
}

void serialPrintDateTime(short year, short month, short day, String dayOfTheWeek, short hour, short minute, short second, bool alarmSet, short alarmHour, short alarmMinute)
{
    Serial.print(year);
    Serial.print('/');
    Serial.print(month);
    Serial.print('/');
    Serial.print(day);
    Serial.print(" - ");
    Serial.print(dayOfTheWeek);
    Serial.print(" - ");
    Serial.print(hour);
    Serial.print(':');
    Serial.print(minute);
    Serial.print(':');
    Serial.print(second);

    if (alarmSet)
    {
        Serial.print(" - ");
        Serial.print(alarmHour);
        Serial.print(':');
        Serial.print(alarmMinute);
    }
    Serial.println();
}



#endif
