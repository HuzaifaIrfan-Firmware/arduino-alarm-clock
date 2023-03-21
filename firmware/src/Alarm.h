
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
}

void resetAlarm()
{

    if (buzz)
    {
        buzz = false;
        Serial.println("Buzz Off");
    }

    if (alarmSet)
    {
        alarmSet = false;
        Serial.println("Alarm Off");
    }
}

void setAlarm()
{
    if (not alarmSet)
    {
        if (not alarmSettingView)
        {
            alarmSettingView = true;
        }
        else
        {
            alarmSettingView = false;
            alarmSet = true;
        }
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
    String dayOfTheWeek = daysOfTheWeek[now.dayOfTheWeek()];
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

    serialPrintDateTime(year, month, day, dayOfTheWeek, hour, minute, second, (alarmSet or alarmSettingView), alarmHour, alarmMinute);

    displayDateTime(year, month, day, dayOfTheWeek, hour, minute, second, (alarmSet or alarmSettingView), alarmSettingView, cursor, alarmHour, alarmMinute);
}

#endif
