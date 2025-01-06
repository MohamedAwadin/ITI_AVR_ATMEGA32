

#include "HSEVENSEG.h"
#include "HSEVENSEG_Config.h"
// #define  F_CPU    8000000UL
// #include <util/delay.h>

int main(void) {
    HSEVENSEG_enumErrorStatus_t errorStatus;

    /* Initialize the Seven-Segment Driver */
    HSEVENSEG_vInit();

    
    // HSEVENSEG_vSetValue(SEVENSEG_0 , 1);
    // HSEVENSEG_vSetValue(SEVENSEG_1 , 0);
    // HSEVENSEG_vSetValue(SEVENSEG_2 , 5);
    // HSEVENSEG_vSetValue(SEVENSEG_3 , 3);

     HSEVENSEG_enuSetMultiDigitValue(123);
    
    

    
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 8; j++)
    //     {
    //         MDIO_enuSetPinValue(i,j,MDIO_HIGH);
    //     }
        
    // }
    
    
    while (1) {
    
        
    }
}