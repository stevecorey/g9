#include <Encoder.h>

// Change these pin numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder knob(3, 2);
//   avoid using pins with LEDs attached
int led01 = 4;
int led02 = 5;
int led03 = 6;
int led04 = 7;
int led05 = 8;
int led06 = 9;
int led07 = 10;
int led08 = 11;
int led09 = 12;
int led10 = 13;
int led11 = 18;
int led12 = 19;
int led13 = 20;
int led14 = 21;
int led15 = 22;
int led16 = 23;


void setup() {
  pinMode(led01, OUTPUT);
  pinMode(led02, OUTPUT);
  pinMode(led03, OUTPUT);
  pinMode(led04, OUTPUT);
  pinMode(led05, OUTPUT);
  pinMode(led06, OUTPUT);
  pinMode(led07, OUTPUT);
  pinMode(led08, OUTPUT);
  pinMode(led09, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);
  pinMode(led12, OUTPUT);
  pinMode(led13, OUTPUT);
  pinMode(led14, OUTPUT);
  pinMode(led15, OUTPUT);
  pinMode(led16, OUTPUT);
}

byte enc = 0x40;
byte addr = 0xc0;
byte first = 0x0f;
byte pi = 0xc0;

void loop() {
  long n;
  n = knob.read();
  if (n > 255) {
    n = 255;
    knob.write(255);
  }
  if (n < 0) {
    n = 0;
    knob.write(0);
  }

  //    Serial.write(n + enc + pi);
  //    knob.write(0);
  //  if (Serial.available() > 0) {
  int data = n / 16;
  // Turn off all LEDs first
  digitalWrite(led01, LOW);
  digitalWrite(led02, LOW);
  digitalWrite(led03, LOW);
  digitalWrite(led04, LOW);
  digitalWrite(led05, LOW);
  digitalWrite(led06, LOW);
  digitalWrite(led07, LOW);
  digitalWrite(led08, LOW);
  digitalWrite(led09, LOW);
  digitalWrite(led10, LOW);
  digitalWrite(led11, LOW);
  digitalWrite(led12, LOW);
  digitalWrite(led13, LOW);
  digitalWrite(led14, LOW);
  digitalWrite(led15, LOW);
  digitalWrite(led16, LOW);

  //Turn back on only the necessary ones
  Serial.print(data);
  switch (data) {
    case 15:
      digitalWrite(led16, HIGH);
    case 14:
      digitalWrite(led15, HIGH);
    case 13: // doing nothing
      digitalWrite(led14, HIGH);
    case 12: // doing nothing
      digitalWrite(led13, HIGH);
    case 11: // doing nothing
      digitalWrite(led12, HIGH);
    case 10: // doing nothing
      digitalWrite(led11, HIGH);
    case 9:
      digitalWrite(led10, HIGH);
    case 8:
      digitalWrite(led09, HIGH);
    case 7:
      digitalWrite(led08, HIGH);
    case 6:
      digitalWrite(led07, HIGH);
    case 5:
      digitalWrite(led06, HIGH);
    case 4:
      digitalWrite(led05, HIGH);
    case 3:
      digitalWrite(led04, HIGH);
    case 2:
      digitalWrite(led03, HIGH);
    case 1:
      digitalWrite(led02, HIGH);
    case 0:
      digitalWrite(led01, HIGH);
      break;
    default:
      break;
  }
}
