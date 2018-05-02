// Example usage for Tangible_Sensor_Library library by Dan Levine.

#include "Tangible_Sensor_Library.h"


/* Create sensor library with setup sensors and actuators */
Tangible_Sensor_Library senseLib(sensors,actuators);

//Initialize workspace of pins non I2C pins using, e.g., Photon LED
int led = D7;
int potPin = A3;
int reading;
/*Sets up your code*/
void setup() {
    // Initialize pinModes
    pinMode(potPin, INPUT);
    Particle.variable("reading",  &reading, INT);
    // Initialize Sensor library. Starts I2C automatically.
    senseLib.begin();
}

void loop() {
    reading = analogRead(potPin);
    // reading = 10;
    Particle.publish("Sending reading!",String(reading),60);
    delay(1000);
}
