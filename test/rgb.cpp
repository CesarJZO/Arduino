#include <Arduino.h>
#include "nanopins.h"
#include "rgb.h"

void RGB::setup()
{
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
    pinMode(D4, OUTPUT);
}

void RGB::loop()
{
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
    digitalWrite(D4, LOW);
}
