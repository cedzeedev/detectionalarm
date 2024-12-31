#include "pitches.h"
int result_motion = 2;
int led_detection = 3;
bool detection_mod = false;
int led_jaune = 4;
int button = 13;
int passive = 6;
int active = 7;
int tempo = 300;
int activate = 1;
int button_activate = 12;
int led_active = 5;
int tempo2 = 400;
void setup() {
  Serial.begin(9600);
  pinMode(result_motion, INPUT);
  pinMode(led_detection, OUTPUT);
  digitalWrite(led_detection, LOW);
  pinMode(led_jaune, OUTPUT);
  pinMode(button, INPUT);
  pinMode(active, OUTPUT);
  pinMode(led_active, OUTPUT);
  pinMode(button_activate, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(button_activate) == 0) {
    activate = activate * -1;
    lockedalarm_music();
  }



  if (activate == 1) {
    digitalWrite(led_active, LOW);
    if (digitalRead(result_motion) == 1) {
      detection_mod = true;
      digitalWrite(led_detection, HIGH);
    } else{
        digitalWrite(led_detection, LOW);
      }

    if (detection_mod) {
      digitalWrite(active, HIGH);
      digitalWrite(led_jaune, HIGH);
      if (digitalRead(button) ==  0) {
        digitalWrite(active, LOW);
        detection_mod = false;
        digitalWrite(led_jaune, LOW);
        stopalarm_music();
        delay(2000);
      }
    } else {
      digitalWrite(led_jaune, LOW);
    }
  } else {
    digitalWrite(led_active, HIGH);
  }

  
}



void stopalarm_music() {
  tone(passive, NOTE_E6, tempo/2);
  delay(tempo/2);
  tone(passive, NOTE_E6, tempo/2);
  delay(tempo);
  tone(passive, NOTE_E6, tempo/2);
  delay(tempo);
  tone(passive, NOTE_C6, tempo/2);
  delay(tempo/2);
  tone(passive, NOTE_E6, tempo);
  delay(tempo);
  tone(passive, NOTE_G6, tempo);
  delay(tempo*2);
  tone(passive, NOTE_G5, tempo);
  delay(tempo*2);


}

void lockedalarm_music() {
  tone(passive, NOTE_C5 , tempo2 / 2);
  delay(tempo2 / 2);
  tone(passive, NOTE_A4 , tempo2 / 2);
  delay(tempo2 / 2);
  tone(passive, NOTE_E4 , tempo2 * 3);
  delay(tempo2 * 3);
  tone(passive, NOTE_C5 , tempo2 / 2);
  delay(tempo2 / 2);
  tone(passive, NOTE_A4 , tempo2 / 2);
  delay(tempo2 / 2);
  tone(passive, NOTE_D4 , tempo2 * 3);
  delay(tempo2 * 3);
  tone(passive, NOTE_C5 , tempo2 / 2);
  delay(tempo2 / 2);
  tone(passive, NOTE_A4 , tempo2 / 2);
  delay(tempo2 / 2);
  tone(passive, NOTE_C4 , tempo2 * 3);
  delay(tempo2 * 3);
  tone(passive, NOTE_B3 , tempo2 / 2);
  delay(tempo2 / 2);
  tone(passive, NOTE_D4 , tempo2 * 2);
  delay(tempo2 * 2);

  
}