#include <Arduino.h>
#include "nanopins.h"
#include "InputAsBin.h"

void InputAsBin::setup()
{
    pinMode(D2, INPUT);
    pinMode(D3, INPUT);
    pinMode(D4, INPUT);
    Serial.begin(BAUD);
}

int getBinaryValue(int pin0, int pin1, int pin2)
{
    int bin = 0;

    if (digitalRead(pin0) == LOW)
        bin += 1;
    if (digitalRead(pin1) == LOW)
        bin += 2;
    if (digitalRead(pin2) == LOW)
        bin += 4;
    
    return bin;
}

void InputAsBin::loop()
{
    int value;
    // bitWrite(value, 0, digitalRead(D2));
    bitWrite(value, 1, digitalRead(D3));

    value = getBinaryValue(D4, D3, D2);

    Serial.println(value);
    delay(500);
}
