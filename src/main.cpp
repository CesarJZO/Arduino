#include <Arduino.h>
#include "pins.h"

#include "BinaryCounter.h"

/**
 * Current circuit to run
 */
BinaryCounter c;

/**
 * Run once
 */
void setup() {
	c.setup();
}

/**
 * Run repeatedly
 */
void loop() {
	c.loop();
}
