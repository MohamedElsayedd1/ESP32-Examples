#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Wire.begin();
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0); // row 0, column 0
  lcd.print("Hello, World !");
  lcd.setCursor(0, 1);
  lcd.print("Hello, World !"); // row 1, column 0
}

void loop() {
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Test Line 1");
  lcd.setCursor(0, 1);
  lcd.print("Line 2");
  delay(2000); 

   lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Clear Test");
  delay(2000);
  
  lcd.clear();
  lcd.print("Scrolling left...");
  delay(1000);
  for (int i = 0; i < 16; i++) {
    lcd.scrollDisplayLeft();
    delay(300);
  }
  
  lcd.clear();
  lcd.print("Scrolling right...");
  delay(1000);
  for (int i = 0; i < 16; i++) {
    lcd.scrollDisplayRight();
    delay(300);
  }

  lcd.clear();
  lcd.print("Backlight Test");
  delay(1000);
  lcd.noBacklight();
  delay(1000);
  lcd.backlight();
  delay(1000);

  lcd.clear();
  lcd.print("Display Off/On");
  delay(1000);
  lcd.noDisplay();
  delay(1000);
  lcd.display();
  delay(1000);

  lcd.clear();
  lcd.print("Blink Cursor");
  lcd.blink();
  delay(2000);
  lcd.noBlink();

  lcd.clear();
  lcd.print("Underscore Cur.");
  lcd.cursor();
  delay(2000);
  lcd.noCursor();
  
  delay(2000);  
}
