#include "ultrasonic.h"
#include "msp430g2553.h"

void UltrasonicInit()
{
    P1DIR |= TRIG_PIN; // Set trigger pin as output
    TA1CTL = TASSEL_2 + ID_0 + MC_2; // Increment timer TA1R every microsecond (SMCLK + no divider + continuous mode)
}

float UltrasonicGetDistance()
{
    int echoDuration;
    float distance;

    P1OUT |= TRIG_PIN; // Trigger high

    __delay_cycles(20);
    
    P1OUT &= ~TRIG_PIN; // Trigger low
    
    while ((P1IN & ECHO_PIN) == 0); // Wait until echo pulse starts
    TA1R = 0;
    while ((P1IN & ECHO_PIN) > 0); // Wait for the end of echo pulse
    
    echoDuration = TA1R; // Timer value is the echo duration
    distance = echoDuration / 58.0; // Distance is echo duration divided by 58
    return distance;
}
