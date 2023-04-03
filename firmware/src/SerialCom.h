
#ifndef SerialCom_h
#define SerialCom_h

#include "Arduino.h"

void serialSetup()
{
    Serial.begin(9600);
}

void serialSendState(short year,short month,short day,short dayOfTheWeekIndex,short hour,short minute,short second,short alarmSet,short alarmHour,short alarmMinute,short buzz)
{
    // Serial.print(year);
    // Serial.print('/');
    // Serial.print(month);
    // Serial.print('/');
    // Serial.print(day);
    // Serial.print(" - ");
    // Serial.print(dayOfTheWeek);
    // Serial.print(" - ");
    // Serial.print(hour);
    // Serial.print(':');
    // Serial.print(minute);
    // Serial.print(':');
    // Serial.print(second);

    // if (alarmSet)
    // {
    //     Serial.print(" - Alarm Set ");
    //     Serial.print(alarmHour);
    //     Serial.print(':');
    //     Serial.print(alarmMinute);
    // }
    // Serial.println();

        Serial.print('>');
    Serial.print(year);
    Serial.print(',');
      Serial.print(month);
    Serial.print(',');
        Serial.print(day);
    Serial.print(',');
        Serial.print(dayOfTheWeekIndex);
    Serial.print(',');
        Serial.print(hour);
    Serial.print(',');
        Serial.print(minute);
    Serial.print(',');
        Serial.print(second);
    Serial.print(',');
        Serial.print(alarmSet);
    Serial.print(',');
        Serial.print(alarmHour);
    Serial.print(',');
        Serial.print(alarmMinute);
    Serial.print(',');
        Serial.print(buzz);
    Serial.println('>');
}



#endif
