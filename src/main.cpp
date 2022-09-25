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
	c.start();
}

/**
 * Run repeatedly
 */
void loop() {
	c.update();
}
