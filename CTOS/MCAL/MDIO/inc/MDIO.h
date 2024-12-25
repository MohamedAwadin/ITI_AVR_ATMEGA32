/*
 * Dio.h
 *
 * Created: 17/12/2024 1:03:44 PM
 *  Author: Mohamed Awadin
 */ 


#ifndef MDIO_H_
#define MDIO_H_


#include "StdTypes.h"
#include "Utils.h"
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
	}Copy_enuPortNum_t;

typedef enum{
	MDIO_PIN0 = 0,
	MDIO_PIN1 = 1,
	MDIO_PIN2,
	MDIO_PIN3,
	MDIO_PIN4,
	MDIO_PIN5,
	MDIO_PIN6,
	MDIO_PIN7
	}Copy_enuPinNum_t;

typedef enum{
	MDIO_LOW=0,
	MDIO_HIGH
	}Copy_enuPinState_t;	
	
typedef enum{
	MDIO_OUTPUT,
	MDIO_INFREE,
	MDIO_INPULLUP
	}Copy_enuPinConfigration_t;
	
	
typedef enum{
	MDIO_ALL_LOW = 0 ,
	MDIO_ALL_HIGH = 1 
	}Copy_enuPortState_t;
	
typedef enum{
	MDIO_ALL_OUTPUT,
	MDIO_ALL_INFREE,
	MDIO_ALL_INPULLUP
}Copy_enuPortConfigration_t;	
	
	


MDIO_enuErrorStatus_t MDIO_enuSetPinConfigration (Copy_enuPortNum_t Copy_enuPortNum ,Copy_enuPinNum_t            Copy_enuPinNum             ,Copy_enuPinConfigration_t Copy_enuPinConfigration);


MDIO_enuErrorStatus_t MDIO_enuSetPortConfigration(Copy_enuPortNum_t Copy_enuPortNum ,Copy_enuPortConfigration_t  Copy_enuPortConfigration);


MDIO_enuErrorStatus_t MDIO_enuSetPinValue        (Copy_enuPortNum_t Copy_enuPortNum ,Copy_enuPinNum_t            Copy_enuPinNum             ,Copy_enuPinState_t Copy_enuPinState);


MDIO_enuErrorStatus_t MDIO_enuSetPortValue       (Copy_enuPortNum_t Copy_enuPortNum ,Copy_enuPortState_t         Copy_enuPortState);


MDIO_enuErrorStatus_t MDIO_enuSetPortWValue      (Copy_enuPortNum_t Copy_enuPortNum ,u8                          Copy_u8PortState);


MDIO_enuErrorStatus_t MDIO_enuGetPinValue        (Copy_enuPortNum_t Copy_enuPortNum ,Copy_enuPinNum_t            Copy_enuPinNum             ,u8* Add_pu8PinValue);

MDIO_enuErrorStatus_t MDIO_enuInitPin(Copy_enuPinNum_t Copy_enuPinNum , Copy_enuPinConfigration_t Copy_enuPinConfigration );

void MDIO_vInit(void);

void MDIO_vSetPin(Copy_enuPortNum_t Copy_u8PortNum, Copy_enuPinNum_t Copy_u8PinNum, Copy_enuPinState_t Copy_u8Value);


extern const Copy_enuPinConfigration_t PinsStatusArray[MDIO_NUM_OF_PINS * MDIO_NUM_OF_PORTS];




#endif /* MDIO_H_ */