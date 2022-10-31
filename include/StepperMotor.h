#include "Circuit.h"

class StepperMotor : Circuit
{
public:
    int currentState;

    /**
     * Simple step clock wise
     */
    const int simpleStepCW[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}};

    /**
     * Simple step counter-clock wise
     */
    const int simpleStepCC[4][4] = {
        {0, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 1, 0, 0},
        {1, 0, 0, 0}};

    /**
     * Full step clock wise
     */
    const int fullStepCW[4][4] = {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {1, 0, 0, 1}};

    /**
     * Full step counter-clock wise
     */
    const int fullStepCC[4][4] = {
        {0, 0, 1, 1},
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {1, 0, 0, 1}};

    /**
     * Half step clock wise configuration
     */
    const int halfStepCW[8][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1},
        {1, 0, 0, 1}};

    /**
     * Half step counter-clock wise
     */
    const int halfStepCC[8][4] = {
        {0, 0, 0, 1},
        {0, 0, 1, 1},
        {0, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 1}};
    /**
     * Sets the input and output pins
     */
    void setup() override;
    /**
     * Depending on the dip switch config, it will run different steps
     */
    void loop() override;
    /**
     * Executes the steps
     * @param config The type of steps to run
     * @param steps The number of steps
     */
    void step(const int config[][4], int steps);
};
