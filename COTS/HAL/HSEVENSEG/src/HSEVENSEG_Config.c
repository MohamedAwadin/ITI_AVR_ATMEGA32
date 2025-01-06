
#include "HSEVENSEG_Config.h"
#include "HSEVENSEG.h"

/* Seven-Segment Configuration Array */
const HSEVENSEG_strConfig_t HSEVENSEG_strConfigArray[NUM_OF_SEVENSEGS] =
{
    /* Seven-Segment Display 0 */
    {
        {
            HSEVENSEG_PIN_A0,   /*Segment A*/
            HSEVENSEG_PIN_A1,   /*Segment B*/
            HSEVENSEG_PIN_A2,   /*Segment C*/
            HSEVENSEG_PIN_A3,   /*Segment D*/
            HSEVENSEG_PIN_A4,   /*Segment E*/
            HSEVENSEG_PIN_A5,   /*Segment F*/
            HSEVENSEG_PIN_A6    /*Segment G*/
        },
        HSEVENSEG_COMMON_CATHODE
    },
    /* Seven-Segment Display 1 */
    {
        {
            
            HSEVENSEG_PIN_B0,  /*Segment A*/
            HSEVENSEG_PIN_B1,  /*Segment B*/
            HSEVENSEG_PIN_B2,  /*Segment C*/
            HSEVENSEG_PIN_B3,  /*Segment D*/
            HSEVENSEG_PIN_B4,  /*Segment E*/
            HSEVENSEG_PIN_B5,  /*Segment F*/
            HSEVENSEG_PIN_B6  /*Segment G*/
        },
        HSEVENSEG_COMMON_CATHODE
    },
    /* Seven-Segment Display 2 */
    {
        {
            HSEVENSEG_PIN_C0, /*Segment A*/
            HSEVENSEG_PIN_C1, /*Segment B*/
            HSEVENSEG_PIN_C2, /*Segment C*/
            HSEVENSEG_PIN_C3, /*Segment D*/
            HSEVENSEG_PIN_C4, /*Segment E*/
            HSEVENSEG_PIN_C5, /*Segment F*/
            HSEVENSEG_PIN_C6 /*Segment G*/
        },
        HSEVENSEG_COMMON_CATHODE
    },
    /* Seven-Segment Display 3 */
    {
        {
            HSEVENSEG_PIN_D0,/*Segment A*/
            HSEVENSEG_PIN_D1,/*Segment B*/
            HSEVENSEG_PIN_D2,/*Segment C*/
            HSEVENSEG_PIN_D3,/*Segment D*/
            HSEVENSEG_PIN_D4,/*Segment E*/
            HSEVENSEG_PIN_D5,/*Segment F*/
            HSEVENSEG_PIN_D6/*Segment G*/
        },
        HSEVENSEG_COMMON_CATHODE
    }

};

