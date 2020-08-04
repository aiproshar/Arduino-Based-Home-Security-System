#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include<SoftwareSerial.h>
int gas;
int fire;
int pir;
bool motionTrue = false;
int amp;
int motioncount = 0;
bool motion_sms = false;
char c = ' ';

LiquidCrystal_I2C lcd(0x3F, 16, 2); //LCD Display(I2C) Object Declaration on Adress 0x3F
									//incase of malfunction find the I2C adress using I2C scanner
SoftwareSerial SIM900A(10,11);  //Object name SIM900A , utilizing digital PWM pins 10,11
                                //10 as RX; 11 as TX

void Emergency_State()
{
  digitalWrite(2,HIGH);
  while(1);//Arduino Remains into Emergency State Until Reboot;
}
void FireMessage()
{
  SIM900A.println("AT+CMGF=1");    //setting the GSM module text mode before sending a SMS
  delay(2000);
  SIM900A.println("AT+CMGS=\"+8801700000000\"\r"); //Host mobile phone number to send message
  delay(1000);
  SIM900A.println("Fire Detected");// Messsage content
  SIM900A.println("System Entered into Emergency Mode!!");
  SIM900A.println((char)26);// ASCII code of CTRL+Z ; Indicates Termination of Text
  delay(1000);
};
void GasMessage()
{
  SIM900A.println("AT+CMGF=1");    //setting the GSM module text mode before sending a SMS
  delay(2000);
  SIM900A.println("AT+CMGS=\"+8801700000000\"\r"); //Host mobile phone number to send message
  delay(1000);
  SIM900A.println("Gas Detected");// Messsage content
  SIM900A.println("System Entered into Emergency Mode!!");
  SIM900A.println((char)26);// ASCII code of CTRL+Z ; Indicates Termination of Text
  delay(1000);
};
void OCMessage()  //OverCurrent Message
{
  SIM900A.println("AT+CMGF=1");    //setting the GSM module text mode before sending a SMS
  delay(2000);
  SIM900A.println("AT+CMGS=\"+8801700000000\"\r"); //Host mobile phone number to send message
  delay(1000);
  SIM900A.println("Over Current Detected into Main Power Line ");// Messsage content
  SIM900A.println("System Entered into Emergency Mode!!");
  SIM900A.println((char)26);// ASCII code of CTRL+Z ; Indicates Termination of Text
  delay(1000);
};
void MotionMessage()
{
  SIM900A.println("AT+CMGF=1");    //setting the GSM module text mode before sending a SMS
  delay(2000);
  SIM900A.println("AT+CMGS=\"+8801700000000\"\r"); //Host mobile phone number to send message
  delay(1000);
  SIM900A.println("Unauthorized Motion Detected");// Messsage content
  SIM900A.println((char)26);// ASCII code of CTRL+Z ; Indicates Termination of Text
  delay(1000);
};

void GSM_debug() //Set Serial Monitor Both NL & CR (important)
{
	lcd.clear();
	lcd.print("GSM DEBUGGING")
	while(!Serial);
    Serial.println("SIM900A started at 9600");
    delay(1000);
    Serial.println("SIM900A is Ready!");
    while(digitalRead(8))
    {
    	// Keep reading from SIM800 and send to Arduino Serial Monitor
    	if (SIM900A.available())
    	{ c = SIM900A.read();
    	Serial.write(c);}
    	// Keep reading from Arduino Serial Monitor and send to SIM900A
    	if (Serial.available())
    	{ 	
    	  c = Serial.read();
          SIM900A.write(c);
        }
    }
    Serial.println("Exiting GSM Debug");
    lcd.clear();
}



//---------------------------------------------------------------------------------------------------------------





void setup() {
  pinMode(A0, INPUT);//Analog 0 for Gas Sensor Output
  pinMode(A1,INPUT);//Analog 1 for Fire Sensor Output
  pinMode(A2,INPUT);//Analog 2 for Current Sensor Output
  pinMode(2,OUTPUT);//Digital 2 ;Emergency Mode Output Pin From Arduino,Goes to L293D for Relay Control
  pinMode(4,INPUT);//Digital 4 for PIR-Motion Output
  pinMode(8,INPUT);//GSM Debugging Mode
  Serial.begin(9600);//Starting Serial Communication at 9600 rate
  SIM900A.begin(9600);//starting Communication With GSM object at 9600 rate
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
  motionTrue = false;//No Motion Detected at Each Iteration
  gas = analogRead(A0);
  fire = analogRead(A1);
  pir = digitalRead(4);
  amp = analogRead(A2);
  digitalWrite(2,LOW);//Setting Emergency State False By Default
  if(digitalRead(8))//Checking If Debugging Pin is True
  {
  	lcd.print("GSM Debugging!");
  	GSM_debug();
  }
  lcd.print("Sensors Online");
  lcd.setCursor(0, 1);
  if(gas > 400 || fire < 200 || pir == HIGH || amp > 540)
  {
    if(gas > 400)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Emergency Mode!!");
      lcd.setCursor(0,1);
      lcd.print("Gas Detected");
      GasMessage();
      Emergency_State();
    }
    else if(fire < 200)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Emergency Mode!!");
      lcd.setCursor(0,1);
      lcd.print("Fire Detected");
      FireMessage();
      Emergency_State();
    }
    else if( amp > 540)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Emergency Mode!!");
      lcd.setCursor(0,1);
      lcd.print("O.C. Detected");
      OCMessage();
      Emergency_State();
    }
    else if(pir)
    {
      motionTrue = true;
      motioncount++;
      if(motioncount >= 3)
      {
      	if(motion_sms == false)
      	{
      		motion_sms = true;
      		MotionMessage();
      	}
      }
    }
    if(motionTrue)delay(7000);//Motion sensor recover time after Detection
  }
  
  lcd.clear();
}