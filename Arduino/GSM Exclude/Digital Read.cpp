void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  
  int analogSensor = digitalRead(2);
  Serial.println(analogSensor);
  delay(500);
}