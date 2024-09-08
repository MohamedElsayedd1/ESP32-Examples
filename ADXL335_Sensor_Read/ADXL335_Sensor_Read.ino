// Pin definitions for the ADXL335 sensor
#define PIN_X_AXIS 34  // X-axis connected to GPIO 34
#define PIN_Y_AXIS 35  // Y-axis connected to GPIO 35
#define PIN_Z_AXIS 32  // Z-axis connected to GPIO 32

// Constants for the ADXL335 sensor
const float referenceVoltage = 3.3;  // ESP32 is running at 3.3V
const int adcResolution = 4095;      // 12-bit ADC, resolution of 0-4095
const float zeroGVoltage = referenceVoltage / 2;  // 1.65V is the zero-g voltage
const float sensitivity = 0.330;  // Sensitivity of ADXL335 is 330 mV/g

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);

  // Setup ADC pins as input
  pinMode(PIN_X_AXIS, INPUT);
  pinMode(PIN_Y_AXIS, INPUT);
  pinMode(PIN_Z_AXIS, INPUT);
}

void loop() {
  // Read raw analog values from ADXL335
  int rawX = analogRead(PIN_X_AXIS);
  int rawY = analogRead(PIN_Y_AXIS);
  int rawZ = analogRead(PIN_Z_AXIS);

  // Convert raw ADC values to voltage (0-3.3V)
  float voltageX = (rawX * referenceVoltage) / adcResolution;
  float voltageY = (rawY * referenceVoltage) / adcResolution;
  float voltageZ = (rawZ * referenceVoltage) / adcResolution;

  // Convert voltage to acceleration in g (g = (Vout - VzeroG) / sensitivity)
  float accelerationX = (voltageX - zeroGVoltage) / sensitivity;
  float accelerationY = (voltageY - zeroGVoltage) / sensitivity;
  float accelerationZ = (voltageZ - zeroGVoltage) / sensitivity;

  // Determine the board's orientation based on acceleration values
  String position = "Unknown";

  if (accelerationZ > 0.8) {
    position = "Flat, facing up";
  } else if (accelerationZ < -0.8) {
    position = "Flat, facing down";
  } else if (accelerationX > 0.8) {
    position = "Standing on right edge";
  } else if (accelerationX < -0.8) {
    position = "Standing on left edge";
  } else if (accelerationY > 0.8) {
    position = "Standing on bottom edge";
  } else if (accelerationY < -0.8) {
    position = "Standing on top edge";
  }

  // Print the position to the Serial Monitor
  Serial.print("Position: ");
  Serial.println(position);

  // Print the raw acceleration data for debugging
  Serial.print("Acceleration X: ");
  Serial.print(accelerationX);
  Serial.println(" g");

  Serial.print("Acceleration Y: ");
  Serial.print(accelerationY);
  Serial.println(" g");

  Serial.print("Acceleration Z: ");
  Serial.print(accelerationZ);
  Serial.println(" g");

  // Delay before the next reading
  delay(1000);
}
