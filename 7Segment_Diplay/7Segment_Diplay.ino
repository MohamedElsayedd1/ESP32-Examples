// Define segment pins
const int segmentA = 2;
const int segmentB = 3;
const int segmentC = 4;
const int segmentD = 5;
const int segmentE = 6;
const int segmentF = 7;
const int segmentG = 8;

const bool digits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
  // Set all segment pins as outputs
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
}

void displayDigit(int digit) {
  digitalWrite(segmentA, digits[digit][0]);
  digitalWrite(segmentB, digits[digit][1]);
  digitalWrite(segmentC, digits[digit][2]);
  digitalWrite(segmentD, digits[digit][3]);
  digitalWrite(segmentE, digits[digit][4]);
  digitalWrite(segmentF, digits[digit][5]);
  digitalWrite(segmentG, digits[digit][6]);
}

void loop() {
  // Display digits from 0 to 9
  for (int i = 0; i < 10; i++) {
    displayDigit(i);
    delay(1000); // Wait for 1 second
  }
}
