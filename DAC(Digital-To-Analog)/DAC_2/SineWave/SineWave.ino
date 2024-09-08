const int dac_pin = 25;


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  // Generate Sine Wavw

  for(int i = 0 ; i <=360; i++){
    dacWrite(dac_pin, int(128+80 * (sin(deg*3.14/180))));
  }

}
