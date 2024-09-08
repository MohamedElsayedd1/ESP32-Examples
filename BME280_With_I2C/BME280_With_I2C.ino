#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define I2C_SDA 21
#define I2C_SCL 22
#define BME280_ADDRESS 0X76 // it may be 0x77 for other sensors 

Adafruit_BME280 bme; // create an object

void setup() {
  Serial.begin(115200);
  Wire.begin(I2C_SDA, I2C_SCL);

  if(!bme.begin(BME280_ADDRESS)){
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1); // Halt execution
  }

  Serial.println("BME280 sensor initialized.");
}

void loop() {
  // put your main code here, to run repeatedly:

  float temperature = bme.readTemperature();
  float humidity = bme.readHumidity();
  float pressure = bme.readPressure();

  // Print values to serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
  
  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" hPa");

  delay(2000);  // Wait for 2 seconds before next reading

}
