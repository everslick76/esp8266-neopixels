#include <EspWifi.h>
#include <EspSerial.h>

const char* ssid = "";
const char* password = "";

static EspSerial serial;

void start() {

  WiFi.mode(WIFI_STA);
  WiFi.hostname("ESP-12F");
  serial.print("INIT: Connecting to wifi");
  WiFi.begin(ssid, password);

  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    serial.print(".");
  }
  serial.println("");
  serial.print("INIT: Successfully connected to ");
  serial.println(ssid);

  serial.print("INIT: ");
  serial.print(WiFi.hostname());
  serial.print(" is using IP address: ");
  serial.println(WiFi.localIP().toString());

  serial.println("INIT: Wifi connection complete.");
  serial.println("");
}

void EspWifi::startDynamicIp() {

  serial.println("INIT: Initializing dynamic IP.");
  start();
}

void EspWifi::startStaticIp(IPAddress ip) {

  IPAddress gateway(192,168,0,1);
  IPAddress subnet(255,255,255,0);

  serial.println("INFO: Initializing static IP.");
  WiFi.config(ip, gateway, subnet);
  start();
}
