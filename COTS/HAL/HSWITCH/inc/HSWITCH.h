#ifndef HSWITCH_H_
#define HSWITCH_H_

#include "StdTypes.h"
#include "Bit_Math.h"
#include "MDIO.h"

/* Switch States */
typedef enum {
    HSWITCH_PRESSED = 0,  // Switch is pressed
    HSWITCH_RELEASED      // Switch is released
} HSWITCH_enuStates_t;

/* Switch Connection Types */
typedef enum {
    HSWITCH_PULLDOWN = 1,  // Switch connected to GND, internal pull-down resistor
    HSWITCH_PULLUP         // Switch connected to VCC, internal pull-up resistor
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
void HSWITCH_init(void);  // Initialize the switch driver
HSWITCH_enuErrorStatus_t HSWITCH_enuGetSwitchState(u8 Copy_u8SwitchName, u8* Add_pu8State);  // Get switch state

#endif /* HSWITCH_H_ */