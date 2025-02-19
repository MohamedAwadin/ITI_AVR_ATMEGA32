#include "HLCD.h"
#include "HLCD_Config.h"

#define F_CPU 8000000UL
#include <util/delay.h>

#if (HLCD_Mode == _8Bit)

void HLCD_vWriteCommand(u8 Copy_u8Command)
{
    
    u8 Local_u8_RSPortNum = GET_HIGH_NIB(HLCD_RS);
    u8 Local_u8_RSPinNum = GET_LOW_NIB(HLCD_RS);
    u8 Local_u8_RWPortNum = GET_HIGH_NIB(HLCD_RW);
    u8 Local_u8_RWPinNum = GET_LOW_NIB(HLCD_RW);
    u8 Local_u8_ENPortNum = GET_HIGH_NIB(HLCD_EN);
    u8 Local_u8_ENPinNum = GET_LOW_NIB(HLCD_EN);

    MDIO_enuSetPinValue(Local_u8_RSPortNum, Local_u8_RSPinNum, MDIO_LOW);
    MDIO_enuSetPinValue(Local_u8_RWPortNum, Local_u8_RWPinNum, MDIO_LOW);
    MDIO_enuSetPortWValue(HLCD_PORT_8Bit, Copy_u8Command);
    MDIO_enuSetPinValue(Local_u8_ENPortNum, Local_u8_ENPinNum, MDIO_HIGH);
    // _delay_ms(1);
    _delay_ms(HLCD_COMMAND_DELAY);
    MDIO_enuSetPinValue(Local_u8_ENPortNum, Local_u8_ENPinNum, MDIO_LOW);
    // _delay_ms(1);
    _delay_ms(HLCD_COMMAND_DELAY);
}

void HLCD_vWriteData(u8 Copy_u8Data)
{
    u8 Local_u8_RSPortNum = GET_HIGH_NIB(HLCD_RS);
    u8 Local_u8_RSPinNum = GET_LOW_NIB(HLCD_RS);
    u8 Local_u8_RWPortNum = GET_HIGH_NIB(HLCD_RW);
    u8 Local_u8_RWPinNum = GET_LOW_NIB(HLCD_RW);
    u8 Local_u8_ENPortNum = GET_HIGH_NIB(HLCD_EN);
    u8 Local_u8_ENPinNum = GET_LOW_NIB(HLCD_EN);

    MDIO_enuSetPinValue(Local_u8_RSPortNum, Local_u8_RSPinNum, MDIO_HIGH);
    MDIO_enuSetPinValue(Local_u8_RWPortNum, Local_u8_RWPinNum, MDIO_LOW);
    MDIO_enuSetPortWValue(HLCD_PORT_8Bit, Copy_u8Data);
    MDIO_enuSetPinValue(Local_u8_ENPortNum, Local_u8_ENPinNum, MDIO_HIGH);
    //_delay_ms(1);
    _delay_ms(HLCD_COMMAND_DELAY);
    MDIO_enuSetPinValue(Local_u8_ENPortNum, Local_u8_ENPinNum, MDIO_LOW);
    //_delay_ms(1);
    _delay_ms(HLCD_COMMAND_DELAY);
}

void HLCD_vInit(void)
{
    MPORT_enuSetPinDirection(HLCD_RS      , MPORT_PORT_PIN_OUTPUT);
    MPORT_enuSetPinDirection(HLCD_RW      , MPORT_PORT_PIN_OUTPUT);
    MPORT_enuSetPinDirection(HLCD_EN      , MPORT_PORT_PIN_OUTPUT);
    MPORT_enuSetPortDirection(HLCD_PORT_8Bit, MPORT_ALL_OUTPUT);
    //_delay_ms(50);
    _delay_ms(HLCD_POWER_UP_DELAY);
    HLCD_vWriteCommand(HLCD_FUNC_SET_INS_8Bit);
    // _delay_ms(1);
    _delay_ms(HLCD_COMMAND_DELAY);
    HLCD_vWriteCommand(HLCD_DISPLAY_CONTROL_INS_8Bit);
    //_delay_ms(1);
    _delay_ms(HLCD_COMMAND_DELAY);
    HLCD_vWriteCommand(HLCD_CLEAR_MODE_INS); // Display Clear
    // _delay_ms(2);
    _delay_ms(HLCD_CLEAR_DELAY);
    HLCD_vWriteCommand(HLCD_ENTRY_MODE_INS_8Bit);
    //_delay_ms(1);
    _delay_ms(HLCD_COMMAND_DELAY);
    
}

