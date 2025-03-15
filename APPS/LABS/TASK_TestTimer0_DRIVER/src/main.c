#include"MTIMER.h"


#include <util/delay.h>
#include "MPORT.h"


void onOverflow(void) {
    
}


TIMER_0_enumErrorType setLEDBrightness(u8 brightness) {
    return TIMER_0_enumSetCompare(brightness);
}

int main(void) {
    MPORT_enuSetPinDirection( MPORT_PIN_B3, MPORT_PORT_PIN_OUTPUT);

    // Timer0 configuration
    TIMER_0_strConfigType timerConfig = {
        .Mode = TIMER_0_MODE_FASTPWM,           
        .OC0Mode = TIMER_0_OC0_NON_INVERTING,   
        .Prescaler = TIMER_0_PRESCALER_STOP,    
        .InitialValue = 0,                      
        .CompareValue = 0                       
    };

    // Initialize Timer0
    if (TIMER_0_enumInit(&timerConfig) != TIMER_0_OK) {
        while (1);
    }
    TIMER_0_enumSetOverflowCallback(onOverflow);
    TIMER_0_enumOverflowInterruptEnable();

    // Start Timer0 with prescaler /64
    if (TIMER_0_enumStart(TIMER_0_PRESCALER_64) != TIMER_0_OK) {
        while (1); 
    }
    while (1) {
        
        for (u8 brightness = 0; brightness < 255; brightness++) {
            setLEDBrightness(brightness);
            _delay_ms(10); 
        }

        
        for (u8 brightness = 255; brightness > 0; brightness--) {
            setLEDBrightness(brightness);
            _delay_ms(10); 
        }
    }

    return 0; 
}