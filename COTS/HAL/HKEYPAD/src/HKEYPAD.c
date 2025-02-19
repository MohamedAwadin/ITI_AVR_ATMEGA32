#include "HKEYPAD.h"
#include "HKEYPAD_Config.h"


/**
 * @brief Macro to check if the HKEYPAD ID is valid.
 */
#define IS_HKEYPAD_ID_VALID(HKEYPAD_ID) (((HKEYPAD_ID) >= 0) && ((HKEYPAD_ID) < NUM_OF_HKEYPAD))

/**
 * @brief External declaration for the HKEYPAD configuration array.
 */
extern const HKEYPAD_strConfig_t HKEYPAD_gstrConfigArray[NUM_OF_HKEYPAD];



/**
 * @brief **Private Function** Configures the pins for a specific HKEYPAD.
 * @param Copy_u8KEYPadNum: HKEYPAD ID to configure.
 * @return HKEYPAD_enumErrorStatus_t: Error status.
 */
static void HKEYPAD_vConfig(u8 Copy_u8KEYPadNum)
{

    MPORT_enuErrorStatus_t Local_enuMPortErrorStatus = MPORT_OK;
    u8 Local_u8Iter = 0;
    MDIO_enuPortNum_t Local_enumPort;
    MDIO_enuPinNum_t Local_enumPin;

    HKEYPAD_enumPullupState_t Local_enumPullupState = HKEYPAD_gstrConfigArray[Copy_u8KEYPadNum].HKEYPAD_PullState;

    for (Local_u8Iter = 0; Local_u8Iter < HKEYPAD_enumROW_TotalNum; Local_u8Iter++)
    {

        Local_enuMPortErrorStatus = MPORT_enuSetPinDirection(HKEYPAD_gstrConfigArray[Copy_u8KEYPadNum].HKEYPAD_RowsPins[Local_u8Iter], MPORT_PORT_PIN_INPUT);
        if (Local_enuMPortErrorStatus == MPORT_OK)
        {
            Local_enuMPortErrorStatus = MPORT_enuSetPinMode(HKEYPAD_gstrConfigArray[Copy_u8KEYPadNum].HKEYPAD_RowsPins[Local_u8Iter], Local_enumPullupState);
        }
    }

    for (Local_u8Iter = 0; Local_u8Iter < HKEYPAD_enumColumn_TotalNum; Local_u8Iter++)
    {

        Local_enuMPortErrorStatus = MPORT_enuSetPinDirection(HKEYPAD_gstrConfigArray[Copy_u8KEYPadNum].HKEYPAD_ColumnsPins[Local_u8Iter], MPORT_PORT_PIN_OUTPUT);
        if (Local_enuMPortErrorStatus == MPORT_OK)
        {
            Local_enumPort = (MDIO_enuPortNum_t)(GET_HIGH_NIB(HKEYPAD_gstrConfigArray[Copy_u8KEYPadNum].HKEYPAD_ColumnsPins[Local_u8Iter]));
            Local_enumPin = (MDIO_enuPinNum_t)(GET_LOW_NIB(HKEYPAD_gstrConfigArray[Copy_u8KEYPadNum].HKEYPAD_ColumnsPins[Local_u8Iter]));

            MDIO_enuSetPinValue(Local_enumPort, Local_enumPin, MDIO_HIGH);
        }
    }
}


/**
 * @brief Initializes all HKEYPADs.
 */
void HKEYPAD_vInit(void)
{
    u8 Local_u8Iter = 0;
    for (Local_u8Iter = 0; Local_u8Iter < NUM_OF_HKEYPAD; Local_u8Iter++)
    {
        HKEYPAD_vConfig(Local_u8Iter);
    }
}


/**
 * @brief Reads the pressed key value from the HKEYPAD.
 * @param Copy_u8KEYPadNum: HKEYPAD ID to read from.
 * @param Add_pu8KeyValue: Pointer to store the pressed key value.
 * @return HKEYPAD_enumErrorStatus_t: Error status.
 */
