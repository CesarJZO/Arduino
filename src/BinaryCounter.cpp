#include <Arduino.h>
#include "pins.h"

#include "BinaryCounter.h"

void BinaryCounter::start() {
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
    pinMode(D4, OUTPUT);
    pinMode(D5, OUTPUT);
    Serial.begin(BAUD);
}

void BinaryCounter::update() {
    delay(time);

    // Formula: i % n / 2 - 1
    digitalWrite(D2, i % 2 > 0 ? HIGH : LOW);
    digitalWrite(D3, i % 4 > 1 ? HIGH : LOW);
    digitalWrite(D4, i % 8 > 3 ? HIGH : LOW);
    digitalWrite(D5, i % 16 > 7 ? HIGH : LOW);

    Serial.println(i);
    i++;
    if (i == 16) i = 0;
}
