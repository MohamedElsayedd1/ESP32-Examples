const int touch_pin = T9; 
const int led_pin = A0; // pin 36
const int threshold = 20;

int touch_val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Touch sensor test : ");
  pinMode(touch_pin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  touch_val = analogRead(touch_pin);

  if(touch_val < threshold){
    digitalWrite(led_pin, 1);
    Serial.println("Touched!");
  }
  else{
    Serial.println("Not Touched!");
  }

  delay(100);
}
