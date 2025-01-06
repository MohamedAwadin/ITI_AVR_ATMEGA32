#ifndef HSEVENSEG_H_
#define HSEVENSEG_H_

#include "MDIO.h"
#include "MPORT.h"
#include "StdTypes.h"
#include "Bit_Math.h"

#define HSEVENSEG_Total_Num_Pins 7
#define HSEVENSEG_MAX_NUM_SIGSEG 9
#define HSEVENSEG_NO_DISPLAY     10 

#define HSEVENSEG_GET_PINVALUE(DS_VAL , PIN_NUM)   ((DS_VAL >> PIN_NUM) & 0x01)

typedef enum
{
    HSEVENSEG_PIN_A0 = 0x00,
    HSEVENSEG_PIN_A1 = 0x01,
    HSEVENSEG_PIN_A2 = 0x02,
    HSEVENSEG_PIN_A3 = 0x03,
    HSEVENSEG_PIN_A4 = 0x04,
    HSEVENSEG_PIN_A5 = 0x05,
    HSEVENSEG_PIN_A6 = 0x06,
    HSEVENSEG_PIN_A7 = 0x07,
    HSEVENSEG_PIN_B0 = 0x10,
    HSEVENSEG_PIN_B1 = 0x11,
    HSEVENSEG_PIN_B2 = 0x12,
    HSEVENSEG_PIN_B3 = 0x13,
    HSEVENSEG_PIN_B4 = 0x14,
    HSEVENSEG_PIN_B5 = 0x15,
    HSEVENSEG_PIN_B6 = 0x16,
    HSEVENSEG_PIN_B7 = 0x17,
    HSEVENSEG_PIN_C0 = 0x20,
    HSEVENSEG_PIN_C1 = 0x21,
    HSEVENSEG_PIN_C2 = 0x22,
    HSEVENSEG_PIN_C3 = 0x23,
    HSEVENSEG_PIN_C4 = 0x24,
    HSEVENSEG_PIN_C5 = 0x25,
    HSEVENSEG_PIN_C6 = 0x26,
    HSEVENSEG_PIN_C7 = 0x27,
    HSEVENSEG_PIN_D0 = 0x30,
    HSEVENSEG_PIN_D1 = 0x31,
    HSEVENSEG_PIN_D2 = 0x32,
    HSEVENSEG_PIN_D3 = 0x33,
    HSEVENSEG_PIN_D4 = 0x34,
    HSEVENSEG_PIN_D5 = 0x35,
    HSEVENSEG_PIN_D6 = 0x36,
    HSEVENSEG_PIN_D7 = 0x37
} HSEVENSEG_enumPinPortNum_t;


/* Error Status */
typedef enum{
    HSEVENSEG_NOK=0,                                /*Operation Failed*/
    HSEVENSEG_OK,                                   /*Operation Succeeded*/  
    HSEVENSEG_ErrorLimitSevenSegments,              /*Invalid Seven-Segment Display Number*/
    HSEVENSEG_InvalidPort,                          /*Invalid Seven-Segment Display Port  */ 
    HSEVENSEG_ErrorLimitSevenSegmentsDisplayNum,    /*Invalid Seven-Segment Display Number*/
    HSEVENSEG_enuSevenSegLimitError                 /*Input Number Exceeds The range Supported by the number of configured Displays*/
}HSEVENSEG_enumErrorStatus_t;


/* SEVENSEG Connection Types */
typedef enum {
    HSEVENSEG_COMMON_CATHODE = 0,  // Common Cathode Seven-Segment Display 
    HSEVENSEG_COMMON_ANODE         // Common Anode   Seven-Segment Display 
} HSEVENSEG_enuConnectionType_t;


typedef struct {
    HSEVENSEG_enumPinPortNum_t                  SEVENSEG_enumPinArray[7];
    HSEVENSEG_enuConnectionType_t               SEVENSEG_Connection     ;
} HSEVENSEG_strConfig_t;


/*Function Prototypes*/

/**
 * @brief Initialize all seven-segment displays based on the configuration.
 *
 * This function initializes all the pins of the seven-segment displays as outputs
 * according to the configuration provided in `HSEVENSEG_strConfigArray`. It sets
 * the direction of each pin to output using the `MPORT_enuSetPinDirection` function.
 *
 * @param void
 * @return void
 *
 * @note This function must be called before using any other functions in the driver.
 */
void HSEVENSEG_vInit(void);  


/**
 * @brief Set a single digit on a specific seven-segment display.
 *
 * This function displays a single digit (0-9) on a specific seven-segment display.
 * It uses the lookup table `HSEVENSEG_u8LookupTableArray` to determine the pin states
 * for the given digit. If the display is configured as a common anode, the value is
 * inverted before being applied to the pins.
 *
 * @param Copy_enuSevenSegNum The index of the seven-segment display to set (0 to NUM_OF_SEVENSEGS - 1).
 * @param Copy_u8Value The digit to display (0-9). If the value is `HSEVENSEG_NO_DISPLAY`, the display is cleared.
 *
 * @return HSEVENSEG_enumErrorStatus_t
 *   - HSEVENSEG_OK: The operation was successful.
 *   - HSEVENSEG_ErrorLimitSevenSegments: The display index is invalid.
 *   - HSEVENSEG_ErrorLimitSevenSegmentsDisplayNum: The digit value is invalid.
 *
 * @note The display index must be within the range defined by `NUM_OF_SEVENSEGS`.
 */
HSEVENSEG_enumErrorStatus_t HSEVENSEG_vSetValue(u8 Copy_enuSevenSegNum , u8 Copy_u8Value);

/**
 * @brief Set a multi-digit number across multiple seven-segment displays.
 *
 * This function displays a multi-digit number across multiple seven-segment displays.
 * It calculates the maximum number that can be displayed based on the number of
 * seven-segment displays (`NUM_OF_SEVENSEGS`). If the input number exceeds this
 * maximum value, the function returns an error. Otherwise, it displays the number
 * digit by digit on the displays. If there are fewer digits than displays, the
 * remaining displays are cleared.
 *
 * @param Copy_u16Value The number to display (0 to 9999 for 4 displays).
 *
 * @return HSEVENSEG_enumErrorStatus_t
 *   - HSEVENSEG_OK: The operation was successful.
 *   - HSEVENSEG_enuSevenSegLimitError: The input number exceeds the maximum value supported by the displays.
 *
 * @note The maximum value is calculated as (10^NUM_OF_SEVENSEGS) - 1. For example:
 *   - 1 display: max value = 9
 *   - 2 displays: max value = 99
 *   - 3 displays: max value = 999
 *   - 4 displays: max value = 9999
 */
HSEVENSEG_enumErrorStatus_t HSEVENSEG_enuSetMultiDigitValue(u16 Copy_u16Value);

#endif /*HSEVENSEG_H_*/