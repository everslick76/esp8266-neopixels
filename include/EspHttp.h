#ifndef EspHttp_h
#define EspHttp_h

#include <ESP8266WebServer.h>

class EspHttp {

  public:
    void startHttp();
    void handleClient();
    void writeHtml(String text);

};

#endif
