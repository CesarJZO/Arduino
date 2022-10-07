#include <Arduino.h>
#include <nanopins.h>
#include <StepperMotor.h>

void StepperMotor::setup()
{
    for (int p = D2; p <= D8; p++)
        pinMode(p, p < D5 ? INPUT : OUTPUT);
}

void StepperMotor::loop()
{
    currentState = getBinaryValue(D4, D3, D2);
    
    switch (currentState)
    {
        default:break;
        case 0x001: step(simpleStepCW, 4); break;
        case 0x010: step(simpleStepCC, 4); break;
        case 0x011: step(fullStepCW, 4); break;
        case 0x100: step(fullStepCC, 4); break;
        case 0x101: step(halfStepCW, 8); break;
        case 0x110: step(halfStepCC, 8); break;
    }
}

int8_t StepperMotor::getBinaryValue(int pin0, int pin1, int pin2)
{
    int bin = 0;

    if (digitalRead(pin0) == HIGH)
        bin += 1;
    if (digitalRead(pin1) == HIGH)
        bin += 2;
    if (digitalRead(pin2) == HIGH)
        bin += 4;
    
    return bin;
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
    delay(2000);
}
