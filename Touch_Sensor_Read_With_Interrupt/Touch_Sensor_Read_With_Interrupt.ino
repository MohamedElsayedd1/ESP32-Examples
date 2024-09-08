
const int led_pin = A0;
const int touch_pin = T0;
bool T0_Touched = false;
const int threshold = 20;

void isTouch(){
  T0_Touched = true;
}


void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Touch sensor reading with interrupt : ");
  attachInterrupt(touch_pin, isTouch, threshold);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (T0_Touched) {  // Check if a touch event occurred
    Serial.println("Touched!");
    digitalWrite(led_pin, HIGH);
    T0_Touched = false;  // Reset the flag
  }
  else{
    Serial.println("Not Touched!");
    digitalWrite(led_pin, LOW);

  }

  // Other code can go here
  delay(100); 

}
