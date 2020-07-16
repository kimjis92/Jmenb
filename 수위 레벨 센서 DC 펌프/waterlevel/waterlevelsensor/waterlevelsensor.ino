void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = digitalRead(2);

  if(sensorVal == HIGH){
//    Serial.println("물 넘침");
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    delay(1000);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
  }

  else{
  }
}
