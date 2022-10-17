#include <Arduino.h>
#include "nanopins.h"
#include "Empty.h"

void Empty::setup()
{
    pinMode(D5, OUTPUT);
}

void Empty::loop()
{
    digitalWrite(D2, LOW);
}
