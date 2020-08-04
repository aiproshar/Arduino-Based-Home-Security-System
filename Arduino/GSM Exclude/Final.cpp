#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
int gas;
int fire;
int pir;
bool motionTrue = 0;
int amp;

LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(2,OUTPUT);
  pinMode(4,INPUT);
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.print("Initializing....");
  lcd.setCursor(0,1);
  for(int i = 5 ; i > 0 ; i--)
  {
    lcd.setCursor(0,0);
    lcd.print("Initializing....");
    lcd.setCursor(0,1);
    lcd.print(i);
    delay(1000);
  }
  lcd.setCursor(0,0);
  lcd.clear();
  
}

void loop() {
  motionTrue = false;
  gas = analogRead(A0);
  fire = analogRead(A1);
  pir = digitalRead(4);
  amp = analogRead(A2);
  lcd.print("Sensors Online");
  lcd.setCursor(0, 1);
  if(gas > 400 || fire < 200 || pir == HIGH || amp > 540)
  {
    if(gas > 400)
    {
      lcd.print("Gas Detected");
    }
    else if(fire < 200)
    {
      lcd.print("Fire Detected");
    }
    else if(pir)
    {
      lcd.print("Motion Detected");
      motionTrue = true;
    }
    else if( amp > 540)
    {
      lcd.print("Over Current");
    }
    digitalWrite(2,HIGH);
    
    if(motionTrue)delay(5000);
  }
  else digitalWrite(2,LOW);
  delay(500);
  
  lcd.clear();
}