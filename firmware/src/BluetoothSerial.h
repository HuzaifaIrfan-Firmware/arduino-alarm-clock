#ifndef BluetoothSerial_h
#define BluetoothSerial_h

#include "Arduino.h"

#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void bluetoothSerialSetup(){

  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  // mySerial.println("Hello, world?");

}

String bluetoothSerialLoop(){

  String serialData; 
  if (mySerial.available()) {
    serialData=mySerial.readStringUntil('\n');
    Serial.println(serialData);


  }
  else if (Serial.available()) {
    serialData=Serial.readStringUntil('\n');
    mySerial.println(serialData);


  }
return serialData;
}

void bluetoothSendState(short year,short month,short day,short dayOfTheWeekIndex,short hour,short minute,short second,short alarmSet,short alarmHour,short alarmMinute,short buzz){
    
    mySerial.print('>');
    mySerial.print(year);
    mySerial.print(',');
      mySerial.print(month);
    mySerial.print(',');
        mySerial.print(day);
    mySerial.print(',');
        mySerial.print(dayOfTheWeekIndex);
    mySerial.print(',');
        mySerial.print(hour);
    mySerial.print(',');
        mySerial.print(minute);
    mySerial.print(',');
        mySerial.print(second);
    mySerial.print(',');
        mySerial.print(alarmSet);
    mySerial.print(',');
        mySerial.print(alarmHour);
    mySerial.print(',');
        mySerial.print(alarmMinute);
    mySerial.print(',');
        mySerial.print(buzz);
    mySerial.println('>');

}


#endif
