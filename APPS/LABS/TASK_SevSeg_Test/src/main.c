

#include "HSEVENSEG.h"
#include "HSEVENSEG_Config.h"
#include "HSWITCH.h"
#include "HSWITCH_Config.h"
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
    
    u8 SwitchState1;

    /* Initialize the switch driver */
    HSWITCH_init();

    /* Initialize the LED driver */
    HSEVENSEG_vInit();
    char count = 0;
    while (1)
    {

        HSWITCH_enuGetSwitchState(SWITCH_0, &SwitchState1);

        if (SwitchState1 == HSWITCH_PRESSED)
        {
            /* Turn on the Start LED */
            count++;
            if (count > 99)
            {
                count =0;
            }
            HSEVENSEG_enuSetMultiDigitValue(count);
            //while (SwitchState1 == HSWITCH_PRESSED)
            _delay_ms(1000);
            
        }
        else
        {
            
        }
         
        //_delay_ms(500);
    }
}