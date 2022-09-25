#include <Arduino.h>
#include "pins.h"

class Circuit {
protected:
	/**
	 * Run at the beginning of the program
	 */
	virtual void start();

	/**
	 * Run indefinitely while Arduino is on
	 */
	virtual void update();
};

Circuit c;

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
