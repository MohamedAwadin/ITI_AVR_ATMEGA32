#include "MPORT.h"
#include "MDIO.h"
#include "Bit_Math.h"
#include "MEXTINT.h"


void EXTI0_Callback(void) {
    // Toggle an LED or perform any action when INT0 is triggered
    static u8 Local_u8PinState = 0;
    u8 Local_u8Port = (GET_HIGH_NIB(MPORT_PIN_A0));
    u8 Local_u8Pin  = (GET_LOW_NIB(MPORT_PIN_A0));
    MDIO_enuSetPinValue(Local_u8Port,
        Local_u8Port,
        ! Local_u8PinState);
}

void EXTI1_Callback(void) {
    
    static u8 Local_u8PinState = 0;
    u8 Local_u8Port = (GET_HIGH_NIB(MPORT_PIN_A1));
    u8 Local_u8Pin  = (GET_LOW_NIB(MPORT_PIN_A1));
    MDIO_enuSetPinValue(Local_u8Port,
        Local_u8Port,
        ! Local_u8PinState);
}


void EXTI2_Callback(void) {
    
    static u8 Local_u8PinState = 0;
    u8 Local_u8Port = (GET_HIGH_NIB(MPORT_PIN_A2));
    u8 Local_u8Pin  = (GET_LOW_NIB(MPORT_PIN_A2));
    MDIO_enuSetPinValue(Local_u8Port,
        Local_u8Port,
        ! Local_u8PinState);
}

int main(void) {
    MPort_vInit();
    

    
    MEXTINT_vInit();

    
    MEXTINT_enumSetCallBack(MEXTINT_EXTI0_SOURCE, EXTI0_Callback);
    MEXTINT_enumSetCallBack(MEXTINT_EXTI1_SOURCE, EXTI1_Callback);
    MEXTINT_enumSetCallBack(MEXTINT_EXTI2_SOURCE, EXTI2_Callback);

    
    

    while (1) {
        
    }

    return 0;
}