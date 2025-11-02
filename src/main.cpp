
#include <Arduino.h>
#include "SimpleFOC.h"
#include "SimpleFOCDrivers.h"
#include "encoders/kth78xx/MagneticSensorKTH7812.h"

#include "leds.h"


TrioDriveLEDs leds;
int current_led = 0;

Commander commander = Commander(Serial);

SPIClass SPI_Sensor1 = SPIClass(COPI1_PIN, CIPO1_PIN, SCLK1_PIN);
MagneticSensorKTH7812 sensor1 = MagneticSensorKTH7812(SENSOR1_nCS_PIN, false, false, SPISettings(1000000, KTH7812_BITORDER, SPI_MODE3));
BLDCDriver3PWM driver1 = BLDCDriver3PWM(M1_INU_PIN, M1_INV_PIN, M1_INW_PIN, M1_EN_PIN);
BLDCMotor motor1 = BLDCMotor(11);
void onMotor1(char* cmd){ commander.motor(&motor1,cmd); }


SPIClass SPI_Sensor2 = SPIClass(COPI2_PIN, CIPO2_PIN, SCLK2_PIN);
MagneticSensorKTH7812 sensor2 = MagneticSensorKTH7812(SENSOR2_nCS_PIN, false, false, KTH7812SPISettings);

/*
  Arduino functions, setup() and loop()
*/

void setup() {
    pinMode(M1_nSLEEP_PIN, OUTPUT);
    digitalWrite(M1_nSLEEP_PIN, LOW);
    pinMode(M2_nSLEEP_PIN, OUTPUT);
    digitalWrite(M2_nSLEEP_PIN, LOW);
    pinMode(M3_nSLEEP_PIN, OUTPUT);
    digitalWrite(M3_nSLEEP_PIN, LOW);
    // init debug on USB serial
    delay(500);
    Serial.begin(115200);
    SimpleFOCDebug::enable(&Serial);
    Serial.println("TrioDrive firmware starting...");

    leds.begin();
    leds.strip.clear();
    leds.strip.setBrightness(50);
    leds.setColor(0, 0, 255); // blue
    commander.verbose = VerboseMode::user_friendly;

    delay(1000);
    
    Serial.println("Starting setup...");
    sensor1.init(&SPI_Sensor1);
    sensor2.init(&SPI_Sensor2);
    delay(1000);

    motor1.linkDriver(&driver1);
    motor1.linkSensor(&sensor2); // TODO change when sensor 1 is working!!
    driver1.voltage_power_supply = 8.0f;
    driver1.voltage_limit = 7.8f;
    motor1.voltage_limit = driver1.voltage_limit / 2.0f;
    motor1.controller = MotionControlType::torque;
    motor1.torque_controller = TorqueControlType::voltage;
    motor1.foc_modulation = FOCModulationType::SinePWM;
    motor1.voltage_sensor_align = 4.0f;
    commander.add('M', onMotor1, "motor1 commands");

    driver1.init();
    motor1.init();
    digitalWrite(M1_nSLEEP_PIN, HIGH); // wake up motor drivers
    delayMicroseconds(100);
    motor1.initFOC();

    Serial.println("Setup complete.");    
    delay(1000);
    
    leds.setColor(0, 255, 0); // green
}


unsigned long timestamp = 0;
uint32_t loop_counter = 0;

void loop() {
    motor1.move();
    motor1.loopFOC();
    loop_counter++;
    //sensor2.update();
    unsigned long now = millis();
    if (now - timestamp > 1000 || timestamp > now) {
        float angle = sensor2.getAngle();
        float velocity = sensor2.getVelocity();
        Serial.print("A ");
        Serial.print(angle);
        Serial.print("  V ");
        Serial.print(velocity);
        Serial.print("  L ");
        Serial.println(loop_counter);
        loop_counter = 0;
        leds.strip.clear();
        leds.setColor(0, 255, 0, current_led);
        current_led = (current_led + 1) % RGB_LED_NUM;
        timestamp = now;
    }
    //delayMicroseconds(100);
    commander.run();
}

