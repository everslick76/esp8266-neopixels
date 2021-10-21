#include <EspHttp.h>
#include <EspSerial.h>

int port = 80;
String html = "";
ESP8266WebServer httpServer(port);
static EspSerial serial;

void handleRoot() {
  httpServer.send(200, "text/html", html);
}

void handleNotFound() {
  httpServer.send(404, "text/html", "404: File Not Found");
}

void EspHttp::startHttp() {

  serial.println("INIT: Setting up HTTP server");
  httpServer.on("/", handleRoot);
  httpServer.onNotFound(handleNotFound);

  httpServer.begin();
  serial.print("INIT: HTTP daemon available at ");
  serial.println(WiFi.localIP().toString());
  serial.println("INIT: HTTP setup complete.");
  serial.println("");

}

void EspHttp::handleClient() {
  httpServer.handleClient();
}

void EspHttp::writeHtml(String text) {
  html = "<html><body><h1>ESP-12F</h1><p>" + text + "</p></body></html>";
}
