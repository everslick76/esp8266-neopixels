#ifndef EspSerial_h
#define EspSerial_h

#include <Arduino.h>

class EspSerial {

  public:
    void startSerial();
    void print(String text);
    void println(String text);
};

#endif
