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
	}Copy_enuState_t;	
	
typedef enum{
	MDIO_OUTPUT,
	MDIO_INFREE,
	MDIO_INPULLUP
	}Copy_enuConfigration_t;
	
	
typedef enum{
	MDIO_ALL_LOW = 0 ,
	MDIO_ALL_HIGH = 1 
	}Copy_enuPortState_t;
	
typedef enum{
	MDIO_ALL_OUTPUT,
	MDIO_ALL_INFREE,
	MDIO_ALL_INPULLUP
}Copy_enuPortConfigration_t;	
	
	


MDIO_enuErrorStatus_t MDIO_enuSetPinConfigration(Copy_enuPortNum_t port,Copy_enuPinNum_t pin,Copy_enuConfigration_t confg);
MDIO_enuErrorStatus_t MDIO_enuSetPortConfigration(Copy_enuPortNum_t port,Copy_enuPortConfigration_t  confg);
MDIO_enuErrorStatus_t MDIO_enuSetPinValue( Copy_enuPortNum_t port , Copy_enuPinNum_t pin , Copy_enuState_t state);
MDIO_enuErrorStatus_t MDIO_enuSetPortValue(Copy_enuPortNum_t port , Copy_enuPortState_t portState);
MDIO_enuErrorStatus_t MDIO_enuSetPortWValue(Copy_enuPortNum_t port , u8 portState);
MDIO_enuErrorStatus_t MDIO_enuGetPinValue(Copy_enuPortNum_t port ,Copy_enuPinNum_t pin ,u8* Add_pu8PinValue);








#endif /* MDIO_H_ */