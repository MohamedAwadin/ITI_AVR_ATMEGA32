#include "HLED.h"
#include "HLED_Config.h"

/**
 * @brief Initializes all LEDs based on the configuration provided in `HLED_strPinConfigArray`.
 * 
 * This function iterates through all LEDs defined by `NUM_OF_LEDS`, combines the port number and pin number 
 * for each LED using `COMBINE_HIGH_AND_LOW_NIB`, and sets the direction of each pin to OUTPUT using 
 * `MPORT_enuSetPinDirection`.
 * 
 * @param  None
 * @return None
 */
void HLED_vInit(void)
{
    u8 Local_u8currPinPort = 0;
    u8 Local_u8Iter= 0;

    for(Local_u8Iter = 0 ; Local_u8Iter<NUM_OF_LEDS ; Local_u8Iter++)
    {
        Local_u8currPinPort = COMBINE_HIGH_AND_LOW_NIB((HLED_strPinConfigArray[Local_u8Iter].port_Number) , (HLED_strPinConfigArray[Local_u8Iter].pin_Number));
        MPORT_enuSetPinDirection(Local_u8currPinPort , MPORT_PORT_PIN_OUTPUT);
    }
}

/**
 * @brief Sets the state (ON or OFF) of a specific LED.
 * 
 * This function validates the LED name (`Copy_u8LedName`) to ensure it is within the valid range (`NUM_OF_LEDS`). 
 * It also validates the LED state (`CopyHLED_enumLogicValue`) to ensure it is either `HLED_ON` or `HLED_OFF`. 
 * Based on the LED's connection type (forward or reverse), it determines the actual pin state and sets the pin 
 * value using `MDIO_enuSetPinValue`.
 * 
 * @param Copy_u8LedName The identifier of the LED to control (must be less than `NUM_OF_LEDS`).
 * @param CopyHLED_enumLogicValue The desired state of the LED (`HLED_ON` or `HLED_OFF`).
 * 
 * @return HLED_enumErrorState_t 
 * - `HLED_enumErrSt_NOK`: If the operation fails.
 * - `HLED_enumErrSt_WrongLED`: If the LED name is invalid.
 * - `HLED_enumErrSt_InvalidConfig`: If the LED state is invalid.
 * - Result of `MDIO_enuSetPinValue`: If the operation is successful.
 */
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