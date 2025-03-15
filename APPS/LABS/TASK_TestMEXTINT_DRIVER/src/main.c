#include "MEXTINT.h"
#include "MTIMER.h"
#include "MPORT.h"
#include <avr/io.h>
#include <util/delay.h>


static volatile u8 ledBrightness = 0;
static volatile u8 ledState = 1; 

// Callback for INT0: Increase brightness
void increaseBrightness(void) {
    if (ledState && ledBrightness < 255) {
        ledBrightness += 25; 
        if (ledBrightness > 255) ledBrightness = 255; 
        TIMER_0_enumSetCompare(ledBrightness);
    }
}

// Callback for INT1: Decrease brightness
void decreaseBrightness(void) {
    if (ledState && ledBrightness > 0) {
        ledBrightness -= 25;
        if (ledBrightness < 0) ledBrightness = 0;
        TIMER_0_enumSetCompare(ledBrightness);
    }
}

// Callback for INT2: Toggle LED
void toggleLED(void) {
    ledState = !ledState;
    if (ledState) {
        TIMER_0_enumSetCompare(ledBrightness); 
    } else {
        TIMER_0_enumSetCompare(0); 
    }
}

int main(void) {
    
    
    
    MPORT_enuSetPinDirection( MPORT_PIN_B3, MPORT_PORT_PIN_OUTPUT);
    MPORT_enuSetPinDirection( MPORT_PIN_D2, MPORT_PORT_PIN_INPUT);
    MPORT_enuSetPinDirection( MPORT_PIN_D3, MPORT_PORT_PIN_INPUT);
    MPORT_enuSetPinDirection( MPORT_PIN_B2, MPORT_PORT_PIN_INPUT);    

    MPORT_enuSetPinMode(MPORT_PIN_D2, MPORT_PIN_MODE_INPUT_PULLUP);
    MPORT_enuSetPinMode(MPORT_PIN_D3, MPORT_PIN_MODE_INPUT_PULLUP);
    MPORT_enuSetPinMode(MPORT_PIN_B2, MPORT_PIN_MODE_INPUT_PULLUP);
    

    
    TIMER_0_strConfigType timerConfig = {
        .Mode = TIMER_0_MODE_FASTPWM,
        .OC0Mode = TIMER_0_OC0_NON_INVERTING,
        .Prescaler = TIMER_0_PRESCALER_STOP,
        .InitialValue = 0,
        .CompareValue = 0
    };
    if (TIMER_0_enumInit(&timerConfig) != TIMER_0_OK) {
        while (1); 
    }
    TIMER_0_enumStart(TIMER_0_PRESCALER_64); 
    MEXTINT_vInit();
    MEXTINT_enumErrorStatus_t status;
    status = MEXTINT_enumSetCallBack(MEXTINT_EXTI0_SOURCE, increaseBrightness);
    if (status != MEXTINT_enumOK) {
        while (1); 
    }
    status = MEXTINT_enumSetCallBack(MEXTINT_EXTI1_SOURCE, decreaseBrightness);
    if (status != MEXTINT_enumOK) {
        while (1);
    }
    status = MEXTINT_enumSetCallBack(MEXTINT_EXTI2_SOURCE, toggleLED);
    if (status != MEXTINT_enumOK) {
        while (1);
    }
    while (1) {
        _delay_ms(100);
    }

    return 0; 
}