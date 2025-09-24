
#pragma once


#include <Arduino.h>
#include "Adafruit_NeoPixel.h"


#define RGB_LED_NUM 3

class TrioDriveLEDs {
    public:
        TrioDriveLEDs() {};
        void begin() { strip.begin(); strip.clear(); strip.show(); };
        void setColor(uint32_t color, uint8_t led=-1){
            if (led < 0)
                strip.fill(color);
            else
                strip.setPixelColor(led, color);
            show();
        };
        void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t led=-1) {
            if (led < 0)
                strip.fill(strip.Color(r, g, b));
            else
                strip.setPixelColor(led, r, g, b);
            show();
        };
        void show() { strip.show(); };
        
        Adafruit_NeoPixel strip = Adafruit_NeoPixel(RGB_LED_NUM, LED_MCU_PIN, NEO_GRB + NEO_KHZ800);
};