#elif (HLCD_Mode == _4Bit)
void HLCD_vWriteCommand(u8 Copy_u8Command)
{
    u8 Local_u8_RSPortNum = GET_HIGH_NIB(HLCD_RS);
    u8 Local_u8_RSPinNum = GET_LOW_NIB(HLCD_RS);
    u8 Local_u8_RWPortNum = GET_HIGH_NIB(HLCD_RW);
    u8 Local_u8_RWPinNum = GET_LOW_NIB(HLCD_RW);
    u8 Local_u8_ENPortNum = GET_HIGH_NIB(HLCD_EN);
    u8 Local_u8_ENPinNum = GET_LOW_NIB(HLCD_EN);

    u8 Local_u8_D0PortNum =  GET_HIGH_NIB(HLCD_D0_4Bit);
    u8 Local_u8_D0PinNum  =  GET_LOW_NIB(HLCD_D0_4Bit);
    
    u8 Local_u8_D1PortNum =  GET_HIGH_NIB(HLCD_D1_4Bit);
    u8 Local_u8_D1PinNum  =  GET_LOW_NIB(HLCD_D1_4Bit);
    
    u8 Local_u8_D2PortNum =  GET_HIGH_NIB(HLCD_D2_4Bit);
    u8 Local_u8_D2PinNum  =  GET_LOW_NIB(HLCD_D2_4Bit);
    
    u8 Local_u8_D3PortNum =  GET_HIGH_NIB(HLCD_D3_4Bit);
    u8 Local_u8_D3PinNum  =  GET_LOW_NIB(HLCD_D3_4Bit);



    MDIO_enuSetPinValue(Local_u8_RSPortNum, Local_u8_RSPinNum, MDIO_LOW);
    MDIO_enuSetPinValue(Local_u8_RWPortNum, Local_u8_RWPinNum, MDIO_LOW);
    

    MDIO_enuSetPinValue(Local_u8_D0PortNum, Local_u8_D0PinNum, READ_BIT(Copy_u8Command, 4));
    MDIO_enuSetPinValue(Local_u8_D1PortNum, Local_u8_D1PinNum, READ_BIT(Copy_u8Command, 5));
    MDIO_enuSetPinValue(Local_u8_D2PortNum, Local_u8_D2PinNum, READ_BIT(Copy_u8Command, 6));
    MDIO_enuSetPinValue(Local_u8_D3PortNum, Local_u8_D3PinNum, READ_BIT(Copy_u8Command, 7));
    
    MDIO_enuSetPinValue(Local_u8_ENPortNum, Local_u8_ENPinNum, MDIO_HIGH);
    _delay_ms(HLCD_COMMAND_DELAY);
    MDIO_enuSetPinValue(Local_u8_ENPortNum, Local_u8_ENPinNum, MDIO_LOW);
    _delay_ms(HLCD_COMMAND_DELAY);

    MDIO_enuSetPinValue(Local_u8_D0PortNum, Local_u8_D0PinNum, READ_BIT(Copy_u8Command, 0));
    MDIO_enuSetPinValue(Local_u8_D1PortNum, Local_u8_D1PinNum, READ_BIT(Copy_u8Command, 1));
    MDIO_enuSetPinValue(Local_u8_D2PortNum, Local_u8_D2PinNum, READ_BIT(Copy_u8Command, 2));
    MDIO_enuSetPinValue(Local_u8_D3PortNum, Local_u8_D3PinNum, READ_BIT(Copy_u8Command, 3));

    MDIO_enuSetPinValue(Local_u8_ENPortNum, Local_u8_ENPinNum, MDIO_HIGH);
    _delay_ms(HLCD_COMMAND_DELAY);
    MDIO_enuSetPinValue(Local_u8_ENPortNum, Local_u8_ENPinNum, MDIO_LOW);
    _delay_ms(HLCD_COMMAND_DELAY);

}

