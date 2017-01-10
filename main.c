#include "lcd.h"
#include "ultrasonic.h"
#include "stdio.h"
#include "msp430g2553.h"

int main()
{
    WDTCTL = WDTPW + WDTHOLD; // Stop watchdog
    
    _EINT(); // enable interrupts
    
    UltrasonicInit(); //initialize ultrasonic module
    LcdInit(); // initialize LCD display

    float dist = 0;
    char text[20]; // buffer

    while (1)
    {
        dist = UltrasonicGetDistance();

        if (0 < dist && dist < 130)
            snprintf(text, sizeof(text), "Distanta: %-7.1f", dist);
        else
            snprintf(text, sizeof(text), "Distanta: %-9s", "none");

        LcdWriteString(text);
        LcdSetPosition(1,1);

        __delay_cycles(200000);
    }

return 0;   

}
