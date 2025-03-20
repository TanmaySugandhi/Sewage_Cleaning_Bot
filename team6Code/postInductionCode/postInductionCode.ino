#define BLYNK_TEMPLATE_ID "TMPL32GSQIhe6"
#define BLYNK_TEMPLATE_NAME "Quickstart Device"
#define BLYNK_AUTH_TOKEN "cno9TktK1ZRK2Q2WZqoa5WEpWi8TeDRY"

#include <BlynkSimpleEsp8266.h>
//Movement
// Motor A
const int motor1A = D1;  // D0
const int motor1B = D2;  // D2
const int enA = D0;      // D0

// Motor B
const int motor2A = D3;  // D3
const int motor2B = D4;  // D4
const int enB = D5;      // D5

// Extension
const int motor3A = D6;  // D6
const int motor3B = D7;  // D7
int const en2A = D8;     // D8

// Spinning
const int motor4A = A0;   // GPIO3 (RX)
const int motor4B = 1;   // GPIO1 (TX)
int const en2B = 3;     // GPIO10 (SD3)

void setup() {
  Serial.begin(00);
  Blynk.begin(BLYNK_AUTH_TOKEN, "The Robotics Club", "trcsnist@2022");

  //Movement
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  //Extension and Spinning
  pinMode(motor3A, OUTPUT);
  pinMode(motor3B, OUTPUT);
  pinMode(motor4A, OUTPUT);
  pinMode(motor4B, OUTPUT);
  pinMode(en2A, OUTPUT);
	pinMode(en2B, OUTPUT);
}

BLYNK_WRITE(V0) { //Forward Button
  int value = param.asInt();  

  if (value == 1) {
    Serial.println("Switch on V0 is ON");
    forward();
  } else {
    Serial.println("Switch on V0 is OFF");
    stopMotorsDrive();
  }
}

BLYNK_WRITE(V1) { // Backward
  int value = param.asInt(); 

  if (value == 1) {
    Serial.println("Switch on V1 is ON");
    backward();
  } else {
    Serial.println("Switch on V1 is OFF");
    stopMotorsDrive();
  }
}

BLYNK_WRITE(V2) { // Right
  int value = param.asInt();

  if (value == 1) {
    Serial.println("Switch on V2 is ON");
    right();
  } else {
    Serial.println("Switch on V2 is OFF");
    stopMotorsDrive();
  }
}

BLYNK_WRITE(V3) { //Left
  int value = param.asInt();  

  if (value == 1) {
    Serial.println("Switch on V3 is ON");
    left();
  } else {
    Serial.println("Switch on V3 is OFF");
    stopMotorsDrive();
  }
}

BLYNK_WRITE(V5) { //Extension And retraction
  int value = param.asInt();  

  if (value == 1) {
    Serial.println("Switch on V3 is ON");
    extension();
  } else {
    Serial.println("Switch on V3 is OFF");
    retraction();
    stopMotorsEs();
  }
}

BLYNK_WRITE(V4) { //Spinning
  int value = param.asInt();  

  if (value == 1) {
    Serial.println("Switch on V3 is ON");
    spin();
  } else {
    Serial.println("Switch on V3 is OFF");
    stopMotorsEs();
  }
}

void loop() {
  Blynk.run();
}
//Driving Functions
void forward() {
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
}

void backward() {
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);
}

void left() {
  analogWrite(enA, 255);
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  analogWrite(enB, 255); 
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);
}

void right() {
  analogWrite(enA, 255);  
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  analogWrite(enB, 255);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
}

void stopMotorsDrive() {
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW);
}

//Extension and Spinning Functions
void extension() {
  analogWrite(en2A, 255);
  digitalWrite(motor3A, HIGH);
  digitalWrite(motor3B, LOW);
  delay(250);
  stopMotorsEs(); 
}

void retraction() {
   analogWrite(en2A, 255);
  digitalWrite(motor3A, LOW);
  digitalWrite(motor3B, HIGH);
  delay(250);
  stopMotorsEs(); 
}

void spin(){
  analogWrite(enB, 255);
  digitalWrite(motor4A, HIGH);
  digitalWrite(motor4B, LOW);
}

void stopMotorsEs() {
  analogWrite(en2A, 0);
  analogWrite(en2B, 0);
  digitalWrite(motor3A, LOW);
  digitalWrite(motor3B, LOW);
  digitalWrite(motor4A, LOW);
  digitalWrite(motor4B, LOW);
}