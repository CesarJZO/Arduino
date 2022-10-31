#include <Arduino.h>
#include "Bluetooth.h"

Bluetooth c;

void setup() { c.setup(); }

/**
 * Run repeatedly
 */
void loop() { c.loop(); }
