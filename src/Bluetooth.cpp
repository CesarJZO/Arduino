#include <Arduino.h>
#include <SoftwareSerial.h>
#include "nanopins.h"
#include "Bluetooth.h"

SoftwareSerial bluetooth(D3, D2);

void Bluetooth::setup()
{
    Serial.begin(BAUD);
    bluetooth.begin(BAUD);
    for (int p = D2; p < D7; p++)
        pinMode(p, p == D2 ? INPUT : OUTPUT);
}

void Bluetooth::loop()
{
    int state;
    if (bluetooth.available())
        state = bluetooth.read();

    switch (state)
    {
        case 1: stepper.step(stepper.simpleStepCW, 4); break;
        case 2: stepper.step(stepper.simpleStepCC, 4); break;
        case 3: stepper.step(stepper.fullStepCW,   4); break;
        case 4: stepper.step(stepper.fullStepCC,   4); break;
        case 5: stepper.step(stepper.halfStepCW,   8); break;
        case 6: stepper.step(stepper.halfStepCC,   8); break;
    }
}
