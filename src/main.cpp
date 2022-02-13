#include <EspNeopixel.h>

// pins
#define NEOSTRIP 4
#define NEOLED 0
#define BUTTON 16
// fade speed
#define FAST 1
#define MEDIUM 13
#define SLOW 40

// bool high = true;

EspNeopixel pixels;

//setup and main loop
void setup() {

  srand(time(NULL));

  // pin setup
  // 0 = D3
  // 1 = TX
  // 2 = D4
  // 3 = RX
  // 4 = D2
  // 5 = D1
  // 12 = D6
  // 13 = D7
  // 14 = D5
  // 15 = D8
  // 16 = D0
  // 17 = A0
  // pinMode(NEOLED, OUTPUT); // see EspNeopixel.h
  // pinMode(1, OUTPUT);
  // pinMode(2, OUTPUT);
  // pinMode(3, OUTPUT);
  // pinMode(NEOSTRIP, OUTPUT); // see EspNeopixel.h
  pinMode(5, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(BUTTON, INPUT);

  // digitalWrite(NEOLED, LOW); // see EspNeopixel.h
  // digitalWrite(1, LOW);
  // digitalWrite(2, LOW);
  // digitalWrite(3, LOW);
  // digitalWrite(NEOSTRIP, LOW); // see EspNeopixel.h
  digitalWrite(5, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(14, LOW);
  digitalWrite(15, LOW);
  // digitalWrite(16, LOW);

  // startup
  pixels.setup();
}

void loop() {

  //flashLed(16, 500);

  // if (high) {
  //   digitalWrite(LED, HIGH);
  //   high = false;
  // } else {
  //   digitalWrite(LED, LOW);
  //   high = true;
  // }

  int button = digitalRead(BUTTON);
  if (button == HIGH) {
    pixels.sweep(200, 0, 0, true);
  }

  pixels.rainbowStep();

  // pixels.glow();
  // pixels.sweep(200, 0, 0, true);
  // pixels.pulse(50500, SLOW);
  // pixels.sweep(200, 0, 0, true);
}
