#include<SoftwareSerial.h>
SoftwareSerial SIM900A(10,11);  //Object name SIM900A , utilizing digital PWM pins 10,11
                                //10 as RX,11 as TX
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
void setup() {
  SIM900A.begin(9600); 

}

void loop() {
  delay(1000);
  OCMessage();
  delay(1000000);

};