void HLCD_vWriteData(u8 Copy_u8Data)
{
    u8 Local_u8_RSPortNum = GET_HIGH_NIB(HLCD_RS);
    u8 Local_u8_RSPinNum = GET_LOW_NIB(HLCD_RS);
    u8 Local_u8_RWPortNum = GET_HIGH_NIB(HLCD_RW);
    u8 Local_u8_RWPinNum = GET_LOW_NIB(HLCD_RW);
    u8 Local_u8_ENPortNum = GET_HIGH_NIB(HLCD_EN);
    u8 Local_u8_ENPinNum = GET_LOW_NIB(HLCD_EN);

    u8 Local_u8_D0PortNum =  GET_HIGH_NIB(HLCD_D0_4Bit);
    u8 Local_u8_D0PinNum  =  GET_LOW_NIB(HLCD_D0_4Bit);
    
    u8 Local_u8_D1PortNum =  GET_HIGH_NIB(HLCD_D1_4Bit);
    u8 Local_u8_D1PinNum  =  GET_LOW_NIB(HLCD_D1_4Bit);
    
    u8 Local_u8_D2PortNum =  GET_HIGH_NIB(HLCD_D2_4Bit);
    u8 Local_u8_D2PinNum  =  GET_LOW_NIB(HLCD_D2_4Bit);
    
    u8 Local_u8_D3PortNum =  GET_HIGH_NIB(HLCD_D3_4Bit);
    u8 Local_u8_D3PinNum  =  GET_LOW_NIB(HLCD_D3_4Bit);



    MDIO_enuSetPinValue(Local_u8_RSPortNum, Local_u8_RSPinNum, MDIO_HIGH);
    MDIO_enuSetPinValue(Local_u8_RWPortNum, Local_u8_RWPinNum, MDIO_LOW);



    MDIO_enuSetPinValue(Local_u8_D0PortNum, Local_u8_D0PinNum, READ_BIT(Copy_u8Data, 4));
    MDIO_enuSetPinValue(Local_u8_D1PortNum, Local_u8_D1PinNum, READ_BIT(Copy_u8Data, 5));
    MDIO_enuSetPinValue(Local_u8_D2PortNum, Local_u8_D2PinNum, READ_BIT(Copy_u8Data, 6));
    MDIO_enuSetPinValue(Local_u8_D3PortNum, Local_u8_D3PinNum, READ_BIT(Copy_u8Data, 7));
    
    MDIO_enuSetPinValue(Local_u8_ENPortNum, Local_u8_ENPinNum, MDIO_HIGH);
    _delay_ms(HLCD_COMMAND_DELAY);
    MDIO_enuSetPinValue(Local_u8_ENPortNum, Local_u8_ENPinNum, MDIO_LOW);
    _delay_ms(HLCD_COMMAND_DELAY);

    MDIO_enuSetPinValue(Local_u8_D0PortNum, Local_u8_D0PinNum, READ_BIT(Copy_u8Data, 0));
    MDIO_enuSetPinValue(Local_u8_D1PortNum, Local_u8_D1PinNum, READ_BIT(Copy_u8Data, 1));
    MDIO_enuSetPinValue(Local_u8_D2PortNum, Local_u8_D2PinNum, READ_BIT(Copy_u8Data, 2));
    MDIO_enuSetPinValue(Local_u8_D3PortNum, Local_u8_D3PinNum, READ_BIT(Copy_u8Data, 3));

    MDIO_enuSetPinValue(Local_u8_ENPortNum, Local_u8_ENPinNum, MDIO_HIGH);
    _delay_ms(HLCD_COMMAND_DELAY);
    MDIO_enuSetPinValue(Local_u8_ENPortNum, Local_u8_ENPinNum, MDIO_LOW);
    _delay_ms(HLCD_COMMAND_DELAY);

}

