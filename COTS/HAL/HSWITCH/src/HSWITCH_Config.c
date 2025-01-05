#include "HSWITCH_Config.h"
#include "HSWITCH.h"

/* Switch Configuration Array */
const HSWITCH_strConfig_t HSWITCH_strConfigArray[NUM_OF_SWITCHES] = {
    /* Switch 0: Port B, Pin 0, Pull-Up Connection */
    {
        MDIO_PORTB,
        MDIO_PIN0,
        HSWITCH_PULLUP
    },
    /* Switch 1: Port B, Pin 1, Pull-Up Connection */
    {
        MDIO_PORTB,
        MDIO_PIN1,
        HSWITCH_PULLUP
    },
    /* Switch 2: Port B, Pin 2, Pull-Up Connection */
    {
        MDIO_PORTB,
        MDIO_PIN2,
        HSWITCH_PULLUP
    }
};