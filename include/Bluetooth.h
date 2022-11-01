#include "StepperMotor.h"

class Bluetooth : Circuit
{
private:
    StepperMotor stepper;
    String state;
public:
    void setup() override;
    void loop() override;
};
