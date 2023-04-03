
#ifndef Alarm_h
#define Alarm_h

#include "Arduino.h"

bool alarmSet = false;
short alarmHour = 0;
short alarmMinute = 0;
bool cursor = false;

bool alarmSettingView = false;

void alarmSetup()
{
    alarmSet = loadAlarmSet();
    alarmHour = loadAlarmHour();
    alarmMinute = loadAlarmMinute();
}

void resetAlarm()
{

    if (buzz)
    {
        buzz = false;
        // Serial.println("Buzz Off");
    }

    if (alarmSet)
    {
        alarmSet = false;
        // Serial.println("Alarm Off");
        saveAlarmSet(alarmSet);
    }
}

void setAlarm()
{

        if (not alarmSettingView)
        {
            alarmSettingView = true;
        }
        else
        {
            alarmSettingView = false;
            alarmSet = true;
            saveAlarmSet(alarmSet);
            saveAlarmHour(alarmHour);
            saveAlarmMinute(alarmMinute);
        }

}

void increaseValue()
{
    if (alarmSettingView)
    {
        if (cursor)
        {
            if (alarmMinute >= 55)
            {
                alarmMinute = 0;
                if (alarmHour >= 23)
                {
                    alarmHour = 0;
                }
                else
                {
                    alarmHour = alarmHour + 1;
                }
            }
            else
            {
                alarmMinute = alarmMinute + 5;
            }
        }
        else
        {

            if (alarmHour >= 23)
            {
                alarmHour = 0;
            }
            else
            {
                alarmHour = alarmHour + 1;
            }
        }
    }
}

void decreaseValue()
{
    if (alarmSettingView)
    {
        if (cursor)
        {
            if (alarmMinute <= 0)
            {
                alarmMinute = 55;
                if (alarmHour <= 0)
                {
                    alarmHour = 23;
                }
                else
                {
                    alarmHour = alarmHour - 1;
                }
            }
            else
            {
                alarmMinute = alarmMinute - 5;
            }
        }
        else
        {

            if (alarmHour <= 0)
            {
                alarmHour = 23;
            }
            else
            {
                alarmHour = alarmHour - 1;
            }
        }
    }
}

void moveCursor()
{
    if (alarmSettingView)
    {
        cursor = not cursor;
    }
}

void setCursorValue(short value)
{
    if (alarmSettingView)
    {
        if (cursor)
        {
            if (value < 60 and value >= 0)
            {
                alarmMinute = value;
            }
        }
        else
        {
            if (value < 24 and value >= 0)
            {
                alarmHour = value;
            }
        }
    }
}

void displayAlarmSettingView()
{
}

void alarmLoop()
{

    DateTime now = rtc.now();

    short year = now.year();
    short month = now.month();
    short day = now.day();
    short dayOfTheWeekIndex = now.dayOfTheWeek();
    String dayOfTheWeek = daysOfTheWeek[dayOfTheWeekIndex];
    short hour = now.hour();
    short minute = now.minute();
    short second = now.second();

    if (alarmSet)
    {
        if (hour == alarmHour and minute == alarmMinute)
        {
            buzz = true;
        }
    }

    

    serialSendState(year, month, day, dayOfTheWeekIndex, hour, minute, second,alarmSet, alarmHour, alarmMinute, buzz);
    bluetoothSendState(year, month, day, dayOfTheWeekIndex, hour, minute, second,alarmSet, alarmHour, alarmMinute, buzz);
    displayDateTime(year, month, day, dayOfTheWeek, hour, minute, second, (alarmSet or alarmSettingView), alarmSettingView, cursor, alarmHour, alarmMinute);
}


       void set_alarm(short alarm_hour,short alarm_minute){

            alarmHour = alarm_hour;
            alarmMinute = alarm_minute;
            
            alarmSettingView = false;
            alarmSet = true;
            saveAlarmSet(alarmSet);
            saveAlarmHour(alarmHour);
            saveAlarmMinute(alarmMinute);

       }

       void turn_off_alarm(){
            resetAlarm();
       }

#endif
