/*
 * Dio.h
 *
 * Created: 17/12/2024 1:03:44 PM
 *  Author: Mohamed Awadin
 */ 


#ifndef MDIO_H_
#define MDIO_H_


#include "StdTypes.h"
#include "Bit_Math.h"
#include "MemMap.h"
#include "MDIO_LCFG.h"
#include "MDIO_PBCFG.h"



typedef enum{
	MDIO_NOK=0, 
	MDIO_OK, 
	MDIO_InvalidPin,
	MDIO_InvalidPort,
	MDIO_InvalidConfg,
	MDIO_InvalidState
	}MDIO_enuErrorStatus_t;
	
typedef enum{
	MDIO_PORTA=0,
	MDIO_PORTB,
	MDIO_PORTC,
	MDIO_PORTD
	}MDIO_enuPortNum_t;

typedef enum{
	MDIO_PIN0 = 0,
	MDIO_PIN1 = 1,
	MDIO_PIN2,
	MDIO_PIN3,
	MDIO_PIN4,
	MDIO_PIN5,
	MDIO_PIN6,
	MDIO_PIN7
	}MDIO_enuPinNum_t;

typedef enum{
	MDIO_LOW=0,
	MDIO_HIGH
	}MDIO_enuPinState_t;	
	
typedef enum{
	MDIO_OUTPUT,
	MDIO_INFREE,
	MDIO_INPULLUP
	}MDIO_enuPinConfigration_t;
	
	
typedef enum{
	MDIO_ALL_LOW = 0 ,
	MDIO_ALL_HIGH = 1 
	}MDIO_enuPortState_t;
	
typedef enum{
	MDIO_ALL_OUTPUT,
	MDIO_ALL_INFREE,
	MDIO_ALL_INPULLUP
}MDIO_enuPortConfigration_t;	
	
	
extern const MDIO_enuPinConfigration_t PinsStatusArray[MDIO_NUM_OF_PINS * MDIO_NUM_OF_PORTS];



MDIO_enuErrorStatus_t MDIO_enuSetPinConfigration(MDIO_enuPortNum_t Copy_enuPortNum ,MDIO_enuPinNum_t Copy_enuPinNum,MDIO_enuPinConfigration_t Copy_enuPinConfigration);
MDIO_enuErrorStatus_t MDIO_enuSetPortConfigration(MDIO_enuPortNum_t Copy_enuPortNum ,MDIO_enuPortConfigration_t  Copy_enuPortConfigration);
MDIO_enuErrorStatus_t MDIO_enuSetPinValue  (MDIO_enuPortNum_t Copy_enuPortNum ,MDIO_enuPinNum_t    Copy_enuPinNum ,MDIO_enuPinState_t Copy_enuPinState);
MDIO_enuErrorStatus_t MDIO_enuSetPortValue (MDIO_enuPortNum_t Copy_enuPortNum ,MDIO_enuPortState_t Copy_enuPortState);
MDIO_enuErrorStatus_t MDIO_enuSetPortWValue(MDIO_enuPortNum_t Copy_enuPortNum ,u8                  Copy_u8PortState);
MDIO_enuErrorStatus_t MDIO_enuGetPinValue  (MDIO_enuPortNum_t Copy_enuPortNum ,MDIO_enuPinNum_t    Copy_enuPinNum ,u8* Add_pu8PinValue);
MDIO_enuErrorStatus_t MDIO_enuInitPin(MDIO_enuPinNum_t Copy_enuPinNum , MDIO_enuPinConfigration_t Copy_enuPinConfigration );



void MDIO_vInit(void);

void MDIO_vSetPin(MDIO_enuPortNum_t Copy_u8PortNum, MDIO_enuPinNum_t Copy_u8PinNum, MDIO_enuPinState_t Copy_u8Value);







#endif /* MDIO_H_ */