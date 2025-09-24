
#include <Arduino.h>
#include "SimpleFOC.h"
#include "SimpleFOCDrivers.h"

#include "leds.h"





TrioDriveLEDs leds;
int current_led = 0;


/*
  Arduino functions, setup() and loop()
*/

void setup() {
    // init debug on USB serial
    Serial.begin(115200);
    leds.begin();
    leds.strip.setBrightness(50);
    leds.setColor(0, 0, 255); // blue

    delay(1000);

    Serial.println("Setup complete.");
    leds.setColor(0, 255, 0); // green
}




void loop() {
    Serial.println("Hello, world!");
    delay(1000);
    leds.strip.clear();
    leds.setColor(0, 255, 0, current_led);
    current_led = (current_led + 1) % RGB_LED_NUM;
}

