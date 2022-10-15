#include <Arduino.h>
#include "nanopins.h"
#include "BinaryCounter.h"

void BinaryCounter::setup()
{
    for (int p = D2; p <= D5; p++)
        pinMode(p, OUTPUT);

    Serial.begin(BAUD);
}

void BinaryCounter::loop()
{
    delay(time);

    int n = 2;
    for (int p = D2; p <= D5; p++)
    {
        digitalWrite(p, i % n > n / 2 - 1 ? HIGH : LOW);
        n *= 2;
    }

    Serial.println(i);
    i++;
    if (i == 16)
        i = 0;
}
