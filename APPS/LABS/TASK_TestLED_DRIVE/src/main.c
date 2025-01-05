#include "HLED.h"
#include "HLED_Config.h"


int main(void) {
    HLED_enumErrorState_t errorStatus;

    /* Initialize the LED driver */
    HLED_vInit();

    
    errorStatus = HLED_enuSetValue(LED_START, HLED_ON);
    if (errorStatus != HLED_enumErrSt_OK) {
        
    }

    
    errorStatus = HLED_enuSetValue(LED_STOP, HLED_OFF);
    if (errorStatus != HLED_enumErrSt_OK) {
        
    }

    
    while (1) {
        
    }
}