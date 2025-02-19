#ifndef HKEYPAD_H_
#define HKEYPAD_H_

#include "MDIO.h"
#include "MPORT.h"
#include "StdTypes.h"
#include "Bit_Math.h"



/**
 * @brief Enumeration for HKEYPAD pin_port numbers.
 */
typedef enum {
    HKEYPAD_PIN_A0 = MPORT_PIN_A0,
    HKEYPAD_PIN_A1 = MPORT_PIN_A1,
    HKEYPAD_PIN_A2 = MPORT_PIN_A2,
    HKEYPAD_PIN_A3 = MPORT_PIN_A3,
    HKEYPAD_PIN_A4 = MPORT_PIN_A4,
    HKEYPAD_PIN_A5 = MPORT_PIN_A5,
    HKEYPAD_PIN_A6 = MPORT_PIN_A6,
    HKEYPAD_PIN_A7 = MPORT_PIN_A7,
    HKEYPAD_PIN_B0 = MPORT_PIN_B0,
    HKEYPAD_PIN_B1 = MPORT_PIN_B1,
    HKEYPAD_PIN_B2 = MPORT_PIN_B2,
    HKEYPAD_PIN_B3 = MPORT_PIN_B3,
    HKEYPAD_PIN_B4 = MPORT_PIN_B4,
    HKEYPAD_PIN_B5 = MPORT_PIN_B5,
    HKEYPAD_PIN_B6 = MPORT_PIN_B6,
    HKEYPAD_PIN_B7 = MPORT_PIN_B7,
    HKEYPAD_PIN_C0 = MPORT_PIN_C0,
    HKEYPAD_PIN_C1 = MPORT_PIN_C1,
    HKEYPAD_PIN_C2 = MPORT_PIN_C2,
    HKEYPAD_PIN_C3 = MPORT_PIN_C3,
    HKEYPAD_PIN_C4 = MPORT_PIN_C4,
    HKEYPAD_PIN_C5 = MPORT_PIN_C5,
    HKEYPAD_PIN_C6 = MPORT_PIN_C6,
    HKEYPAD_PIN_C7 = MPORT_PIN_C7,
    HKEYPAD_PIN_D0 = MPORT_PIN_D0,
    HKEYPAD_PIN_D1 = MPORT_PIN_D1,
    HKEYPAD_PIN_D2 = MPORT_PIN_D2,
    HKEYPAD_PIN_D3 = MPORT_PIN_D3,
    HKEYPAD_PIN_D4 = MPORT_PIN_D4,
    HKEYPAD_PIN_D5 = MPORT_PIN_D5,
    HKEYPAD_PIN_D6 = MPORT_PIN_D6,
    HKEYPAD_PIN_D7 = MPORT_PIN_D7
} HKEYPAD_enumPinPortNum_t;

/**
 * @brief Enumeration for HKEYPAD error status.
 */
typedef enum {
    HKEYPAD_enumNOK = 0,      // Operation failed
    HKEYPAD_enumOK,           // Operation succeeded
    HKEYPAD_enumInvalidID,    // Invalid HKEYPAD ID
    HKEYPAD_enumNullPtr,      // Null pointer passed
} HKEYPAD_enumErrorStatus_t;

/**
 * @brief Enumeration for HKEYPAD Pins pull-up/down states.
 */
typedef enum {
    HKEYPAD_enumPullState_PullDown = MPORT_PIN_MODE_INPUT_PULLDOWN,
    HKEYPAD_enumPullState_PullUp   = MPORT_PIN_MODE_INPUT_PULLUP
} HKEYPAD_enumPullupState_t;


/**
 * @brief Initializes all HKEYPADs.
 */
void HKEYPAD_vInit(void);


/**
 * @brief Reads the pressed key value from the HKEYPAD.
 * @param Copy_u8KEYPadNum: HKEYPAD ID to read from.
 * @param Add_pu8KeyValue: Pointer to store the pressed key value.
 * @return HKEYPAD_enumErrorStatus_t: Error status.
 */
HKEYPAD_enumErrorStatus_t HKEYPAD_enumGetPressedValue(u8 Copy_u8KEYPadNum, u8 *Add_pu8KeyValue);

#endif /* HKEYPAD_H_ */