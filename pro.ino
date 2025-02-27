
/*
 * HC-SR04 example sketch
 *
 * https://create.arduino.cc/projecthub/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-036380
 *
 * by Isaac100
 */
const int trigPin = 9;
const int echoPin = 10;
const int openPin=3;
float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(openPin,OUTPUT);
  digitalWrite(openPin,HIGH);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if(distance>=0&&distance<=10)
  {
    digitalWrite(openPin,LOW);
    delay(10);
  }
  else
  {
    digitalWrite(openPin,HIGH);
    delay(10);
  }
  delay(100);
}
