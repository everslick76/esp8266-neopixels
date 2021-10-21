#include <EspOta.h>
#include <EspSerial.h>

static EspSerial serial;

void EspOta::startOta() {
  serial.println("INIT: Setting up OTA");

  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH)
      type = "sketch";
    else // U_SPIFFS
      type = "filesystem";

    // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
    serial.println("OTA: Start updating " + type);
  });

  ArduinoOTA.onEnd([]() {
    serial.println("\nEnd");
  });

  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("OTA: Progress: %u%%\r", (progress / (total / 100)));
  });

  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("OTA: Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("OTA: Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("OTA: Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("OTA: Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("OTA: End Failed");
  });

  ArduinoOTA.begin();
  serial.print("INIT: Over The Air firmware flashing available at ");
  serial.print(WiFi.localIP().toString());
  serial.println(":8266");
  serial.println("INIT: OTA setup complete.");
  serial.println("");
}
