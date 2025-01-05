#include "HLED_Config.h"
#include "HLED.h"

/* LED Configuration Array */
const HLED_strPinConfig_t HLED_strPinConfigArray[NUM_OF_LEDS] = {
    /* LED 0: Start LED (Port A, Pin 1, Forward Connection) */
    {
        MDIO_PORTA,
        MDIO_PIN1,
        HLED_Forward
    },
    /* LED 1: Stop LED (Port A, Pin 2, Forward Connection) */
    {
        MDIO_PORTA,
        MDIO_PIN2,
        HLED_Forward
    },
    /* LED 2: Alert LED (Port A, Pin 3, Reverse Connection) */
    {
        MDIO_PORTA,
        MDIO_PIN3,
        HLED_Reverse
    }
};