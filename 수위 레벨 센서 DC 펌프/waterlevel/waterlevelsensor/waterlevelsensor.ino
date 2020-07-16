void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);                   //pc와 아두이노 통신속도 맞춤
  pinMode(2, INPUT);                    //수위레벨 센서 입력핀
  pinMode(5, OUTPUT);                   // 5, 6, 8, 9 BTS7960 드라이버 모터에 연결
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
    digitalWrite(8, HIGH);                                      //DC 펌프로 물을 뻄
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
