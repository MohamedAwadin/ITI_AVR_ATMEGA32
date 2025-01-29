#ifndef HLCD_H_
#define HLCD_H_


#include "MDIO.h"
#include "MPORT.h"
#include "StdTypes.h"
#include "Bit_Math.h"




/* LCD Driver Error States */
typedef enum {
    HLCD_enumErrSt_NOK = 0,         // Operation failed
    HLCD_enumErrSt_OK,              // Operation succeede
} HLCD_enumErrorState_t;





/* Function Prototypes */
void HLCD_vInit(void);
void HLCD_vWriteCommand(u8 Copy_u8Command);
void HLCD_vWriteData(u8 Copy_u8Data);
void HLCD_vWriteString(u8 *Add_pu8String);
void HLCD_vClearScreen(void);
void HLCD_vGoTo(u8 Copy_u8Line , u8 Copy_u8Cell);
void HLCD_vWriteNumber(s64 Copy_s64Number);
void HLCD_vGotoCGRAM(u8 Copy_u8BlockNumber);
void HLCD_vStoreSpecialCharacter(u8 Copy_u8BlockNumber, u8 *Add_pu8Pattern);
void HLCD_vDisplaySpecialCharacter(u8 Copy_u8BlockNumber, u8 *Add_pu8Pattern, u8 Copy_u8Line, u8 Copy_u8Cell);
/**************************/



#endif /* HLCD_H_ */