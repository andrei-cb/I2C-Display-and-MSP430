#include "ultrasonic.h"
#include "msp430g2553.h"

void UltrasonicInit()
{
    P1DIR |= TRIG_PIN; //set trigger pin as output
    TA1CTL = TASSEL_2 + ID_0 + MC_2; //increment timer TA1R every microsecond
}

float UltrasonicGetDistance()
{
    int echoDuration;
    float distance;

    P1OUT |= TRIG_PIN; // trigger high

    __delay_cycles(20);
    
    P1OUT &= ~TRIG_PIN; // trigger  low
    
    while ((P1IN & ECHO_PIN) == 0); //wait until echo pulse starts
    TA1R = 0;
    while ((P1IN & ECHO_PIN) > 0); //wait for the end of echo pulse
    
    echoDuration = TA1R; //timer value is the echo duration
    distance = echoDuration / 58.0; //distance is echo duration divided by 58
    return distance;
}
