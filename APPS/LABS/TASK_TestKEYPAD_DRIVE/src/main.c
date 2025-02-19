#include "MPORT.h"
#include "HLCD.h"
#include "HLCD_Config.h"
#include "HKEYPAD.h"
#include "HKEYPAD_Config.h"


int main(void)
{
    

    
    
    HLCD_vInit();
    HKEYPAD_vInit();
    u8 key = 0 ;

    // u8 str[] = "AWADIN";
    // HLCD_vWriteData('h');
    // HLCD_vWriteString(str);
    // HLCD_vGoTo(0,0);
    // HLCD_vWriteData('a');
    // HLCD_vGoTo(1,0);
    // HLCD_vWriteData('w');
    // HLCD_vGoTo(0,1);
    // HLCD_vWriteData('a');
    // HLCD_vGoTo(1,1);
    // HLCD_vWriteData('d');
    // HLCD_vGoTo(0,2);
    // HLCD_vWriteData('i');
    // HLCD_vGoTo(1,2);
    // HLCD_vWriteData('n');
    //HLCD_vWriteNumber(1446);
    // HLCD_vGoTo(1,0);
    // HLCD_vWriteNumber(-1444444444444446);
       



    while (1)
    {
        HKEYPAD_enumGetPressedValue(HKEYPAD_ID0, &key);
        HLCD_vGoTo(0,0);
        HLCD_vWriteData(key);
    }
}