#ifndef HLCD_CONFIG_H_
#define HLCD_CONFIG_H_

#include "HLCD.h"
#include "HLCD_Private.h"

/*********************************************************************/
/*In the first you must Select Mode of the LCD connection:
_4Bit : For 4 bit mode "Data pins can connect in any separated pins in the MCU"
_8Bit : For 8 bit mode "Data port"
*/
#define HLCD_Mode _4Bit

/*********************************************************************/
/********************Configration PINS******************************/

/***Select Instruction Pins***/
#define HLCD_RS                     MPORT_PIN_C0
#define HLCD_RW                     MPORT_PIN_C1
#define HLCD_EN                     MPORT_PIN_C2

#if (HLCD_Mode == _8Bit)
/*****For 8 Bit Mode*********/
/*********"Select Port Data"***********/
#define HLCD_PORT_8Bit              MPORT_PORTB
/*********"Config LCD Settings"***********/
#define HLCD_FUNC_SET_INS_8Bit        0x38                         // 0b 0 0 1 1(DL=0"4-bit"/DL=1"8-bit") 1(N=0"1 Line Display"/N=1"2 Line Display") 1(F=0"5x7 dots font"/N=1"5x10 dots font") X X
#define HLCD_DISPLAY_CONTROL_INS_8Bit 0x0C                        // 0b 0 0 0 0 1 1(D=0"Display off, data remains in DDRAM"/D=1"Display always ON") 0(D=0"Cursor Display off"/D=1"Cursor Display ON") 0(D=0"Cursor Blink off"/D=1"Cursor Blink ON")
#define HLCD_ENTRY_MODE_INS_8Bit      0x06                       // 0b 0 0 0 0 0 1 1(I/D=0"Decreases"/I/D=1"Increases">DDRAM address by 1) 0(S=0"Display does not Shift"/S=1"shifts to the left when ID = 1 and to the right when ID = O")

#elif (HLCD_Mode == _4Bit)

/*****For 4 Bit Mode*********/
/********"Select Pins Data"***********/
#define HLCD_D0_4Bit                MPORT_PIN_C3
#define HLCD_D1_4Bit                MPORT_PIN_C4
#define HLCD_D2_4Bit                MPORT_PIN_C5
#define HLCD_D3_4Bit                MPORT_PIN_C6

/*********"Config LCD Settings"***********/
#define HLCD_FUNC_SET_INS_4Bit		     	0x28	   // 0b 0 0 1 1(DL=0"4-bit"/DL=1"8-bit") 1(N=0"1 Line Display"/N=1"2 Line Display") 1(F=0"5x7 dots font"/N=1"5x10 dots font") X X
#define HLCD_DISPLAY_CONTROL_INS_4Bit		0x0C	  // 0b 0 0 0 0 1 1(D=0"Display off, data remains in DDRAM"/D=1"Display always ON") 0(C=0"Cursor Display off"/C=1"Cursor Display ON") 0(B=0"Cursor Blink off"/B=1"Cursor Blink ON")
#define HLCD_ENTRY_MODE_INS_4Bit	        0x06	 // 0b 0 0 0 0 0 1 1(I/D=0"Decreases"/I/D=1"Increases">DDRAM address by 1) 0(S=0"Display does not Shift"/S=1"shifts to the left when ID = 1 and to the right when ID = O")

//#elif ((HLCD_Mode != _8Bit) || (HLCD_Mode != _4Bit))
#else
#error "ERROR :: HAL LAYER :: Using HLCD DRIVER, and WRONG Configuration For HLCD_Mode Macro \
PLEASE CONFIGURE IT ONLY WITH _8Bit OR _4Bit"

#endif



#endif