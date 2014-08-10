int analog = 0;
int digital = 0;
int aPin = A0;
int dPin = 10;

void setup(){
  Serial.begin(9600);
}

void loop(){
  delay(10);
  analog = analogRead(aPin);
  Serial.println(analog);
}