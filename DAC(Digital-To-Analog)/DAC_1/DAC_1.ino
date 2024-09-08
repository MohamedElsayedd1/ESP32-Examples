const int dac_pin = 25;


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  // Generate Traingular Waveform

  for(int i = 0; i <= 255; i++){
    dacWrite(dac_pin, i);
    delay(5);
  }
  for(int i = 255; i >= 0; i--){
    dacWrite(dac_pin, i);
    delay(5);
  }

}
