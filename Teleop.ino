#include <Arduino.h>

// Define motor pins
const int motor1A = 2;
const int motor1B = 3;
const int motor2A = 4;
const int motor2B = 5;
const int motor3A = 6;
const int motor3B = 7;
const int motor4A = 8;
const int motor4B = 9;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set motor pins as outputs
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  pinMode(motor3A, OUTPUT);
  pinMode(motor3B, OUTPUT);
  pinMode(motor4A, OUTPUT);
  pinMode(motor4B, OUTPUT);
}

void loop() {
  if (Serial.available() >= 4) {
    // Read 4 bytes from serial
    int motor1Speed = Serial.read();
    int motor2Speed = Serial.read();
    int motor3Speed = Serial.read();
    int motor4Speed = Serial.read();

    // Set motor speeds
    analogWrite(motor1A, motor1Speed);
    analogWrite(motor1B, 0);
    analogWrite(motor2A, motor2Speed);
    analogWrite(motor2B, 0);
    analogWrite(motor3A, motor3Speed);
    analogWrite(motor3B, 0);
    analogWrite(motor4A, motor4Speed);
    analogWrite(motor4B, 0);
  }
}
