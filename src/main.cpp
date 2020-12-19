/*
  Arduino Slave for Raspberry Pi Master
  i2c_slave_ard.ino
  Connects to Raspberry Pi via I2C

  ######################################################################
  # pi777hub fix: use two different addresses for arduino - 0x9 or 0x8 #
  ######################################################################

  DroneBot Workshop 2019
  https://dronebotworkshop.com
*/

// Include the Wire library for I2C
#include <Wire.h>
#include <Arduino.h>

// LED on pin 13
const int ledPin = 13; 

// we use address 0x9 or 0x8, it is hardcode in master.py
void setup() {
  // Join I2C bus as slave with address 8
  Wire.begin(0x9);
  
  // Call receiveEvent when data received                
  Wire.onReceive(receiveEvent);
  
  // Setup pin 13 as output and turn LED off
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

// Function that executes whenever data is received from master
void receiveEvent(int howMany) {
  while (Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    digitalWrite(ledPin, c);
  }
}
void loop() {
  delay(100);
}