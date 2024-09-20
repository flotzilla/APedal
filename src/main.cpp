#include <Arduino.h>
#include <Keyboard.h>
#include "IntervalTimer.h"

// #define DEBUG;

const int pin = A2;
unsigned const int delayVal = 1000;

unsigned long lastUpdateTime;
unsigned long prevTime;

void setup() {
  pinMode(pin, INPUT);
  Serial.begin(pin);  
  Keyboard.begin();
} 

void handlePress()
{
  int val = digitalRead(pin);  
  
  #ifdef DEBUG
  Serial.println(val);
  #endif

  if ((int) val == LOW){
    unsigned long currentMills = millis();

    if ( (currentMills - lastUpdateTime) > delayVal){
      lastUpdateTime = currentMills;

      #ifdef DEBUG
      Serial.println("pressed");
      #endif

      Keyboard.press(KEY_ESC);
      Keyboard.releaseAll();
    }
  }
}

IntervalTimer serialHandler(10, &handlePress);

void loop() {
  unsigned long currMillis = millis();
  serialHandler.update(currMillis);
}