#ifndef HKEYPAD_CONFIG_H_
#define HKEYPAD_CONFIG_H_

#include "HKEYPAD.h"

/* Number of HKEYPAD in the System */
#define NUM_OF_HKEYPAD 2

/* HKEYPAD Names (Indices for the configuration array) */
#define HKEYPAD_ID0   0  // HKEYPAD 0
#define HKEYPAD_ID1   1  // HKEYPAD 1

/* Default key value when no key is pressed */
#define HKEYPAD_DEFAULT_KEY ';'

/**
 * @brief Enumeration for HKEYPAD row pins.
 */
typedef enum {
    HKEYPAD_enumROW_Pin0 = 0U,
    HKEYPAD_enumROW_Pin1,
    HKEYPAD_enumROW_Pin2,
    HKEYPAD_enumROW_Pin3,
    HKEYPAD_enumROW_TotalNum
} HKEYPAD_enumRows_t;

/**
 * @brief Enumeration for HKEYPAD column pins.
 */
typedef enum {
    HKEYPAD_enumColumn_Pin0 = 0U,
    HKEYPAD_enumColumn_Pin1,
    HKEYPAD_enumColumn_Pin2,
    HKEYPAD_enumColumn_Pin3,
    HKEYPAD_enumColumn_TotalNum
} HKEYPAD_enumColumn_t;

/**
 * @brief Structure for HKEYPAD configuration.
 */
typedef struct {
    HKEYPAD_enumPinPortNum_t HKEYPAD_RowsPins[HKEYPAD_enumROW_TotalNum];      // Row pins
    HKEYPAD_enumPinPortNum_t HKEYPAD_ColumnsPins[HKEYPAD_enumColumn_TotalNum]; // Column pins
    u8 HKEYPAD_KEYArray[HKEYPAD_enumROW_TotalNum][HKEYPAD_enumColumn_TotalNum]; // Key array
    HKEYPAD_enumPullupState_t HKEYPAD_PullState;                              // Pull-up/down state
} HKEYPAD_strConfig_t;

#endif /* HKEYPAD_CONFIG_H_ */


