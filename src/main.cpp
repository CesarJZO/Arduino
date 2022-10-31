#include <Arduino.h>
#include "BatteryReader.h"

BatteryReader c;

void setup() { c.setup(); }

/**
 * Run repeatedly
 */
void update() { c.loop(); }
