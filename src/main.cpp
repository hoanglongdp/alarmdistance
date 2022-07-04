#include <Arduino.h>

#define Trig 8
#define Echo 7
#define Horn 5

float Distance() {
  digitalWrite(Trig, LOW);
  delay(2);
  digitalWrite(Trig, HIGH);
  delay(10);
  digitalWrite(Trig, LOW);
  float duration = pulseIn(Echo, HIGH);
  float distance = duration / 2.0 / 29.412;
  return distance;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(Horn, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float distance = Distance();
  if (distance < 5) {
    digitalWrite(Horn, HIGH);
  }else {
    digitalWrite(Horn, LOW);
  }
  Serial.println(distance);
  delay(500);
}