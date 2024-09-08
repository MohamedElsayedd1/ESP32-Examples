const int buttonPin = 25;  // GPIO pin connected to the push button
const int ledPin = 33;     // GPIO pin connected to the LED

volatile bool ledState = false;  // Variable to track LED state
volatile int interrupt_counter = 0;

void IRAM_ATTR handleButtonPress(){
  ledState = !ledState;
  interrupt_counter++;
  Serial.print("Interrupt count : ");
  Serial.println(interrupt_counter);
}

void setup() {
  Serial.begin(115200); 
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(buttonPin, handleButtonPress, FALLING);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, ledState);

}
