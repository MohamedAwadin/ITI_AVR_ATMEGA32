#include "HSWITCH.h"
#include "HSWITCH_Config.h"

/**
 * @brief Initializes all switches based on the configuration provided in `HSWITCH_strConfigArray`.
 * 
 * This function iterates through all switches defined by `NUM_OF_SWITCHES`, combines the port number and pin number 
 * for each switch using `COMBINE_HIGH_AND_LOW_NIB`, sets the direction of each pin to INPUT using `MPORT_enuSetPinDirection`, 
 * and configures the pin mode (pull-up or pull-down) using `MPORT_enuSetPinMode`.
 * 
 * @param None
 * @return None
 */
void HSWITCH_init(void) {
    u8 Local_u8Iter, Local_u8currPinPort;
    for (Local_u8Iter = 0; Local_u8Iter < NUM_OF_SWITCHES; Local_u8Iter++) {
        Local_u8currPinPort = COMBINE_HIGH_AND_LOW_NIB((HSWITCH_strConfigArray[Local_u8Iter].Switch_Port), 
                                                       (HSWITCH_strConfigArray[Local_u8Iter].Switch_Pin));
        MPORT_enuSetPinDirection(Local_u8currPinPort, MPORT_PORT_PIN_INPUT);
        MPORT_enuSetPinMode(Local_u8currPinPort, HSWITCH_strConfigArray[Local_u8Iter].Switch_Connection);
    }
}

/**
 * @brief Gets the state of a specific switch.
 * 
 * This function retrieves the state of a switch specified by `Copy_u8SwitchName`. It validates the switch name to ensure 
 * it is within the valid range (`NUM_OF_SWITCHES`). Based on the switch's connection type (pull-up or pull-down), it 
 * determines the actual state of the switch and stores it in the provided pointer `Add_pu8State`.
 * 
 * @param Copy_u8SwitchName The identifier of the switch to check (must be less than `NUM_OF_SWITCHES`).
 * @param Add_pu8State Pointer to a variable where the switch state will be stored. The state will be either:
 *                    - `HSWITCH_PRESSED`: If the switch is pressed.
 *                    - `HSWITCH_RELEASED`: If the switch is released.
 * 
 * @return HSWITCH_enuErrorStatus_t 
 * - `HSWITCH_OK`: If the operation is successful.
 * - `HSWITCH_INVALID_SWITCH_NAME`: If the switch name is invalid.
 */
HSWITCH_enuErrorStatus_t HSWITCH_enuGetSwitchState(u8 Copy_u8SwitchName, u8* Add_pu8State) {
    HSWITCH_enuErrorStatus_t Ret_enuErrorStatus = HSWITCH_NOK;
    u8 Local_u8PinState;

    /* Validate switch name */
    if (Copy_u8SwitchName >= NUM_OF_SWITCHES) {
        Ret_enuErrorStatus = HSWITCH_INVALID_SWITCH_NAME;
    } else {
        /* Get the current pin value */
        MDIO_enuGetPinValue(HSWITCH_strConfigArray[Copy_u8SwitchName].Switch_Port,
                            HSWITCH_strConfigArray[Copy_u8SwitchName].Switch_Pin,
                            &Local_u8PinState);

        /* Determine switch state based on connection type */
        if (HSWITCH_strConfigArray[Copy_u8SwitchName].Switch_Connection == HSWITCH_PULLUP) {
            *Add_pu8State = (Local_u8PinState == 0) ? HSWITCH_PRESSED : HSWITCH_RELEASED;
        } else {
            *Add_pu8State = (Local_u8PinState == 1) ? HSWITCH_PRESSED : HSWITCH_RELEASED;
        }

        Ret_enuErrorStatus = HSWITCH_OK;
    }

    return Ret_enuErrorStatus;
}