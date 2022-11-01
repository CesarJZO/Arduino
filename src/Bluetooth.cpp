#include <Arduino.h>
#include <SoftwareSerial.h>
#include "nanopins.h"
#include "Bluetooth.h"

SoftwareSerial bluetooth(D3, D2); // R | T

void Bluetooth::setup()
{
    Serial.begin(BAUD);
    bluetooth.begin(BAUD);
    for (int p = D2; p <= D7; p++)
        pinMode(p, p == D2 ? INPUT : OUTPUT);
}

void Bluetooth::loop()
{
    if (bluetooth.available())
    {
        state = bluetooth.readString();
        Serial.println(state);
    }

    if (state.equals("scw"))
        stepper.step(stepper.simpleStepCW, 4);
    else if (state.equals("scc"))
        stepper.step(stepper.simpleStepCC, 4);
    else if (state.equals("fcw"))
        stepper.step(stepper.fullStepCW, 4);
    else if (state.equals("fcc"))
        stepper.step(stepper.fullStepCC, 4);
    else if (state.equals("hcw"))
        stepper.step(stepper.halfStepCW, 8);
    else if (state.equals("hcc"))
        stepper.step(stepper.halfStepCC, 8);
}
