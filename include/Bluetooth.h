#include "Circuit.h"
#include "StepperMotor.h"
class Bluetooth : Circuit
{
private:
    StepperMotor stepper;
public:
    void setup() override;
    void loop() override;
};
