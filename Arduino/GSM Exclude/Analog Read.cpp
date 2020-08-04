void setup() {
  pinMode(A0, INPUT); 
}

void loop() {
  
  int analogSensor = analogRead(A0);
  Serial.println(analogsensor);
  delay(500);
}