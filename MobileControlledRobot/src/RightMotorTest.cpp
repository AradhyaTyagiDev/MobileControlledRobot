#include <Arduino.h>

#define PWMA 18
#define AIN1 19
#define AIN2 21
#define STBY 4

// PWM config
#define PWM_CHANNEL 0
#define PWM_FREQ 1000
#define PWM_RESOLUTION 8

int speedValue = 150;

void setup() {

  Serial.begin(115200);

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(STBY, OUTPUT);

  // Setup PWM for ESP32
  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(PWMA, PWM_CHANNEL);

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

void moveForward() {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  setSpeed(speedValue);
}

void moveBackward() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  setSpeed(speedValue);
}

void stopMotor() {
  setSpeed(0);
}

void loop() {

  if (Serial.available()) {

    char cmd = Serial.read();

    if (cmd == 'F') {
      moveForward();
      Serial.println("Forward");
    }

    else if (cmd == 'B') {
      moveBackward();
      Serial.println("Backward");
    }

    else if (cmd == 'S') {
      stopMotor();
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