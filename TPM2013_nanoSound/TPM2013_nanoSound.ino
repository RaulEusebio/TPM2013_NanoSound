void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {

  int x = 10;
  Serial.println(x, HEX);
  // put your main code here, to run repeatedly:

  delay(100);
}
