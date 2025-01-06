
#include "HSEVENSEG.h"
#include "HSEVENSEG_Config.h"
#include "MDIO.h"
#include "MPORT.h"
/*Look-Up table for Seven Segment Display (Common-Cathod)*/
static const u8 HSEVENSEG_u8LookupTableArray[11] = {
    0x3F,  /*Num = 0*/
    0x06,  /*Num = 1*/
    0x5B,  /*Num = 2*/
    0x4F,  /*Num = 3*/
    0x66,  /*Num = 4*/
    0x6D,  /*Num = 5*/
    0x7D,  /*Num = 6*/
    0x07,  /*Num = 7*/
    0x7F,  /*Num = 8*/
    0x6F,  /*Num = 9*/
    0x00   /* 10: All segments are OFF (Clear Display) */
};

/* SEVENSEG Configuration Array (Defined in SEVENSEG_Config.c) */
extern const HSEVENSEG_strConfig_t HSEVENSEG_strConfigArray[NUM_OF_SEVENSEGS];

/**
 * @brief Initialize all seven-segment displays based on the configuration.
 *
 * This function initializes all the pins of the seven-segment displays as outputs
 * according to the configuration provided in `HSEVENSEG_strConfigArray`. It sets
 * the direction of each pin to output using the `MPORT_enuSetPinDirection` function.
 */
void HSEVENSEG_vInit(void)
{
    u8 Local_u8Iter_1, Local_u8Iter_2;
    /* Loop through all seven-segment displays */
    for (Local_u8Iter_1 = 0; Local_u8Iter_1 < NUM_OF_SEVENSEGS; Local_u8Iter_1++)
    {
        /* Loop through all pins of the current seven-segment display */
        for (Local_u8Iter_2 = 0; Local_u8Iter_2 < HSEVENSEG_Total_Num_Pins; Local_u8Iter_2++)
        {
             /* Set the pin direction to output */
            MPORT_enuSetPinDirection(HSEVENSEG_strConfigArray[Local_u8Iter_1].SEVENSEG_enumPinArray[Local_u8Iter_2], MPORT_PORT_PIN_OUTPUT);
        }
    }
}

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
 */
HSEVENSEG_enumErrorStatus_t HSEVENSEG_vSetValue(u8 Copy_enuSevenSegNum, u8 Copy_u8Value)
{
    HSEVENSEG_enumErrorStatus_t Ret_enuErrorStatus = HSEVENSEG_OK;
    u8 Local_u8DisplayValue;
    u8 Local_u8Iter;
    Copy_enuPortNum_t Local_enumPort;
    Copy_enuPinNum_t  Local_enumPin ;

     /* Check if the display index is valid */
    if (Copy_enuSevenSegNum >= NUM_OF_SEVENSEGS)
    {
        Ret_enuErrorStatus = HSEVENSEG_ErrorLimitSevenSegments;
    }
    /* Check if the digit value is valid */
    else if (Copy_u8Value > HSEVENSEG_MAX_NUM_SIGSEG)
    {
        Ret_enuErrorStatus = HSEVENSEG_ErrorLimitSevenSegmentsDisplayNum;
    }
    else
    {
        /* Get the display value from the lookup table */
        Local_u8DisplayValue = HSEVENSEG_u8LookupTableArray[Copy_u8Value];

        /* Invert the value for Common Anode displays */
        if (HSEVENSEG_strConfigArray[Copy_enuSevenSegNum].SEVENSEG_Connection == HSEVENSEG_COMMON_ANODE)
        {
            Local_u8DisplayValue = ~Local_u8DisplayValue;
        }

        /* Set each pin of the seven-segment display */
        for (Local_u8Iter = 0; Local_u8Iter < HSEVENSEG_Total_Num_Pins; Local_u8Iter++)
        {
            /* Extract port and pin from HSEVENSEG_enumPinPortNum_t */
            Local_enumPort = (Copy_enuPortNum_t)(GET_HIGH_NIB(HSEVENSEG_strConfigArray[Copy_enuSevenSegNum].SEVENSEG_enumPinArray[Local_u8Iter]));
            Local_enumPin  = (Copy_enuPinNum_t)(GET_LOW_NIB(HSEVENSEG_strConfigArray[Copy_enuSevenSegNum].SEVENSEG_enumPinArray[Local_u8Iter]));

            /* Set the pin value based on the lookup table */
            MDIO_enuSetPinValue(Local_enumPort, Local_enumPin, HSEVENSEG_GET_PINVALUE(Local_u8DisplayValue , Local_u8Iter));
        }
    }
    return Ret_enuErrorStatus;
}

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
 */
HSEVENSEG_enumErrorStatus_t HSEVENSEG_enuSetMultiDigitValue(u16 Copy_u16Value) {
    HSEVENSEG_enumErrorStatus_t Ret_enuErrorStatus = HSEVENSEG_OK;
    u8 Local_u8DisplayValue = 0, Local_u8Iter = 0, Local_u8Iter_2 = 0;

    /* Calculate the maximum number that can be displayed based on the number of seven-segment Numbers */
    u16 Local_u16MaxValue = 1;
    for (Local_u8Iter_2 = 0; Local_u8Iter_2 < NUM_OF_SEVENSEGS;Local_u8Iter_2 ++) {
        Local_u16MaxValue =  Local_u16MaxValue * 10;
    }
    Local_u16MaxValue = Local_u16MaxValue - 1;  

    /* Check if the input number exceeds the maximum value */
    if (Copy_u16Value > Local_u16MaxValue) {
        Ret_enuErrorStatus = HSEVENSEG_enuSevenSegLimitError;
    } 
    else {
        /* Display each digit on the seven-segment displays */
        while ((Copy_u16Value > 0) && (Local_u8Iter < NUM_OF_SEVENSEGS)) {
            Local_u8DisplayValue = Copy_u16Value % 10;  
            Ret_enuErrorStatus = HSEVENSEG_vSetValue(Local_u8Iter, Local_u8DisplayValue);
            if (Ret_enuErrorStatus != HSEVENSEG_OK) {
                break;
            }
            Copy_u16Value = Copy_u16Value / 10;  
            Local_u8Iter++;
        }

        /* If there are remaining displays, clear them*/
        while (Local_u8Iter < NUM_OF_SEVENSEGS) {
            Ret_enuErrorStatus = HSEVENSEG_vSetValue(Local_u8Iter, HSEVENSEG_NO_DISPLAY);
            if (Ret_enuErrorStatus != HSEVENSEG_OK) {
                break;
            }
            Local_u8Iter++;
        }
    }
    return Ret_enuErrorStatus;
}