#include "HLED.h"
#include "HLED_Config.h"

/* Initialize all LEDs based on configuration */

#if (HLED_DRIVER == PIN_DRIVER)

void HLED_vInit(void) {
    u8 Local_u8Iter;
    for (Local_u8Iter = 0; Local_u8Iter < NUM_OF_LEDS; Local_u8Iter++) {
        MDIO_enuSetPinConfigration(HLED_strPinConfigArray[Local_u8Iter].port_Number,
                                   HLED_strPinConfigArray[Local_u8Iter].pin_Number,
                                   MDIO_OUTPUT);
    }
}

#elif (HLED_DRIVER == PORT_DRIVER)
void HLED_vInit(void)
{
    u8 Local_u8currPinPort = 0;
    u8 Local_u8Iter= 0;

    for(Local_u8Iter = 0 ; Local_u8Iter<NUM_OF_LEDS ; Local_u8Iter++)
    {
        Local_u8currPinPort = ((strLed_Cfg_Array[Local_u8Iter].port_Number)<<4)+((strLed_Cfg_Array[Local_u8Iter].pin_Number));
        MPORT_enuSetPinDirection(Local_u8currPinPort , MPORT_PORT_PIN_OUTPUT);
    }

}

#endif

/* Set the state of a specific LED */
HLED_enumErrorState_t HLED_enuSetValue(u8 Copy_u8LedName, HLED_enumLogic_t CopyHLED_enumLogicValue) {
    HLED_enumErrorState_t Ret_enumErrorStatus = HLED_enumErrSt_NOK;
    u8 Local_u8PinState = 0;

    /* Validate LED name */
    if (Copy_u8LedName >= NUM_OF_LEDS) {
        Ret_enumErrorStatus = HLED_enumErrSt_WrongLED;
    }
    /* Validate LED state */
    else if ((CopyHLED_enumLogicValue != HLED_OFF) && (CopyHLED_enumLogicValue != HLED_ON)) {
        Ret_enumErrorStatus = HLED_enumErrSt_InvalidConfig;
    }
    /* Set LED state */
    else {
        /* Determine pin state based on connection type */
        if (HLED_strPinConfigArray[Copy_u8LedName].connection == HLED_Forward) {
            Local_u8PinState = CopyHLED_enumLogicValue;
        } else {
            Local_u8PinState = (CopyHLED_enumLogicValue == HLED_ON) ? HLED_OFF : HLED_ON;
        }

        /* Set the pin value */
        Ret_enumErrorStatus = MDIO_enuSetPinValue(HLED_strPinConfigArray[Copy_u8LedName].port_Number,
                                                  HLED_strPinConfigArray[Copy_u8LedName].pin_Number,
                                                  Local_u8PinState);
    }

    return Ret_enumErrorStatus;
}