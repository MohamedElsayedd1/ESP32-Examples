
const int photo_pin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(photo_pin, INPUT);

  /*
 * Sets the sample bits and read resolution
 * Default is 12bit (0 - 4095)
 * Range is 9 - 12
 * */
  analogSetWidth(9);

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("PhotoResistor : ");
  Serial.println(analogRead(photo_pin));
  delay(100);
}