void HLCD_vInit(void)
{
    MPORT_enuSetPinDirection(HLCD_RS      , MPORT_PORT_PIN_OUTPUT);
    MPORT_enuSetPinDirection(HLCD_RW      , MPORT_PORT_PIN_OUTPUT);
    MPORT_enuSetPinDirection(HLCD_EN      , MPORT_PORT_PIN_OUTPUT);
    MPORT_enuSetPinDirection(HLCD_D0_4Bit , MPORT_PORT_PIN_OUTPUT);
    MPORT_enuSetPinDirection(HLCD_D1_4Bit , MPORT_PORT_PIN_OUTPUT);
    MPORT_enuSetPinDirection(HLCD_D2_4Bit , MPORT_PORT_PIN_OUTPUT);
    MPORT_enuSetPinDirection(HLCD_D3_4Bit , MPORT_PORT_PIN_OUTPUT);
    

    //_delay_ms(50);
    _delay_ms(HLCD_POWER_UP_DELAY);
	HLCD_vWriteCommand(HLCD_FUNC_SET__4Bit);
	//_delay_ms(1);
    _delay_ms(HLCD_COMMAND_DELAY);
	HLCD_vWriteCommand(HLCD_FUNC_SET_INS_4Bit);
	//_delay_ms(1);
    _delay_ms(HLCD_COMMAND_DELAY);
	HLCD_vWriteCommand(HLCD_DISPLAY_CONTROL_INS_4Bit);
	//_delay_ms(1);
    _delay_ms(HLCD_COMMAND_DELAY);
	HLCD_vWriteCommand(HLCD_CLEAR_MODE_INS);
	//_delay_ms(2);
    _delay_ms(HLCD_CLEAR_DELAY);
	HLCD_vWriteCommand(HLCD_ENTRY_MODE_INS_4Bit);
	//_delay_ms(1);
    _delay_ms(HLCD_COMMAND_DELAY);
}
#else 

#error "ERROR :: HAL LAYER :: Using HLCD DRIVER, and WRONG Configuration For (HLCD_Mode) Macro \
PLEASE CONFIGURE IT ONLY WITH _8Bit OR _4Bit"

#endif



void HLCD_vWriteString(u8 *Add_pu8String)
{
    u8 Local_u8Iter;
    for (Local_u8Iter = 0; Add_pu8String[Local_u8Iter]; Local_u8Iter++)
    {
        HLCD_vWriteData(Add_pu8String[Local_u8Iter]);
    }
}
void HLCD_vClearScreen(void)
{
    HLCD_vWriteCommand(HLCD_CLEAR_MODE_INS);
}

void HLCD_vGoTo(u8 Copy_u8Line, u8 Copy_u8Cell)
{
    if (Copy_u8Line == 0)
    {
        HLCD_vWriteCommand(HLCD_LINE1_ADDRESS + Copy_u8Cell);
    }
    else if (Copy_u8Line == 1)
    {
        HLCD_vWriteCommand(HLCD_LINE2_ADDRESS + Copy_u8Cell);
    }
}

void HLCD_vWriteNumber(s64 Copy_s64Number)
{
    u8 Local_u8Iter_1 = 0, Local_u8Iter_2 = 0, Local_u8Reminder = 0, Local_u8Arrary_16Byte[16] = {0};
    if (Copy_s64Number == 0)
    {
        HLCD_vWriteData('0');
    }
    else
    {
        if (Copy_s64Number < 0)
        {
            Copy_s64Number = Copy_s64Number * (-1);
            HLCD_vWriteData('-');
        }
        while (Copy_s64Number > 0)
        {
            Local_u8Reminder = Copy_s64Number % 10;
            Local_u8Arrary_16Byte[Local_u8Iter_1] = Local_u8Reminder + '0';
            Local_u8Iter_1++;
            Copy_s64Number = Copy_s64Number / 10;
        }
        for (Local_u8Iter_2 = Local_u8Iter_1; Local_u8Iter_2 > 0; Local_u8Iter_2--)
        {
            HLCD_vWriteData(Local_u8Arrary_16Byte[Local_u8Iter_2 - 1]);
        }
    }
}

void HLCD_vGotoCGRAM(u8 Copy_u8BlockNumber)
{
    u8 Local_u8Location = Copy_u8BlockNumber * 8;
    HLCD_vWriteCommand(Local_u8Location + HLCD_CGRAM_ST_CC);
}

void HLCD_vStoreSpecialCharacter(u8 Copy_u8BlockNumber, u8 *Add_pu8Pattern)
{
    u8 Local_u8Iter = 0;
    HLCD_vGotoCGRAM(Copy_u8BlockNumber);
    for (Local_u8Iter = 0; Local_u8Iter < 8; Local_u8Iter++)
    {
        HLCD_vWriteData(Add_pu8Pattern[Local_u8Iter]);
    }
}

void HLCD_vDisplaySpecialCharacter(u8 Copy_u8BlockNumber, u8 *Add_pu8Pattern, u8 Copy_u8Line, u8 Copy_u8Cell)
{
    HLCD_vStoreSpecialCharacter(Copy_u8BlockNumber, Add_pu8Pattern);
    HLCD_vGoTo(Copy_u8Line, Copy_u8Cell);
    HLCD_vWriteData(Copy_u8BlockNumber);
}
