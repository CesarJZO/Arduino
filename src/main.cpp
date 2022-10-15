#include <Arduino.h>
#include "BatteryReader.h"

/**
 * Current circuit to run
 */
BatteryReader c;

/**
 * Run once
 */
void setup() { c.setup(); }

/**
 * Run repeatedly
 */
void loop() { c.loop(); }
