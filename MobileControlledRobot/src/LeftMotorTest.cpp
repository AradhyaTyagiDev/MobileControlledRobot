#include <Arduino.h>

#define PWMB 5
#define BIN1 22
#define BIN2 23
#define STBY 4

// PWM config
#define PWM_CHANNEL 0
#define PWM_FREQ 1000
#define PWM_RESOLUTION 8

int speedValue = 150;

void setup() {
  Serial.begin(115200);

  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(STBY, OUTPUT);

  // Setup PWM for ESP32
  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(PWMB, PWM_CHANNEL);

  digitalWrite(STBY, HIGH);   // Enable driver

  Serial.println("Motor Test Ready");
  Serial.println("F = Forward");
  Serial.println("B = Backward");
  Serial.println("S = Stop");
  Serial.println("0-9 = Speed Control");
}

void setSpeed(int speed) {
  ledcWrite(PWM_CHANNEL, speed);  // 0–255
}

void loop() {

  if (Serial.available()) {

    char cmd = Serial.read();

    if (cmd == 'F') {
      digitalWrite(BIN1, HIGH);
      digitalWrite(BIN2, LOW);
      setSpeed(speedValue);
      Serial.println("Forward");
    }

    else if (cmd == 'B') {
      digitalWrite(BIN1, LOW);
      digitalWrite(BIN2, HIGH);
      setSpeed(speedValue);
      Serial.println("Backward");
    }

    else if (cmd == 'S') {
      setSpeed(0);
      Serial.println("Stop");
    }

    else if (cmd >= '0' && cmd <= '9') {

      int level = cmd - '0';
      speedValue = map(level, 0, 9, 0, 255);

      setSpeed(speedValue);

      Serial.print("Speed set to: ");
      Serial.println(speedValue);
    }
  }
}