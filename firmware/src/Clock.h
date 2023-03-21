
#ifndef Clock_h
#define Clock_h

#include "Arduino.h"
#include <Wire.h>
#include <SPI.h>
#include "RTClib.h"

RTC_DS1307 rtc;


char daysOfTheWeek[7][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};



void clockSetup(){


  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  // When time needs to be re-set on a previously configured device, the
  // following line sets the RTC to the date & time this sketch was compiled
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // This line sets the RTC with an explicit date & time, for example to set
  // January 21, 2014 at 3am you would call:
  // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
}


void serialPrintDateTime(short year, short month, short day, String dayOfTheWeek, short hour, short minute, short second){
    Serial.print(year);
    Serial.print('/');
    Serial.print(month);
    Serial.print('/');
    Serial.print(day);
    Serial.print("-");
    Serial.print(dayOfTheWeek);
    Serial.print("-");
    Serial.print(hour);
    Serial.print(':');
    Serial.print(minute);
    Serial.print(':');
    Serial.print(second);
    Serial.println();
}

void displayDateTime(short year, short month, short day, String dayOfTheWeek, short hour, short minute, short second){


    lcd.setCursor(0,0);
    lcd.print(year);
    lcd.print("/");
    lcd.print(month);
    lcd.print("/");
    lcd.print(day);
    lcd.print("-");
    lcd.print(dayOfTheWeek);
    lcd.print("  ");

    lcd.setCursor(0,1);

    lcd.print(hour);
    lcd.print(":");
    lcd.print(minute);
    lcd.print(":");
    lcd.print(second);
    lcd.print("    ");
}


void clockLoop(){

      DateTime now = rtc.now();

      short year = now.year();
      short month = now.month();
      short day = now.day();
      String dayOfTheWeek = daysOfTheWeek[now.dayOfTheWeek()];
      short hour = now.hour();
      short minute = now.minute();
      short second = now.second();

      serialPrintDateTime(year,month,day,dayOfTheWeek,hour,minute,second);
      displayDateTime(year,month,day,dayOfTheWeek,hour,minute,second);

}

#endif
