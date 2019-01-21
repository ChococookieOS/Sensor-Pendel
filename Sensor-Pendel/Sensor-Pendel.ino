#include <Servo.h>

#define trigPin 12
#define echoPin 11

#define servoPin 18

#define powerBank 2

Servo servo;

void setup() {
  Serial.begin (9600);
  Serial.println("Init");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(powerBank, OUTPUT);
  servo.attach(servoPin);
  delay(3000);
}

void loop() {
    digitalWrite(powerBank, HIGH);
    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    if(distance <= 10){
      servo.write(180);
      delay(4000);
      servo.write(89);
    }
    delay(20);
    digitalWrite(powerBank,LOW);
}
