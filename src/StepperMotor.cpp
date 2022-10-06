#include <Arduino.h>
#include <nanopins.h>
#include <StepperMotor.h>

int delayTime = 50;

void StepperMotor::setup()
{
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
    pinMode(D4, OUTPUT);
    pinMode(D5, OUTPUT);
}

void StepperMotor::loop()
{
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
    digitalWrite(D4, LOW);
    digitalWrite(D5, LOW);
    delay(delayTime);
    digitalWrite(D2, LOW);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, LOW);
    digitalWrite(D5, LOW);
    delay(delayTime);
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
    digitalWrite(D4, HIGH);
    digitalWrite(D5, LOW);
    delay(delayTime);
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
    digitalWrite(D4, LOW);
    digitalWrite(D5, HIGH);
    delay(delayTime);
}
