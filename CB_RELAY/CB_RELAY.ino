int relay1 = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(relay1, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(relay1,HIGH);
  delay(5000);

  digitalWrite(relay1, LOW);
  delay(1000);
}
