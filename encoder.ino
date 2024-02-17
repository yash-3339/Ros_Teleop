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

// Define encoder pins
const int encoder1PinA = 18;
const int encoder1PinB = 19;
const int encoder2PinA = 20;
const int encoder2PinB = 21;
const int encoder3PinA = 22;
const int encoder3PinB = 23;
const int encoder4PinA = 24;
const int encoder4PinB = 25;

volatile long encoder1Pos = 0;
volatile long encoder2Pos = 0;
volatile long encoder3Pos = 0;
volatile long encoder4Pos = 0;

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

  // Set encoder pins as inputs
  pinMode(encoder1PinA, INPUT);
  pinMode(encoder1PinB, INPUT);
  pinMode(encoder2PinA, INPUT);
  pinMode(encoder2PinB, INPUT);
  pinMode(encoder3PinA, INPUT);
  pinMode(encoder3PinB, INPUT);
  pinMode(encoder4PinA, INPUT);
  pinMode(encoder4PinB, INPUT);

  // Enable internal pullup resistors for encoder pins
  digitalWrite(encoder1PinA, HIGH);
  digitalWrite(encoder1PinB, HIGH);
  digitalWrite(encoder2PinA, HIGH);
  digitalWrite(encoder2PinB, HIGH);
  digitalWrite(encoder3PinA, HIGH);
  digitalWrite(encoder3PinB, HIGH);
  digitalWrite(encoder4PinA, HIGH);
  digitalWrite(encoder4PinB, HIGH);

  // Attach interrupts for encoder pins
  attachInterrupt(digitalPinToInterrupt(encoder1PinA), updateEncoder1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoder2PinA), updateEncoder2, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoder3PinA), updateEncoder3, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoder4PinA), updateEncoder4, CHANGE);
}

void loop() {
  // Read encoder positions
  long encoder1Value = encoder1Pos;
  long encoder2Value = encoder2Pos;
  long encoder3Value = encoder3Pos;
  long encoder4Value = encoder4Pos;

  // Send encoder positions to Raspberry Pi
  Serial.print(encoder1Value);
  Serial.print(",");
  Serial.print(encoder2Value);
  Serial.print(",");
  Serial.print(encoder3Value);
  Serial.print(",");
  Serial.println(encoder4Value);

  delay(100); // Adjust delay as needed
}

void updateEncoder1() {
  if (digitalRead(encoder1PinA) == digitalRead(encoder1PinB))
    encoder1Pos++;
  else
    encoder1Pos--;
}

void updateEncoder2() {
  if (digitalRead(encoder2PinA) == digitalRead(encoder2PinB))
    encoder2Pos++;
  else
    encoder2Pos--;
}

void updateEncoder3() {
  if (digitalRead(encoder3PinA) == digitalRead(encoder3PinB))
    encoder3Pos++;
  else
    encoder3Pos--;
}

void updateEncoder4() {
  if (digitalRead(encoder4PinA) == digitalRead(encoder4PinB))
    encoder4Pos++;
  else
    encoder4Pos--;
}
