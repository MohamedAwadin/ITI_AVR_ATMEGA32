#ifndef MPORT_H
#define MPORT_H





typedef enum {
    MPORT_NOK=0,
    MPORT_OK,
    MPORT_ERROR_INVALID_PortPin,
    MPORT_ERROR_INVALID_DIRECTION,
    MPORT_ERROR_UNCHANGEABLE_MODE,
    MPORT_ERROR_INVALID_MODE
} MPORT_enuErrorStatus_t;


#define COMBINE_PORT_AND_PIN(PORT,PIN)          ((PORT<<4) | PIN)


typedef enum
{
    MPORT_PIN_A0 = 0x00,
    MPORT_PIN_A1 = 0x01,
    MPORT_PIN_A2 = 0x02,
    MPORT_PIN_A3 = 0x03,
    MPORT_PIN_A4 = 0x04,
    MPORT_PIN_A5 = 0x05,
    MPORT_PIN_A6 = 0x06,
    MPORT_PIN_A7 = 0x07,
    MPORT_PIN_B0 = 0x10,
    MPORT_PIN_B1 = 0x11,
    MPORT_PIN_B2 = 0x12,
    MPORT_PIN_B3 = 0x13,
    MPORT_PIN_B4 = 0x14,
    MPORT_PIN_B5 = 0x15,
    MPORT_PIN_B6 = 0x16,
    MPORT_PIN_B7 = 0x17,
    MPORT_PIN_C0 = 0x20,
    MPORT_PIN_C1 = 0x21,
    MPORT_PIN_C2 = 0x22,
    MPORT_PIN_C3 = 0x23,
    MPORT_PIN_C4 = 0x24,
    MPORT_PIN_C5 = 0x25,
    MPORT_PIN_C6 = 0x26,
    MPORT_PIN_C7 = 0x27,
    MPORT_PIN_D0 = 0x30,
    MPORT_PIN_D1 = 0x31,
    MPORT_PIN_D2 = 0x32,
    MPORT_PIN_D3 = 0x33,
    MPORT_PIN_D4 = 0x34,
    MPORT_PIN_D5 = 0x35,
    MPORT_PIN_D6 = 0x36,
    MPORT_PIN_D7 = 0x37,
} MPORT_enuPortPin_t;

typedef enum
{
    MPORT_PORT_PIN_INPUT  = 0,
    MPORT_PORT_PIN_OUTPUT =1,
} MPORT_enuPortPinDir_t;

typedef enum
{
    MPORT_PIN_MODE_INPUT_PULLUP,
    MPORT_PIN_MODE_INPUT_PULLDOWN,
    MPORT_PIN_MODE_UART,
    MPORT_PIN_MODE_NONE,
} MPORT_enuPortPinMode_t;


// Function prototypes


/**
 * @brief Set the direction of a specific pin.
 * 
 * @param Copy_enuPortPin The combined port and pin number.
 *                        Use `MPORT_PIN_<PORT><PIN>` macros for readability.
 *                        Example: `MPORT_PIN_A0` for Port A, Pin 0.
 * @param Copy_enuPortPinDir The desired pin direction. Possible values include:
 *                            - `MPORT_PORT_PIN_INPUT`
 *                            - `MPORT_PORT_PIN_OUTPUT`
 * @return MPORT_enuErrorStatus_t Error status of the operation.
 */
MPORT_enuErrorStatus_t MPORT_enuSetPinDirection(MPORT_enuPortPin_t Copy_enuPortPin, MPORT_enuPortPinDir_t Copy_enuPortPinDir);



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
 *         - `MPORT_ERROR_INVALID_PortPin`: Invalid pin_port number.
 *         - `MPORT_ERROR_INVALID_MODE`: The mode is invalid or unsupported.
 *         - `MPORT_ERROR_UNCHANGEABLE_MODE`: Mode cannot be changed for the pin.
 *
 * @note Ensure that the mode is supported by the hardware for the given pin.
 */
MPORT_enuErrorStatus_t MPORT_enuSetPinMode(MPORT_enuPortPin_t Copy_enuPortPin, MPORT_enuPortPinMode_t Copy_enuPortPinMode);



/**
 * @brief Initialize all port pins based on configuration.
 *
 * This function initializes all pins of the microcontroller according to the
 * configuration provided in `MPORT_enuArrPinConfig`. Each pin's direction and mode
 * are set during this initialization.
 *
 * @note The configuration array `MPORT_enuArrPinConfig` must be defined and initialized
 *       in `MPORT_LCFG.c`. The number of pins (`MPORT_NUM_OF_ALL_PINS`) must align with
 *       the configuration.
 *
 * @return void
 *
 */
void MPort_vInit(void);

#endif // MPORT_H
