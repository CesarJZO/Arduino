#include <Circuit.h>

/**
 * Using 4 LEDs, count from 0 to 15
 */
class BinaryCounter : Circuit
{
private:
	/**
	 * Counter variable
	 */
	int i = 0;
	/**
	 * The delay time
	 */
	const int time = 1000;

public:
	/**
	 * Sets 4 pins for each LED
	 */
	void setup() override;
	/**
	 * Counts through 0 to 15
	 */
	void loop() override;
};
