
#include "StdTypes.h"
#include "Bit_Math.h"
#include "MemMap.h"
#include "MPORT_LCFG.h"

#include "MPORT.h"


extern MPORT_structPortPinDirAndMode_t MDIO_enuArrPinConfig[MPORT_NUM_OF_ALL_PINS];
#define PTA_BASE 0x39
#define PTB_BASE 0x36
#define PTC_BASE 0x33
#define PTD_BASE 0x30

typedef struct {
    volatile u8 PIN;
    volatile u8 DDR;
    volatile u8 DOR;
} MDIO_gst_PORT_t;


static MDIO_gst_PORT_t* const MDIO_gst_PORTS[] = {
    (MDIO_gst_PORT_t*)PTA_BASE,
    (MDIO_gst_PORT_t*)PTB_BASE,
    (MDIO_gst_PORT_t*)PTC_BASE,
    (MDIO_gst_PORT_t*)PTD_BASE
};


/**
 * @brief Initialize all port pins based on configuration.
 *
 * This function initializes all pins of the microcontroller according to the
 * configuration provided in `MDIO_enuArrPinConfig`. Each pin's direction and mode
 * are set during this initialization.
 *
 * @note The configuration array `MDIO_enuArrPinConfig` must be defined and initialized
 *       in `MPORT_LCFG.c`. The number of pins (`MPORT_NUM_OF_ALL_PINS`) must align with
 *       the configuration.
 *
 * @return void
 *
 */

void MPort_vInit(void) {
    u8 Local_u8Iter;
    u8 Local_u8PortNum;
    u8 Local_u8PinNum;
    u8 Local_u8CombinedPortAndPinNum;

    for (Local_u8Iter = 0; Local_u8Iter < (MPORT_NUM_OF_ALL_PINS); Local_u8Iter++) {
        Local_u8PortNum = Local_u8Iter / 8;
	    Local_u8PinNum  = Local_u8Iter % 8;
        Local_u8CombinedPortAndPinNum  = COMBINE_PORT_AND_PIN(Local_u8PortNum , Local_u8PinNum) ;
        MPORT_enuSetPinDirection(Local_u8CombinedPortAndPinNum, MDIO_enuArrPinConfig[Local_u8Iter].Direction);
        MPORT_enuSetPinMode(Local_u8CombinedPortAndPinNum, MDIO_enuArrPinConfig[Local_u8Iter].Mode);
    }
}

/**
 * @brief Set the direction of a specific pin.
 * 
 * @param Copy_enuPortPin The combined port and pin number.
 * @param Copy_enuPortPinDir The desired direction (INPUT or OUTPUT).
 * @return MPORT_enuErrorStatus_t Error status of the operation.
 */


MPORT_enuErrorStatus_t MPORT_enuSetPinDirection(MPORT_enuPortPin_t Copy_enuPortPin, MPORT_enuPortPinDir_t Copy_enuPortPinDir) {
    
    
    u8 Local_u8PortNum = GET_HIGH_NIB(Copy_enuPortPin);
    u8 Local_u8PinNum  = CLR_LOW_NIB(Copy_enuPortPin);
    

    if (Local_u8PortNum > 3 || Local_u8PinNum > 7) {
        return MPORT_ERROR_INVALID_PIN;
    }

    if (Copy_enuPortPinDir != MPORT_PORT_PIN_INPUT && Copy_enuPortPinDir != MPORT_PORT_PIN_OUTPUT) {
        return MPORT_ERROR_INVALID_DIRECTION;
    }

    switch (Copy_enuPortPinDir)
    {
        case MPORT_PORT_PIN_OUTPUT:
            SET_BIT(MDIO_gst_PORTS[Local_u8PortNum]->DDR , Local_u8PinNum);
            break;
        case MPORT_PORT_PIN_INPUT:
            CLEAR_BIT(MDIO_gst_PORTS[Local_u8PortNum]->DDR , Local_u8PinNum);
            break;
    }

    return MPORT_OK;
}



/**
 * @brief Configure the mode of a specific pin.
 *
 * This function sets the mode of a specific pin on the microcontroller. The mode
 * determines the pin's behavior, such as acting as an input with pull-up/down resistors
 * or being used for specialized functions like UART.
 *
 * @param Copy_enuPortPin The combined port and pin number.
 *                        Use `MPORT_PIN_<PORT><PIN>` macros for readability.
 *                        Example: `MPORT_PIN_A0` for Port A, Pin 0.
 *
 * @param Copy_enuPortPinMode The desired pin mode. Possible values include:
 *                            - `MPORT_PIN_MODE_INPUT_PULLUP`
 *                            - `MPORT_PIN_MODE_INPUT_PULLDOWN`
 *                            - `MPORT_PIN_MODE_UART`
 *                            - `MPORT_PIN_MODE_NONE`
 *
 * @return MPORT_enuErrorStatus_t Error status of the operation:
 *         - `MPORT_OK`: Successfully configured the pin mode.
 *         - `MPORT_ERROR_INVALID_PIN`: Invalid pin number.
 *         - `MPORT_ERROR_INVALID_MODE`: The mode is invalid or unsupported.
 *         - `MPORT_ERROR_UNCHANGEABLE_MODE`: Mode cannot be changed for the pin.
 *
 * @note Ensure that the mode is supported by the hardware for the given pin.
 */
MPORT_enuErrorStatus_t MPORT_enuSetPinMode(MPORT_enuPortPin_t Copy_enuPortPin, MPORT_enuPortPinMode_t Copy_enuPortPinMode){
    
    u8 Local_u8PortNum = GET_HIGH_NIB(Copy_enuPortPin);
    u8 Local_u8PinNum  = CLR_LOW_NIB(Copy_enuPortPin);

    if (Local_u8PortNum > 3 || Local_u8PinNum > 7) {
        return MPORT_ERROR_INVALID_PIN;
    }

    switch (Copy_enuPortPinMode) {
        
        case MPORT_PIN_MODE_INPUT_PULLUP:
            CLEAR_BIT(MDIO_gst_PORTS[Local_u8PortNum]->DOR, Local_u8PinNum);
            break;

        case MPORT_PIN_MODE_INPUT_PULLDOWN:
            SET_BIT(MDIO_gst_PORTS[Local_u8PortNum]->DOR, Local_u8PinNum);
            break;

        case MPORT_PIN_MODE_UART:
            
            return MPORT_ERROR_UNCHANGEABLE_MODE;
            break;

        default:
            return MPORT_ERROR_INVALID_MODE;
    }

    return MPORT_OK;
}


