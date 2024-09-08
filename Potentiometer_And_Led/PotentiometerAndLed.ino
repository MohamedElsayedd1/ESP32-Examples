#include <Arduino.h>  
#include "driver/ledc.h" 

const int pwmPin = 33;  // Pin where you want to output the analog signal
const int pot_pin = 36; // Pin where the potentiometer is connected
const int pwmChannel = 0;
const int pwmFrequency = 4000;  // Frequency of PWM signal
const int pwmResolution = 12;  // Resolution in bits (0-4095 range)

void setup() {
  ledcAttach(pwmPin, pwmChannel, pwmResolution);
  ledcAttachChannel(pwmPin, pwmChannel, pwmResolution, pwmChannel);
}

void loop() {
  int potValue = analogRead(pot_pin);  // Read potentiometer value (0-4095)
  ledcWrite(pwmChannel, potValue); 
}
