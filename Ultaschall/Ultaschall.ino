/*
  HC-SR04 Ping distance sensor]
  VCC to arduino 5v GND to arduino GND
  Echo to Arduino pin 13 Trig to Arduino pin 12
  Red POS to Arduino pin 11
  Green POS to Arduino pin 10
  560 ohm resistor to both LED NEG and GRD power rail
  More info at: http://goo.gl/kJ8Gl
  Original code improvements to the Ping sketch sourced from Trollmaker.com
  Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
*/

#include <Servo.h>

#define trigPin 12
#define echoPin 11

#define servoPin 18

#define powerBank 2

Servo servo;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(powerBank, OUTPUT);
  servo.attach(servoPin);
  servo.write(90);
  delay(2000);
  servo.write(45);
  delay(250);
  servo.write(135);
  delay(250);
  servo.write(90);
  delay(2000);
}

void loop() {
    digitalWrite(powerBank, HIGH);
    long duration, distance;
    digitalWrite(trigPin, LOW);  // Added this line
    delayMicroseconds(2); // Added this line
    digitalWrite(trigPin, HIGH);
    //  delayMicroseconds(1000); - Removed this line
    delayMicroseconds(10); // Added this line
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    if (distance >= 200 || distance <= 0){
      Serial.println("Out of range");
    }
    else if(distance <= 10){
      servo.write(0);
      delay(180);
      servo.write(90);
      delay(4000);
      servo.write(180);
      delay(180);
    }
    Serial.print(distance);
    Serial.println(" cm");
    delay(300);
      digitalWrite(powerBank,LOW);
}
