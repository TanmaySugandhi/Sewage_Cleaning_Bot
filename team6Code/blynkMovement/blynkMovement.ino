#define BLYNK_TEMPLATE_ID "TMPL32GSQIhe6"
#define BLYNK_TEMPLATE_NAME "Quickstart Device"
#define BLYNK_AUTH_TOKEN "cno9TktK1ZRK2Q2WZqoa5WEpWi8TeDRY"

#include <BlynkSimpleEsp8266.h>
//Movement
// Motor A
const int motor1A = D1;  // GPIO1
const int motor1B = D2;  // GPIO2
const int enA = D0;      // GPIO0

// Motor B
const int motor2A = D3;  // GPIO3
const int motor2B = D4;  // GPIO4
const int enB = D5;      // GPIO5

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, "The Robotics Club", "trcsnist@2022");

  //Movement
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
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