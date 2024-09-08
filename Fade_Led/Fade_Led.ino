const int ledPin = 33;  // Pin where the LED is connected
const int pwmChannel = 0;  // PWM channel (can be 0-15)
const int pwmFrequency = 5000;  // PWM frequency in Hz
const int pwmResolution = 8;  // PWM resolution (8 bits = 0-255)

void setup() {
  ledcAttach(ledPin, pwmFrequency, pwmResolution);
  ledcAttachChannel(ledPin, pwmFrequency, pwmResolution, pwmChannel);
}

void loop() {
  // Gradually increase brightness
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    ledcWrite(pwmChannel, dutyCycle);  // Set duty cycle (brightness)
    delay(10);  // Delay to see the fade effect
  }

  // Gradually decrease brightness
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    ledcWrite(pwmChannel, dutyCycle);  // Set duty cycle (brightness)
    delay(10);  // Delay to see the fade effect
  }
}
