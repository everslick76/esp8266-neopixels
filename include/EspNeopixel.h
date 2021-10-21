#define EspNeopixel_h

#include <Adafruit_NeoPixel.h>

class EspNeopixel {

    public:
        void setup();
        void setStripColor(int pixel, int red, int green, int blue);
        void setLedColor(int red, int green, int blue);
        void sweep(int red, int green, int blue, bool shimmer);
        void rainbow();
        void rainbowStep();
        void glow();
        void pulse(uint16_t hue, int speed);
};
