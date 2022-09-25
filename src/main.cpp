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


class BinaryCounter : Circuit {
private:
	/**
	 * Counter variable
	 */
	int i = 0;
	/**
	 * The delay time
	 */
	int time = 1000;

public:
	void start() {
		pinMode(D2, OUTPUT);
		pinMode(D3, OUTPUT);
		pinMode(D4, OUTPUT);
		pinMode(D5, OUTPUT);
		Serial.begin(9600);
	}

	void update() {
		delay(time);

		digitalWrite(D2, i % 2 > 0 ? HIGH : LOW);
		digitalWrite(D3, i % 4 > 1 ? HIGH : LOW);
		digitalWrite(D4, i % 8 > 3 ? HIGH : LOW);
		digitalWrite(D5, i % 16 > 7 ? HIGH : LOW);

		Serial.println(i);
		i++;

		// if (i == 16) i = 0;
	}
};

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
