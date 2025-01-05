#include "HSWITCH.h"
#include "HSWITCH_Config.h"

/* Initialize all switches based on configuration */
void HSWITCH_init(void) {
    u8 Local_u8Iter;
    for (Local_u8Iter = 0; Local_u8Iter < NUM_OF_SWITCHES; Local_u8Iter++) {
        MDIO_enuSetPinConfigration(HSWITCH_strConfigArray[Local_u8Iter].Switch_Port,
                                   HSWITCH_strConfigArray[Local_u8Iter].Switch_Pin,
                                   MDIO_INPULLUP);  // Default to input with pull-up
    }
}

/* Get the state of a specific switch */
HSWITCH_enuErrorStatus_t HSWITCH_enuGetSwitchState(u8 Copy_u8SwitchName, u8* Add_pu8State) {
    HSWITCH_enuErrorStatus_t Ret_enuErrorStatus = HSWITCH_NOK;

    /* Validate switch name */
    if (Copy_u8SwitchName >= NUM_OF_SWITCHES) {
        Ret_enuErrorStatus = HSWITCH_INVALID_SWITCH_NAME;
    } else {
        u8 Local_u8PinState;
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