HKEYPAD_enumErrorStatus_t HKEYPAD_enumGetPressedValue(u8 Copy_u8KEYPadNum, u8 *Add_pu8KeyValue)
{
    HKEYPAD_enumErrorStatus_t Local_enuErrorStatus = HKEYPAD_enumOK;
    
    u8 Local_u8Iter_Row = 0;
    u8 Local_u8Iter_Columns = 0;
    MDIO_enuPortNum_t Local_enumPort;
    MDIO_enuPinNum_t Local_enumPin;
    HKEYPAD_enumPullupState_t Local_enumPullupState = HKEYPAD_gstrConfigArray[Copy_u8KEYPadNum].HKEYPAD_PullState;
    u8 Local_u8KeyStatus = 0;

    if (!IS_HKEYPAD_ID_VALID(Copy_u8KEYPadNum))
    {
        Local_enuErrorStatus = HKEYPAD_enumInvalidID;
    }
    else if (Add_pu8KeyValue == NULL_PTR)
    {
        Local_enuErrorStatus = HKEYPAD_enumNullPtr;
    }
    else
    {
        *Add_pu8KeyValue = HKEYPAD_DEFAULT_KEY ;

        for (Local_u8Iter_Columns = 0; Local_u8Iter_Columns < HKEYPAD_enumColumn_TotalNum; Local_u8Iter_Columns++)
        {
            Local_enumPort = (MDIO_enuPortNum_t)(GET_HIGH_NIB(HKEYPAD_gstrConfigArray[Copy_u8KEYPadNum].HKEYPAD_ColumnsPins[Local_u8Iter_Columns]));
            Local_enumPin = (MDIO_enuPinNum_t)(GET_LOW_NIB(HKEYPAD_gstrConfigArray[Copy_u8KEYPadNum].HKEYPAD_ColumnsPins[Local_u8Iter_Columns]));

            MDIO_enuSetPinValue(Local_enumPort, Local_enumPin, MDIO_LOW);
            for (Local_u8Iter_Row = 0; Local_u8Iter_Row < HKEYPAD_enumROW_TotalNum; Local_u8Iter_Row++)
            {
                Local_enumPort = (MDIO_enuPortNum_t)(GET_HIGH_NIB(HKEYPAD_gstrConfigArray[Copy_u8KEYPadNum].HKEYPAD_RowsPins[Local_u8Iter_Row]));
                Local_enumPin = (MDIO_enuPinNum_t)(GET_LOW_NIB(HKEYPAD_gstrConfigArray[Copy_u8KEYPadNum].HKEYPAD_RowsPins[Local_u8Iter_Row]));

                MDIO_enuGetPinValue(Local_enumPort, Local_enumPin, &Local_u8KeyStatus);
                if (Local_enumPullupState == HKEYPAD_enumPullState_PullUp)
                {
                    Local_u8KeyStatus = !Local_u8KeyStatus;
                }

                if (Local_u8KeyStatus == 1)
                {
                    *Add_pu8KeyValue = HKEYPAD_gstrConfigArray[Copy_u8KEYPadNum].HKEYPAD_KEYArray[Local_u8Iter_Row][Local_u8Iter_Columns];

                    while (Local_u8KeyStatus)
                    {
                        MDIO_enuGetPinValue(Local_enumPort, Local_enumPin, &Local_u8KeyStatus);

                        if (Local_enumPullupState == HKEYPAD_enumPullState_PullUp)
                        {
                            Local_u8KeyStatus = !Local_u8KeyStatus;
                        }
                    }
                }
            }
            Local_enumPort = (MDIO_enuPortNum_t)(GET_HIGH_NIB(HKEYPAD_gstrConfigArray[Copy_u8KEYPadNum].HKEYPAD_ColumnsPins[Local_u8Iter_Columns]));
            Local_enumPin = (MDIO_enuPinNum_t)(GET_LOW_NIB(HKEYPAD_gstrConfigArray[Copy_u8KEYPadNum].HKEYPAD_ColumnsPins[Local_u8Iter_Columns]));

            MDIO_enuSetPinValue(Local_enumPort, Local_enumPin, MDIO_HIGH);
        }
        return Local_enuErrorStatus;
    }
}

