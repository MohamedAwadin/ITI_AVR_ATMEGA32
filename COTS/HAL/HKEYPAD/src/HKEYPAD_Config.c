#include "HKEYPAD_Config.h"
#include "HKEYPAD.h"


/**
 * @brief Configuration array for HKEYPADs.
 */
const HKEYPAD_strConfig_t HKEYPAD_gstrConfigArray[NUM_OF_HKEYPAD]=
{
    [HKEYPAD_ID0]=
    {
        .HKEYPAD_RowsPins =  
        {
            [HKEYPAD_enumROW_Pin0]=HKEYPAD_PIN_A0,
            [HKEYPAD_enumROW_Pin1]=HKEYPAD_PIN_A1,
            [HKEYPAD_enumROW_Pin2]=HKEYPAD_PIN_A2,
            [HKEYPAD_enumROW_Pin3]=HKEYPAD_PIN_A3,
        },
        .HKEYPAD_ColumnsPins =  
        {
            [HKEYPAD_enumColumn_Pin0]=HKEYPAD_PIN_A4,
            [HKEYPAD_enumColumn_Pin1]=HKEYPAD_PIN_A5,
            [HKEYPAD_enumColumn_Pin2]=HKEYPAD_PIN_A6,
            [HKEYPAD_enumColumn_Pin3]=HKEYPAD_PIN_A7,
        },

        .HKEYPAD_KEYArray = 
        {
            {'7','8','9','/'},
            {'4','5','6','*'},
            {'1','2','3','-'},
            {'c','0','=','+'},
        },

        .HKEYPAD_PullState =HKEYPAD_enumPullState_PullUp 
    },

    [HKEYPAD_ID1]=
    {
        .HKEYPAD_RowsPins =  
        {
            [HKEYPAD_enumROW_Pin0]=HKEYPAD_PIN_B0,
            [HKEYPAD_enumROW_Pin1]=HKEYPAD_PIN_B1,
            [HKEYPAD_enumROW_Pin2]=HKEYPAD_PIN_B2,
            [HKEYPAD_enumROW_Pin3]=HKEYPAD_PIN_B3,
        },
        .HKEYPAD_ColumnsPins =  
        {
            [HKEYPAD_enumColumn_Pin0]=HKEYPAD_PIN_B4,
            [HKEYPAD_enumColumn_Pin1]=HKEYPAD_PIN_B5,
            [HKEYPAD_enumColumn_Pin2]=HKEYPAD_PIN_B6,
            [HKEYPAD_enumColumn_Pin3]=HKEYPAD_PIN_B7,
        },

        .HKEYPAD_KEYArray = 
        {
            {'A','B','C','D'},
            {'E','F','G','H'},
            {'I','J','K','L'},
            {'M','N','O','P'},
        },

        .HKEYPAD_PullState =HKEYPAD_enumPullState_PullUp 
    },
};