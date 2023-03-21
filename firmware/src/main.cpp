#include "Arduino.h"
#include <Wire.h>
#include <SPI.h>

#include <LiquidCrystal.h>  
#include "RTClib.h"
#include <EasyBuzzer.h>

RTC_DS1307 rtc;
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
short buzzerPin = A2;
bool buz=false;

char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thur", "Fri", "Sat"};

void setup () {
  Serial.begin(115200);
  lcd.begin(16, 2);
  lcd.clear();

  pinMode(buzzerPin, OUTPUT);
  EasyBuzzer.setPin(buzzerPin);



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

void loop () {
    EasyBuzzer.update();
    DateTime now = rtc.now();

    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

    lcd.setCursor(0,0);
    lcd.print(now.year());
    lcd.print("/");
    lcd.print(now.month());
    lcd.print("/");
    lcd.print(now.day());
    lcd.print("-");
    lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
    lcd.print("  ");

    lcd.setCursor(0,1);

    lcd.print(now.hour());
    lcd.print(":");
    lcd.print(now.minute());
    lcd.print(":");
    lcd.print(now.second());
    lcd.print("    ");
    if(Serial.available()){
      buz=true;
    }

    if(buz){
      // digitalWrite(buzzerPin, HIGH);
      for(int i = 0; i  < 4; i++){
        digitalWrite(buzzerPin, HIGH);
        delay(200);
        digitalWrite(buzzerPin, LOW);
        delay(200);
      }
      delay(2000);

    }


    delay(100);
}
