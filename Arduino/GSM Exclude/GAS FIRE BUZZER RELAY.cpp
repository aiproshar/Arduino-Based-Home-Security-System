#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1,INPUT);
  pinMode(2,OUTPUT);
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  
}

void loop() {
  int gas = analogRead(A0);
  int fire = analogRead(A1);
  lcd.print("Sensors Online");
  lcd.setCursor(0, 1);
  if(gas > 400 || fire < 200)
  {
    if(gas > 400)
      lcd.print("Gas Detected");
     else
      lcd.print("Fire Detected");
    digitalWrite(2,HIGH);
  }
  else digitalWrite(2,LOW);
  delay(500);
  
  lcd.clear();
}