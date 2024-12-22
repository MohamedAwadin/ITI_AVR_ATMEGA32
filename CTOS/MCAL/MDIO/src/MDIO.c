/*
 * Dio.c
 *
 * Created: 17/12/2024 1:03:24 PM
 *  Author: Mohamed Awadin
 */ 

#include "MDIO.h"



MDIO_enuErrorStatus_t MDIO_enuSetPinConfigration(Copy_enuPortNum_t port,Copy_enuPinNum_t pin,Copy_enuConfigration_t confg){
	
	MDIO_enuErrorStatus_t Ret_enuError ;
	switch(confg){
		
		case MDIO_OUTPUT:
		
			switch(port){
				
				case MDIO_PORTA:
					SET_BIT(DDRA,pin);
					CLEAR_BIT(PORTA,pin);
					Ret_enuError = MDIO_OK;
				break;
				case MDIO_PORTB:
					SET_BIT(DDRB,pin);
					CLEAR_BIT(PORTB,pin);
					Ret_enuError = MDIO_OK;
				break;
				case MDIO_PORTC:
					SET_BIT(DDRC,pin);
					CLEAR_BIT(PORTC,pin);
					Ret_enuError = MDIO_OK;
				break;
				case MDIO_PORTD:
					SET_BIT(DDRD,pin);
					CLEAR_BIT(PORTD,pin);
					Ret_enuError = MDIO_OK;
				break;
				default:
					Ret_enuError = MDIO_InvalidPort;
				break;
			}
		break;
		
		case MDIO_INFREE:
		switch(port){
			case MDIO_PORTA:
				CLEAR_BIT(DDRA,pin);
				CLEAR_BIT(PORTA,pin);
				Ret_enuError = MDIO_OK;
			break;
			case MDIO_PORTB:
				CLEAR_BIT(DDRB,pin);
				CLEAR_BIT(PORTB,pin);
				Ret_enuError = MDIO_OK;
			break;
			case MDIO_PORTC:
				CLEAR_BIT(DDRC,pin);
				CLEAR_BIT(PORTC,pin);
				Ret_enuError = MDIO_OK;
			break;
			case MDIO_PORTD:
				CLEAR_BIT(DDRD,pin);
				CLEAR_BIT(PORTD,pin);
				Ret_enuError = MDIO_OK;
			break;
			default:
				Ret_enuError = MDIO_InvalidPort;
			break;
			
		}
		break;
		
		case MDIO_INPULLUP:
		switch(port){
			case MDIO_PORTA:
				CLEAR_BIT(DDRA,pin);
				SET_BIT(PORTA,pin);
				Ret_enuError = MDIO_OK;
			break;
			case MDIO_PORTB:
				CLEAR_BIT(DDRB,pin);
				SET_BIT(PORTB,pin);
				Ret_enuError = MDIO_OK;
			break;
			case MDIO_PORTC:
				CLEAR_BIT(DDRC,pin);
				SET_BIT(PORTC,pin);
				Ret_enuError = MDIO_OK;
			break;
			case MDIO_PORTD:
				CLEAR_BIT(DDRD,pin);
				SET_BIT(PORTD,pin);
				Ret_enuError = MDIO_OK;
			break;
			default:
				Ret_enuError = MDIO_InvalidPort;
			break;
		}
		break;
		default:
			Ret_enuError = MDIO_InvalidConfg;
		break;
	}
	return Ret_enuError;
}
MDIO_enuErrorStatus_t MDIO_enuSetPortConfigration(Copy_enuPortNum_t port,Copy_enuPortConfigration_t  confg){
	
	MDIO_enuErrorStatus_t Ret_enuError ;
	
	switch(confg){
		
		case MDIO_ALL_OUTPUT:
			switch(port){
				case MDIO_PORTA:
					DDRA = 0xff;
					PORTA= 0x0;
					Ret_enuError = MDIO_OK;
				break;
				
				case MDIO_PORTB:
					DDRB = 0xff;
					PORTB= 0x0;
					Ret_enuError = MDIO_OK;
				
				break;
				
				case MDIO_PORTC:
					DDRC = 0xff;
					PORTC= 0x0;
					Ret_enuError = MDIO_OK;
				
				break;
				case MDIO_PORTD:
					DDRD = 0xff;
					PORTD= 0x0;
					Ret_enuError = MDIO_OK;
				break;
				default:
				Ret_enuError = MDIO_InvalidPort;
				break;
			}
		
		break;
		
		case MDIO_ALL_INFREE:
			switch(port){
				case MDIO_PORTA:
					DDRA = 0x0;
					PORTA= 0x0;
					Ret_enuError = MDIO_OK;
				break;
				
				case MDIO_PORTB:
					DDRB = 0x0;
					PORTB= 0x0;
					Ret_enuError = MDIO_OK;
				break;
				
				case MDIO_PORTC:
					DDRC = 0x0;
					PORTC= 0x0;
					Ret_enuError = MDIO_OK;
				break;
				
				case MDIO_PORTD:
					DDRD = 0x0;
					PORTD= 0x0;
					Ret_enuError = MDIO_OK;
				break;
				
				default:
				Ret_enuError = MDIO_InvalidPort;
				break;
			}
		break;
		
		case MDIO_ALL_INPULLUP:
			switch(port){
				case MDIO_PORTA:
					DDRA = 0x0;
					PORTA= 0xFF;
					Ret_enuError = MDIO_OK;
				break;
				
				case MDIO_PORTB:
					DDRB = 0x0;
					PORTB= 0xFF;
					Ret_enuError = MDIO_OK;
				break;
				
				case MDIO_PORTC:
					DDRC = 0x0;
					PORTC= 0xFF;
					Ret_enuError = MDIO_OK;
				break;
				
				case MDIO_PORTD:
					DDRD = 0x0;
					PORTD= 0xFF;
					Ret_enuError = MDIO_OK;
				break;
				
				default:
				Ret_enuError = MDIO_InvalidPort;
				break;
			}
		break;
		
		default:
		Ret_enuError = MDIO_InvalidConfg ;
		break;
		
	}
	return Ret_enuError;
}
MDIO_enuErrorStatus_t MDIO_enuSetPinValue( Copy_enuPortNum_t port , Copy_enuPinNum_t pin , Copy_enuState_t state)
{
	MDIO_enuErrorStatus_t Ret_enuError ;
	if ((pin>=0)&&(pin<8))
	{
		switch(state){
			case MDIO_HIGH:
			switch(port){
				case MDIO_PORTA:
				SET_BIT(PORTA,pin);
				Ret_enuError = MDIO_OK;
				break;
				case MDIO_PORTB:
				SET_BIT(PORTB,pin);
				Ret_enuError = MDIO_OK;
				break;
				case MDIO_PORTC:
				SET_BIT(PORTC,pin);
				Ret_enuError = MDIO_OK;
				break;
				case MDIO_PORTD:
				SET_BIT(PORTD,pin);
				Ret_enuError = MDIO_OK;
				break;
				default:
				Ret_enuError = MDIO_InvalidPort;
				break;
			}
			break;
			case MDIO_LOW:
			switch(port){
				case MDIO_PORTA:
				CLEAR_BIT(PORTA,pin);
				Ret_enuError = MDIO_OK;
				break;
				case MDIO_PORTB:
				CLEAR_BIT(PORTB,pin);
				Ret_enuError = MDIO_OK;
				break;
				case MDIO_PORTC:
				CLEAR_BIT(PORTC,pin);
				Ret_enuError = MDIO_OK;
				break;
				case MDIO_PORTD:
				CLEAR_BIT(PORTD,pin);
				Ret_enuError = MDIO_OK;
				break;
				default:
				Ret_enuError = MDIO_InvalidPort;
				break;
			}
			break;
			
			default:
			Ret_enuError = MDIO_InvalidState;
			break;
		}
	}
	else{
		Ret_enuError = MDIO_InvalidPin;
	}
	return Ret_enuError;
}
MDIO_enuErrorStatus_t MDIO_enuSetPortValue(Copy_enuPortNum_t port , Copy_enuPortState_t portState)
{
	MDIO_enuErrorStatus_t Ret_enuError ;
	
	switch(portState){
		case MDIO_ALL_LOW:
		switch(port){
			case MDIO_PORTA:
			PORTA= 0x0;
			Ret_enuError = MDIO_OK;
			break;
			
			case MDIO_PORTB:
			PORTB= 0x0;
			Ret_enuError = MDIO_OK;
			break;
			
			case MDIO_PORTC:
			PORTC= 0x0;
			Ret_enuError = MDIO_OK;
			break;
			
			case MDIO_PORTD:
			PORTD= 0x0;
			Ret_enuError = MDIO_OK;
			break;
			
			default:
			Ret_enuError = MDIO_InvalidPort;
			break;
		}
		break;
		
		case MDIO_ALL_HIGH:
		switch(port){
			case MDIO_PORTA:
			PORTA= 0xFF;
			Ret_enuError = MDIO_OK;
			break;
			
			case MDIO_PORTB:
			PORTB= 0xFF;
			Ret_enuError = MDIO_OK;
			
			break;
			
			case MDIO_PORTC:
			PORTC= 0xFF;
			Ret_enuError = MDIO_OK;
			break;
			
			case MDIO_PORTD:
			PORTD= 0xFF;
			Ret_enuError = MDIO_OK;
			break;
			default:
			Ret_enuError = MDIO_InvalidPort;
			break;
		}
		
		break;
		
		default:
		Ret_enuError = MDIO_InvalidState ;
		break;
		
	}
	return Ret_enuError;
}
MDIO_enuErrorStatus_t MDIO_enuGetPinValue(Copy_enuPortNum_t port ,Copy_enuPinNum_t pin ,u8* Add_pu8PinValue)
{
	MDIO_enuErrorStatus_t Ret_enuError ;
	if ((pin>=0)&&(pin<8))
	{
		switch(port){
			
			case MDIO_PORTA:
			*Add_pu8PinValue = READ_BIT(PINA, pin);
			Ret_enuError = MDIO_OK;
			break;
			
			case MDIO_PORTB:
			*Add_pu8PinValue = READ_BIT(PINB, pin);
			Ret_enuError = MDIO_OK;
			break;
			
			case MDIO_PORTC:
			*Add_pu8PinValue = READ_BIT(PINC, pin);
			Ret_enuError = MDIO_OK;
			break;
			
			case MDIO_PORTD:
			*Add_pu8PinValue = READ_BIT(PIND, pin);
			Ret_enuError = MDIO_OK;
			break;
			
			default:
			Ret_enuError = MDIO_InvalidPort;
			break;
			
		}
	}
	else
	{
		Ret_enuError = MDIO_InvalidPin;
	}
	
	return Ret_enuError;
}

MDIO_enuErrorStatus_t MDIO_enuSetPortWValue(Copy_enuPortNum_t port , u8 portState)
{
	MDIO_enuErrorStatus_t Ret_enuError ;
		
		switch(port){
			case MDIO_PORTA:
			PORTA= portState;
			Ret_enuError = MDIO_OK;
			break;
			
			case MDIO_PORTB:
			PORTB= portState;
			Ret_enuError = MDIO_OK;
			break;
			
			case MDIO_PORTC:
			PORTC= portState;
			Ret_enuError = MDIO_OK;
			break;
			
			case MDIO_PORTD:
			PORTD= portState;
			Ret_enuError = MDIO_OK;
			break;
			
			default:
			Ret_enuError = MDIO_InvalidPort;
			break;
	}
	return Ret_enuError;
	
}