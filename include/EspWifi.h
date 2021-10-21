#ifndef EspWifi_h
#define EspWifi_h

#include <ESP8266WiFi.h>

class EspWifi {

  public:
    void startDynamicIp();
    void startStaticIp(IPAddress ip);

};

#endif
