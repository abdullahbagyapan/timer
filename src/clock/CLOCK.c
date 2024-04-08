/*
 @module: CLOCK
 @author: Abdullah Bagyapan
 @date:   08/04/2024
*/


/*================================== Libraries ==================================*/


// Module's own header
#include "CLOCK.h"

// AVR libraries
#include <avr/io.h>
#include <avr/interrupt.h>


/*================================== Defined Variables ==================================*/


volatile uint16_t CLOCK_Timer_milliseconds;
volatile uint16_t CLOCK_TimerFuture_milliseconds;


/*================================== Functions ==================================*/



/******************** Inline Functions ********************/


/*
 @brief:  Return timer

 @author  Abdullah Bagyapan

 @date    08/04/2024

 @param   None

 @return  uint16_t, CLOCK_Timer_milliseconds, the timer
*/
extern inline uint16_t CLOCK_GetTimer() {

    return CLOCK_Timer_milliseconds;
}


/*
 @brief:  Set timer

 @author  Abdullah Bagyapan

 @date    08/04/2024

 @param   uint16_t ui16Timeout, the time to set

 @return  None
*/
extern inline void CLOCK_SetTimer(uint16_t ui16Timeout) {

    CLOCK_TimerFuture_milliseconds = ui16Timeout;

}




/******************** Public Functions ********************/



void CLOCK_Init() {

    // Enable Timer/Counter0 module
    PRR &= ~_BV(PRTIM0);

    // Set Timer/Counter as clocked directly by the system clock
    TCCR0B |= _BV(CS01);

    // Set Timer/Counter operation to CTC
    TCCR0A |= _BV(WGM01);

    // Set prescaler to 64
    TCCR0B |= _BV(CS01) | _BV(CS00);

    // Set timer frequency to 1 kHz (1 millisecond)
    OCR0A = F_CPU / 1000 / T_PRESCALER;

    // Enable Timer/Counter Output Compare Match Interrupt
    TIMSK0 |= _BV(OCIE0A);

}



/******************** Interrupt Handlers ********************/


// Timer/Counter Output Compare Match Interrupt Handler
// Increase timer on every 1 ms 
ISR(TIMER0_COMPA_vect) {

    CLOCK_Timer_milliseconds++;

}