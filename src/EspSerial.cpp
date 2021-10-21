#include <EspSerial.h>

boolean active = true;
int baud = 115200;

void EspSerial::startSerial() {

  if (active) {
    Serial.begin(baud);
  }
}

void EspSerial::print(String text) {

  if (active) {
    Serial.print(text);
  }
}

void EspSerial::println(String text) {

  if (active) {
    Serial.println(text);
  }
}
