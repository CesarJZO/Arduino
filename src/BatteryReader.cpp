#include <Arduino.h>
#include "nanopins.h"
#include "BatteryReader.h"

void BatteryReader::setup()
{
    pinMode(PC0, INPUT);
    for (int p = D2; p <= D4; p++)
        pinMode(p, OUTPUT);
    Serial.begin(BAUD);
}

void BatteryReader::loop()
{
    int read = analogRead(PC0);
    double p = (double) read / 307 * 100;
    double v = p * 0.015;

    int pin;

    if (v >= 1.5)
        pin = D4;
    else if (v > 1.3)
        pin = D3;
    else
        pin = D2;

    for (int p = D2; p <= D4; p++)
        digitalWrite(p, p == pin ? HIGH : LOW);

    printInfo(p, v);

    delay(1000);
}

void BatteryReader::printInfo(double p, double v)
{
    Serial.print("Current charge: ");
    Serial.print(p > 100 ? 100.00 : p);
    Serial.print("\% with ");
    Serial.print(v);
    Serial.println(" volts");
}
