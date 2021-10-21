#include <EspNeopixel.h>

#define PIXELS 20
#define LED 1
#define STRIPPIN D2
#define LEDPIN D3
#define LEDBRIGHTNESS 20
#define STRIPBRIGHTNESS 20

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXELS, STRIPPIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led = Adafruit_NeoPixel(LED, LEDPIN, NEO_GRB + NEO_KHZ800);

int cycle = 65536 / 4; // increase divisor to cycle faster
int offset = round(65536 / 2 / strip.numPixels()); // decrease divisor to shorten spread
int hue = 0;
int pixel = 0;

void EspNeopixel::setup() {
    strip.begin();
    strip.clear();
    strip.setBrightness(STRIPBRIGHTNESS);
    strip.show();
    led.begin();
    led.clear();
    strip.setBrightness(LEDBRIGHTNESS);
    led.show();
}

void EspNeopixel::setStripColor(int pixel, int red, int green, int blue) {
    strip.setPixelColor(pixel, strip.Color(red, green, blue));
    strip.show();
}

void EspNeopixel::setLedColor(int red, int green, int blue) {
    led.setPixelColor(0, strip.Color(red, green, blue)); 
    led.show();
}

void EspNeopixel::sweep(int red, int green, int blue, bool shimmer) {

    for (int i = 0; i <= PIXELS - 1; ++i) {
        // setLedColor(random(10, 200), random(10, 200), random(10, 200));
        strip.clear();
        if (shimmer && i % 2) {
            setStripColor(random(1, PIXELS) - 1, 230, 255, 255);
        }
        setStripColor(i, red, green, blue);
        if (i + 1 < PIXELS) {
            setStripColor(i + 1, red, green, blue);
        }
        if (i + 2 < PIXELS) {
            setStripColor(i + 2, red, green, blue);
        }
        strip.show();
        delay(100);
    }

    for (int j = 19; j --> 0;) {
        // setLedColor(255, 0, 0);
        strip.clear();
        if (shimmer && j % 2) {
            setStripColor(random(1, PIXELS) - 1, 230, 255, 255);
        }
        setStripColor(j, red, green, blue);
        if (j - 1 >= 0) {
            setStripColor(j - 1, red, green, blue);
        }
        if (j - 2 >= 0) {
            setStripColor(j - 2, red, green, blue);
        }
        strip.show();
        delay(100);
    }

    strip.clear();
    // delay(random(100, 3000));
}

void EspNeopixel::rainbowStep() {

    strip.setPixelColor(pixel, strip.ColorHSV(hue*8+offset*pixel));
    strip.show();
    delay(1);
    if (hue <= cycle) {
        hue++;
    } else {
        hue = 0;
    }
    if (pixel <= strip.numPixels() - 1) {
        pixel++;
    } else {
        pixel = 0;
    }
}

void EspNeopixel::rainbow() {

    int cycle = 65536 / 4; // increase divisor to cycle faster
    int offset = round(65536 / 2 / strip.numPixels()); // decrease divisor to shorten spread
    for (int hue = 0; hue <= cycle; hue++) {
        for (int pixel = 0; pixel <= strip.numPixels() - 1; pixel++) {
            strip.setPixelColor(pixel, strip.ColorHSV(hue*8+offset*pixel));
        }
        strip.show();
        delay(1);
    }
}

void EspNeopixel::glow() {

    int multiplier = 2; // increase multiplier to cycle faster
    int cycle = 65536 / multiplier;
    for (int hue = 0; hue <= cycle; hue++) {
        strip.fill(strip.ColorHSV(hue*multiplier, 255, 150), 0, strip.numPixels());
        strip.show();
        delay(1);
    }
}

void EspNeopixel::pulse(uint16_t hue, int speed) {

    for (int i = 10; i <= 255; i++) {
        strip.fill(strip.ColorHSV(hue, 255, i), 0, strip.numPixels());
        strip.show();
        delay(speed);
    }
    for (int j = 255; j --> 10;) {
        strip.fill(strip.ColorHSV(hue, 255, j), 0, strip.numPixels());
        strip.show();
        delay(speed);
    }    
}

int random(int min, int max) {
    return rand() % min + max;
}
