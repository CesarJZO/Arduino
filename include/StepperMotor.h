#include "Circuit.h"

/**
 *
 */
class StepperMotor : Circuit
{
private:
    int currentState;

public:
    /**
     *
     */
    void setup() override;
    /**
     *
     */
    void loop() override;
};
