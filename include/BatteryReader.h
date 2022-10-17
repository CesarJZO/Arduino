#include "Circuit.h"

/**
 * A battery charge tester
 */
class BatteryReader : Circuit
{
private:
    /**
     * Prints to the serial port the current charge info
     */
    void printInfo(double percentage, double volts);

public:
    /**
     * Sets an analog pin as input, three digital pins as output and a serial port
     */
    void setup() override;
    /**
     * Turns green, yellow or red depending on the battery charge
     */
    void loop() override;
};
