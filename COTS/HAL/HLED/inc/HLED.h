#ifndef HLED_H_
#define HLED_H_


#include "MDIO.h"
#include "MPORT.h"
#include "StdTypes.h"
#include "Bit_Math.h"

#define PORT_DRIVER  0
#define PIN_DRIVER   1

#define HLED_DRIVER PIN_DRIVER


/* LED Logic States */
typedef enum {
    HLED_OFF = 0,  // LED is off
    HLED_ON        // LED is on
} HLED_enumLogic_t;

/* LED Driver Error States */
typedef enum {
    HLED_enumErrSt_NOK = 0,         // Operation failed
    HLED_enumErrSt_OK,              // Operation succeeded
    HLED_enumErrSt_InvalidPin,      // Invalid pin number
    HLED_enumErrSt_InvalidPort,     // Invalid port number
    HLED_enumErrSt_InvalidConfig,   // Invalid configuration
    HLED_enumErrSt_InvalidState,    // Invalid LED state
    HLED_enumErrSt_WrongLED         // Invalid LED name
} HLED_enumErrorState_t;

/* LED Connection Options */
typedef enum {
    HLED_Forward = 0,  // LED anode connected to MCU pin, cathode to GND
    HLED_Reverse       // LED cathode connected to MCU pin, anode to VCC
} HLED_enumConnectOptions_t;

/* LED Configuration Structure */
typedef struct {
    Copy_enuPortNum_t port_Number;           // Port number (e.g., MDIO_PORTA)
    Copy_enuPinNum_t pin_Number;             // Pin number (e.g., MDIO_PIN0)
    HLED_enumConnectOptions_t connection;    // Connection type (Forward/Reverse)
} HLED_strPinConfig_t;

/* Function Prototypes */

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
void HLED_vInit(void);  

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
HLED_enumErrorState_t HLED_enuSetValue(u8 Copy_u8LedName, HLED_enumLogic_t CopyHLED_enumLogicValue);  // Set LED state

#endif /* HLED_H_ */