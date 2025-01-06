#ifndef HSWITCH_H_
#define HSWITCH_H_

#include "StdTypes.h"
#include "Bit_Math.h"
#include "MDIO.h"
#include "MPORT.h"
/* Switch States */
typedef enum {
    HSWITCH_PRESSED = 0,  // Switch is pressed
    HSWITCH_RELEASED      // Switch is released
} HSWITCH_enuStates_t;

/* Switch Connection Types */
typedef enum {
    HSWITCH_PULLUP   =MPORT_PIN_MODE_INPUT_PULLUP,         // Switch connected to VCC, internal pull-up resistor
    HSWITCH_PULLDOWN =MPORT_PIN_MODE_INPUT_PULLDOWN,  // Switch connected to GND, internal pull-down resistor
} HSWITCH_enuConnectionType_t;

/* Error Status */
typedef enum {
    HSWITCH_NOK,               // Operation failed
    HSWITCH_OK,                // Operation succeeded
    HSWITCH_INVALID_SWITCH_NAME,  // Invalid switch name
    HSWITCH_INVALID_STATE      // Invalid switch state
} HSWITCH_enuErrorStatus_t;

/* Switch Configuration Structure */
typedef struct {
    Copy_enuPortNum_t Switch_Port;       // Port (e.g., MDIO_PORTA, MDIO_PORTB, etc.)
    Copy_enuPinNum_t Switch_Pin;         // Pin (e.g., MDIO_PIN0, MDIO_PIN1, etc.)
    HSWITCH_enuConnectionType_t Switch_Connection;  // Connection type (PULLUP or PULLDOWN)
} HSWITCH_strConfig_t;

/* Function Prototypes */

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
void HSWITCH_init(void);  // Initialize the switch driver


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
HSWITCH_enuErrorStatus_t HSWITCH_enuGetSwitchState(u8 Copy_u8SwitchName, u8* Add_pu8State);  // Get switch state

#endif /* HSWITCH_H_ */