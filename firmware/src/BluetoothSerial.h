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
  mySerial.println("Hello, world?");

}

void bluetoothSerialLoop(){

  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }

}

#endif
