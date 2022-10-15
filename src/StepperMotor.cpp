#include <Arduino.h>
#include "nanopins.h"
#include "StepperMotor.h"

void StepperMotor::setup()
{
    Serial.begin(BAUD);
    Serial.setTimeout(2000);
    for (int p = D2; p <= D8; p++)
        pinMode(p, p < D5 ? INPUT : OUTPUT);
}

void StepperMotor::loop()
{
    String state = Serial.readString();
    if (state.equals("scw"))
        step(simpleStepCW, 4);
    else if (state.equals("scc"))
        step(simpleStepCC, 4);
    else if (state.equals("fcw"))
        step(fullStepCW, 4);
    else if (state.equals("fcc"))
        step(fullStepCC, 4);
    else if (state.equals("hcw"))
        step(halfStepCW, 8);
    else if (state.equals("hcc"))
        step(halfStepCC, 8);
}

void StepperMotor::step(const int config[][4], int steps)
{
    for (int i = 0; i < 512; i++)
    {
        for (int i = 0; i < steps; i++)
        {
            for (int p = D5; p <= D8; p++)
                digitalWrite(p, config[i][p - 5]);
            delay(12);
        }
    }

    for (int p = D5; p <= D8; p++)
        digitalWrite(p, LOW);
}
