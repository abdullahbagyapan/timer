/*
 @module: CLOCK
 @author: Abdullah Bagyapan
 @date:   08/04/2024
*/


/*================================== Libraries ==================================*/


// Standart libraries
#include <stdint.h>


/*================================== Defined Variables ==================================*/


#define F_CPU           16000000
#define T_PRESCALER     64

/*================================== Functions ==================================*/


/*
 @brief:  Initialize CLOCK system

 @author  Abdullah Bagyapan

 @date    08/04/2024

 @param   None

 @return  None
*/
void CLOCK_Init();