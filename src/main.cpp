#include <Arduino.h>
#include <StepperMotor.h>

/**
 * Current circuit to run
 */
StepperMotor c;

/**
 * Run once
 */
void setup() { c.setup(); }

/**
 * Run repeatedly
 */
void loop() { c.loop(); }
