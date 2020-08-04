#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);
int pir;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1,INPUT);
  pinMode(2,OUTPUT);
  Serial.begin(9600);
  pinMode(4,INPUT);
  lcd.begin();
  lcd.backlight();
  delay(5000);
  
}

void loop() {
  lcd.clear();
  pir = digitalRead(4);
  if(pir == HIGH)
  {
    lcd.print("Motion Detected");
    delay(5000);
  }
  else lcd.print("NO motion");
  delay(500);

}
