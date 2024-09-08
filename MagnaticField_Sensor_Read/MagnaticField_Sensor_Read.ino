const int hallSensorPin = 0;  // Internal ADC pin for Hall Effect sensor

void setup() {
  Serial.begin(115200);  // Initialize serial communication at 115200 baud
}

void loop() {
  int hallValue = analogRead(hallSensorPin);  // Read the value from the Hall Effect sensor
  Serial.print("Hall Effect Sensor Value: ");
  Serial.println(hallValue);   // Print the value to the serial monitor
  delay(500);  // Delay for 500 milliseconds
}
