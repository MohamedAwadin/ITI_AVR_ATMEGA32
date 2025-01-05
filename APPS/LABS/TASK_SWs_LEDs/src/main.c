#include "HLED.h"
#include "HLED_Config.h"
#include "HSWITCH.h"
#include "HSWITCH_Config.h"

int main(void)
{
    HLED_enumErrorState_t errorStatus;
    u8 SwitchState1, SwitchState2, SwitchState3;

    /* Initialize the switch driver */
    HSWITCH_init();

    /* Initialize the LED driver */
    HLED_vInit();

    

    while (1)
    {
        
        HSWITCH_enuGetSwitchState(SWITCH_0, &SwitchState1);
        HSWITCH_enuGetSwitchState(SWITCH_1, &SwitchState2);
        HSWITCH_enuGetSwitchState(SWITCH_2, &SwitchState3);

        if (SwitchState1 == HSWITCH_PRESSED)
        {
            /* Turn on the Start LED */
            errorStatus = HLED_enuSetValue(LED_START, HLED_ON);
            if (errorStatus != HLED_enumErrSt_OK)
            {
            }
        }
        else
        {
            errorStatus = HLED_enuSetValue(LED_START, HLED_OFF);
            if (errorStatus != HLED_enumErrSt_OK)
            {
            }
        }


        if (SwitchState2 == HSWITCH_PRESSED)
        {
            /* Turn on the Stop LED */
            errorStatus = HLED_enuSetValue(LED_STOP, HLED_ON);
            if (errorStatus != HLED_enumErrSt_OK)
            {
            }
        }
        else
        {
            errorStatus = HLED_enuSetValue(LED_STOP, HLED_OFF);
            if (errorStatus != HLED_enumErrSt_OK)
            {
            }
        }

        if (SwitchState3 == HSWITCH_PRESSED)
        {
            /* Turn on the Alert LED */
            errorStatus = HLED_enuSetValue(LED_ALERT, HLED_ON);
            if (errorStatus != HLED_enumErrSt_OK)
            {
            }
        }
        else
        {
            errorStatus = HLED_enuSetValue(LED_ALERT, HLED_OFF);
            if (errorStatus != HLED_enumErrSt_OK)
            {
            }
        }
    }
}
