#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  
}

void loop() {
  int analogSensor = analogRead(A0);
  lcd.print(analogSensor);
  delay(500);
  lcd.clear();
}