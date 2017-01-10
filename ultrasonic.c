#include "ultrasonic.h"

UltrasonicInit()
{
    P1DIR |= TRIG_PIN + ECHO_PIN;
    TA1CTL = TASSEL_2 + ID_0 + MC_2;
}

UltrasonicGetDistance()
{
    int echoDuration;
    float distance;

    P1OUT |= TRIG_PIN;
    P1OUT &= ~TRIG_PIN;
    
    while ((P1IN & ECHO_PIN) == 0);
    TA1R = 0;
    while ((P1IN & ECHO_PIN) > 0);
    
    echoDuration = TA1R;
    distace = echoDuration / 58.0;
    return distace;
}
