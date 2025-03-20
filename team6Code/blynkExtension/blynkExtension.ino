#define BLYNK_TEMPLATE_ID           "TMPL39LC_SiEy"
#define BLYNK_TEMPLATE_NAME         "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "LYucq4uAQycB8FSOZtl7aff-DYGzhhbQ"

#include <BlynkSimpleEsp8266.h>
// Extension
const int motor3A = D1;  // GPIO6
const int motor3B = D2;  // GPIO7
int const en2A = D0;     // GPIO8

// Spinning
const int motor4A = D3;   // GPIO9
const int motor4B = D4;  // GPIO10
int const en2B = D5;      // GPIO11
void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, "The Robotics Club", "trcsnist@2022");
   //Extension and Spinning
  pinMode(motor3A, OUTPUT);
  pinMode(motor3B, OUTPUT);
  pinMode(motor4A, OUTPUT);
  pinMode(motor4B, OUTPUT);
  pinMode(en2A, OUTPUT);
	pinMode(en2B, OUTPUT);
}
BLYNK_WRITE(V0) { //Extension And retraction
  int value = param.asInt();  

  if (value == 1) {
    Serial.println("Switch on V3 is ON");
    analogWrite(en2A, 255);
    digitalWrite(motor3A, LOW);
    digitalWrite(motor3B, HIGH);
    delay(150);
    stopMotorsEs(); 
  } else {
    Serial.println("Switch on V3 is OFF");
    retraction();
  }
}
BLYNK_WRITE(V1) { //Spinning
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
//Extension and Spinning Functions

void extension() {
  analogWrite(en2A, 255);
  digitalWrite(motor3A, LOW);
  digitalWrite(motor3B, HIGH);
  delay(150);
  stopMotorsEs(); 
}
void retraction() {
   analogWrite(en2A, 255);
  digitalWrite(motor3A, HIGH);
  digitalWrite(motor3B, LOW);
  delay(150);
  stopMotorsEs(); 
}
void spin(){
  analogWrite(en2B, 255);
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