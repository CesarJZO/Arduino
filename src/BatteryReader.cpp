#include <Arduino.h>
#include "nanopins.h"
#include "BatteryReader.h"

#define GREEN D2
#define YELLOW D3
#define RED D4

void BatteryReader::setup()
{
    pinMode(A1, INPUT);
    for (int p = 0; p <= D4; p++)
        pinMode(p, OUTPUT);
    Serial.begin(BAUD);
}

void BatteryReader::loop()
{
    int read = digitalRead(A1);
    float percentage = read / 1024;
    float volts = 5 * percentage;

    printInfo(percentage, volts);

    digitalWrite(GREEN, volts >= 1.4);
    digitalWrite(YELLOW, volts > 1.3 && volts < 1.4);
    digitalWrite(RED, volts <= 1.3);

    delay(1000);
}

void BatteryReader::printInfo(float p, float v)
{
    Serial.print("Current charge: ");
    Serial.print(p);
    Serial.print("\% at ");
    Serial.print(v);
    Serial.println("volts");
}
