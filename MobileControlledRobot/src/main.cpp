#include <Arduino.h>

// LED Config
int led1 = 4;
int led2 = 5;
int led3 = 18;
int buzzer = 19;

// PWM config for buzzer
#define BUZZER_CHANNEL 0
#define PWM_RESOLUTION 8

// Musical notes
#define C4 262
#define D4 294
#define E4 330
#define F4 349
#define G4 392
#define A4 440

// Melody
int melody[] = {
  C4,C4,G4,G4,A4,A4,G4,
  F4,F4,E4,E4,D4,D4,C4,

  G4,G4,F4,F4,E4,E4,D4,
  G4,G4,F4,F4,E4,E4,D4,

  C4,C4,G4,G4,A4,A4,G4,
  F4,F4,E4,E4,D4,D4,C4
};

int duration[] = {
  400,400,400,400,400,400,800,
  400,400,400,400,400,400,800,

  400,400,400,400,400,400,800,
  400,400,400,400,400,400,800,

  400,400,400,400,400,400,800,
  400,400,400,400,400,400,800
};

int notes = sizeof(melody) / sizeof(melody[0]);

// LED logic
void playLED(int note){
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);

  if(note <= D4){
    digitalWrite(led1, HIGH);
  }
  else if(note <= G4){
    digitalWrite(led2, HIGH);
  }
  else{
    digitalWrite(led3, HIGH);
  }
}

// ESP32 tone replacement
void playTone(int frequency) {
  ledcWriteTone(BUZZER_CHANNEL, frequency);
}

void stopTone() {
  ledcWriteTone(BUZZER_CHANNEL, 0);
}

void setup() {

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  // Setup buzzer PWM
  ledcSetup(BUZZER_CHANNEL, 2000, PWM_RESOLUTION); // freq doesn't matter much
  ledcAttachPin(buzzer, BUZZER_CHANNEL);

  Serial.begin(115200);
  Serial.println("Twinkle Twinkle LED Dance 🎵");
}

void loop() {

  for(int i = 0; i < notes; i++){

    playLED(melody[i]);

    playTone(melody[i]);     // ✅ replaced tone()
    delay(duration[i]);

    stopTone();              // ✅ replaced noTone()
    delay(50);
  }

  delay(2000);
}