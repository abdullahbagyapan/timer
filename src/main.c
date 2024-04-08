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

    // Set Data Direction Register to 1 (output)
    DDRB |= _BV(DDB5);

    CLOCK_Init();

    // Enable global interrupts
    sei();

    // Set timer after 1000 Ms (1 second)
    CLOCK_SetTimer(1000);


    while(1) {

        if (CLOCK_Timeout()) {

            // Toggle led
            PORTB ^= _BV(PORTB5);

            // Set another timer
            CLOCK_SetTimer(1000);
        }

    }


    return 0;
}