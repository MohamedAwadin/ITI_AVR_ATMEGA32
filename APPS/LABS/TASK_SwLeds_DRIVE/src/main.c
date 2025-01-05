#include "HLED.h"
#include "HLED_Config.h"
#include "HSWITCH.h"
#include "HSWITCH_Config.h"

int main(void)
{
    HLED_enumErrorState_t errorStatus;
    u8 SwitchState;

    /* Initialize the switch driver */
    HSWITCH_init();

    /* Initialize the LED driver */
    HLED_vInit();

    

    while (1)
    {
        /* Read the state of Switch 0 */
        HSWITCH_enuGetSwitchState(SWITCH_0, &SwitchState);

        if (SwitchState == HSWITCH_PRESSED)
        {
            /* Turn on the Start LED */
            errorStatus = HLED_enuSetValue(LED_START, HLED_ON);
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
    }
}
