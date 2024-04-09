/*
 @author: Abdullah Bagyapan
 @date:   08/04/2024
*/


/*================================== Libraries ==================================*/


// AVR libraries
#include <avr/io.h>
#include <avr/interrupt.h>

// Other modules
#include "CLOCK.h"


/*================================== Functions ==================================*/



int main() {

    // Set PORTB5 (built-in led) as output
    DDRB |= _BV(DDB5);

    // Initialize clock
    CLOCK_Init();

    // Enable global interrupts
    sei();

    while(1) {

        // Toggle led
        PORTB ^= _BV(PORTB5);

        // Sleep 250 millisecond (0.25 second)
        CLOCK_DelayMs(250);

    }


    return 0;
}