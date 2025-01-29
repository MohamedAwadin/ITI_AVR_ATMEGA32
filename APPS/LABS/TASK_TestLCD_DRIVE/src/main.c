#include "MPORT.h"
#include "HLCD.h"
#include "HLCD_Config.h"

int main(void)
{
    u8 customChar[] = {
        0B00000,
        0B01110,
        0B01010,
        0B01110,
        0B00100,
        0B00100,
        0B11111,
        0B10001};
    
    // u8 Local_u8_RSPortNum = GET_HIGH_NIB(HLCD_RS);
    // u8 Local_u8_RSPinNum  = GET_LOW_NIB(HLCD_RS);
    // u8 Local_u8_ENPortNum = GET_HIGH_NIB(HLCD_EN);
    // u8 Local_u8_ENPinNum  = GET_LOW_NIB(HLCD_EN);
    // u8 Local_u8_RWPortNum = GET_HIGH_NIB(HLCD_RW);
    // u8 Local_u8_RWPinNum  = GET_LOW_NIB(HLCD_RW);

    MPort_vInit();
    // MDIO_enuSetPinValue(Local_u8_RSPortNum, Local_u8_RSPinNum,MDIO_HIGH);
    // MDIO_enuSetPinValue(Local_u8_ENPortNum, Local_u8_ENPinNum,MDIO_HIGH);
    // MDIO_enuSetPinValue(Local_u8_RWPortNum, Local_u8_RWPinNum,MDIO_HIGH);
    // MDIO_enuSetPortWValue(HLCD_PORT_8Bit,0xffUL);
    HLCD_vInit();
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
       HLCD_vDisplaySpecialCharacter(1, customChar, 0,0);



    while (1)
    {
    }
}