#include "MTIMER.h"
#include "MPORT.h"

int main(void) {
    
    MPORT_enuSetPinDirection( MPORT_PIN_B7, MPORT_PORT_PIN_OUTPUT);
    // Configure Timer2 for PWM
    TIMER_strConfigType timer2Config = {
        .Mode = TIMER_MODE_FASTPWM,
        .OCMode = TIMER_OC_NON_INVERTING,
        .Prescaler.Timer2Prescaler = TIMER_2_PRESCALER_STOP,
        .InitialValue = 0,
        .CompareValue = 127 
    };

    if (TIMER_2_enumInit(&timer2Config) != TIMER_OK) {
        
    }

    TIMER_2_enumStart(TIMER_2_PRESCALER_64); 

    while (1) {
        
    }

    return 0;
}