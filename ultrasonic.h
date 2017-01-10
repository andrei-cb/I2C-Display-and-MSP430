#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#define TRIG_PIN BIT1
#define ECHO_PIN BIT2

float UltrasonicGetDistance();
void UltrasonicInit();

#endif
