/*
 * Dio.c
 *
 * Created: 17/12/2024 1:03:24 PM
 *  Author: Mohamed Awadin
 */

#include "MDIO.h"

#define PTA_BASE 0x39
#define PTB_BASE 0x36
#define PTC_BASE 0x33
#define PTD_BASE 0x30

typedef struct
{
	volatile u8 PIN;
	volatile u8 DDR;
	volatile u8 DOR;

} MDIO_gst_PORT_t;




MDIO_gst_PORT_t *MDIO_gst_PORTA = (MDIO_gst_PORT_t *)PTA_BASE;
MDIO_gst_PORT_t *MDIO_gst_PORTB = (MDIO_gst_PORT_t *)PTB_BASE;
MDIO_gst_PORT_t *MDIO_gst_PORTC = (MDIO_gst_PORT_t *)PTC_BASE;
MDIO_gst_PORT_t *MDIO_gst_PORTD = (MDIO_gst_PORT_t *)PTD_BASE;

MDIO_enuErrorStatus_t MDIO_enuSetPinConfigration(Copy_enuPortNum_t Copy_enuPortNum, Copy_enuPinNum_t Copy_enuPinNum, Copy_enuPinConfigration_t Copy_enuPinConfigration)
{

	MDIO_enuErrorStatus_t Ret_enuError;

	if (Copy_enuPinNum > MDIO_PIN7)
	{
		Ret_enuError = MDIO_InvalidPin;
		return Ret_enuError;
	}

	switch (Copy_enuPinConfigration)
	{

	case MDIO_OUTPUT:

		switch (Copy_enuPortNum)
		{

		case MDIO_PORTA:
			SET_BIT(DDRA, Copy_enuPinNum);
			CLEAR_BIT(PORTA, Copy_enuPinNum);
			Ret_enuError = MDIO_OK;
			break;
		case MDIO_PORTB:
			SET_BIT(DDRB, Copy_enuPinNum);
			CLEAR_BIT(PORTB, Copy_enuPinNum);
			Ret_enuError = MDIO_OK;
			break;
		case MDIO_PORTC:
			SET_BIT(DDRC, Copy_enuPinNum);
			CLEAR_BIT(PORTC, Copy_enuPinNum);
			Ret_enuError = MDIO_OK;
			break;
		case MDIO_PORTD:
			SET_BIT(DDRD, Copy_enuPinNum);
			CLEAR_BIT(PORTD, Copy_enuPinNum);
			Ret_enuError = MDIO_OK;
			break;
		default:
			Ret_enuError = MDIO_InvalidPort;
			break;
		}
		break;

	case MDIO_INFREE:
		switch (Copy_enuPortNum)
		{
		case MDIO_PORTA:
			CLEAR_BIT(DDRA, Copy_enuPinNum);
			CLEAR_BIT(PORTA, Copy_enuPinNum);
			Ret_enuError = MDIO_OK;
			break;
		case MDIO_PORTB:
			CLEAR_BIT(DDRB, Copy_enuPinNum);
			CLEAR_BIT(PORTB, Copy_enuPinNum);
			Ret_enuError = MDIO_OK;
			break;
		case MDIO_PORTC:
			CLEAR_BIT(DDRC, Copy_enuPinNum);
			CLEAR_BIT(PORTC, Copy_enuPinNum);
			Ret_enuError = MDIO_OK;
			break;
		case MDIO_PORTD:
			CLEAR_BIT(DDRD, Copy_enuPinNum);
			CLEAR_BIT(PORTD, Copy_enuPinNum);
			Ret_enuError = MDIO_OK;
			break;
		default:
			Ret_enuError = MDIO_InvalidPort;
			break;
		}
		break;

	case MDIO_INPULLUP:
		switch (Copy_enuPortNum)
		{
		case MDIO_PORTA:
			CLEAR_BIT(DDRA, Copy_enuPinNum);
			SET_BIT(PORTA, Copy_enuPinNum);
			Ret_enuError = MDIO_OK;
			break;
		case MDIO_PORTB:
			CLEAR_BIT(DDRB, Copy_enuPinNum);
			SET_BIT(PORTB, Copy_enuPinNum);
			Ret_enuError = MDIO_OK;
			break;
		case MDIO_PORTC:
			CLEAR_BIT(DDRC, Copy_enuPinNum);
			SET_BIT(PORTC, Copy_enuPinNum);
			Ret_enuError = MDIO_OK;
			break;
		case MDIO_PORTD:
			CLEAR_BIT(DDRD, Copy_enuPinNum);
			SET_BIT(PORTD, Copy_enuPinNum);
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
MDIO_enuErrorStatus_t MDIO_enuSetPortConfigration(Copy_enuPortNum_t Copy_enuPortNum, Copy_enuPortConfigration_t Copy_enuPortConfigration)
{

	MDIO_enuErrorStatus_t Ret_enuError;

	switch (Copy_enuPortConfigration)
	{

	case MDIO_ALL_OUTPUT:
		switch (Copy_enuPortNum)
		{
		case MDIO_PORTA:
			DDRA = 0xff;
			PORTA = 0x0;
			Ret_enuError = MDIO_OK;
			break;

		case MDIO_PORTB:
			DDRB = 0xff;
			PORTB = 0x0;
			Ret_enuError = MDIO_OK;

			break;

		case MDIO_PORTC:
			DDRC = 0xff;
			PORTC = 0x0;
			Ret_enuError = MDIO_OK;

			break;
		case MDIO_PORTD:
			DDRD = 0xff;
			PORTD = 0x0;
			Ret_enuError = MDIO_OK;
			break;
		default:
			Ret_enuError = MDIO_InvalidPort;
			break;
		}

		break;

	case MDIO_ALL_INFREE:
		switch (Copy_enuPortNum)
		{
		case MDIO_PORTA:
			DDRA = 0x0;
			PORTA = 0x0;
			Ret_enuError = MDIO_OK;
			break;

		case MDIO_PORTB:
			DDRB = 0x0;
			PORTB = 0x0;
			Ret_enuError = MDIO_OK;
			break;

		case MDIO_PORTC:
			DDRC = 0x0;
			PORTC = 0x0;
			Ret_enuError = MDIO_OK;
			break;

		case MDIO_PORTD:
			DDRD = 0x0;
			PORTD = 0x0;
			Ret_enuError = MDIO_OK;
			break;

		default:
			Ret_enuError = MDIO_InvalidPort;
			break;
		}
		break;

	case MDIO_ALL_INPULLUP:
		switch (Copy_enuPortNum)
		{
		case MDIO_PORTA:
			DDRA = 0x0;
			PORTA = 0xFF;
			Ret_enuError = MDIO_OK;
			break;

		case MDIO_PORTB:
			DDRB = 0x0;
			PORTB = 0xFF;
			Ret_enuError = MDIO_OK;
			break;

		case MDIO_PORTC:
			DDRC = 0x0;
			PORTC = 0xFF;
			Ret_enuError = MDIO_OK;
			break;

		case MDIO_PORTD:
			DDRD = 0x0;
			PORTD = 0xFF;
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
MDIO_enuErrorStatus_t MDIO_enuSetPinValue(Copy_enuPortNum_t Copy_enuPortNum, Copy_enuPinNum_t Copy_enuPinNum, Copy_enuPinState_t Copy_enuPinState)
{
	MDIO_enuErrorStatus_t Ret_enuError;
	if ((Copy_enuPinNum >= MDIO_PIN0) && (Copy_enuPinNum <= MDIO_PIN7))
	{
		switch (Copy_enuPinState)
		{
		case MDIO_HIGH:
			switch (Copy_enuPortNum)
			{
			case MDIO_PORTA:
				SET_BIT(PORTA, Copy_enuPinNum);
				Ret_enuError = MDIO_OK;
				break;
			case MDIO_PORTB:
				SET_BIT(PORTB, Copy_enuPinNum);
				Ret_enuError = MDIO_OK;
				break;
			case MDIO_PORTC:
				SET_BIT(PORTC, Copy_enuPinNum);
				Ret_enuError = MDIO_OK;
				break;
			case MDIO_PORTD:
				SET_BIT(PORTD, Copy_enuPinNum);
				Ret_enuError = MDIO_OK;
				break;
			default:
				Ret_enuError = MDIO_InvalidPort;
				break;
			}
			break;
		case MDIO_LOW:
			switch (Copy_enuPortNum)
			{
			case MDIO_PORTA:
				CLEAR_BIT(PORTA, Copy_enuPinNum);
				Ret_enuError = MDIO_OK;
				break;
			case MDIO_PORTB:
				CLEAR_BIT(PORTB, Copy_enuPinNum);
				Ret_enuError = MDIO_OK;
				break;
			case MDIO_PORTC:
				CLEAR_BIT(PORTC, Copy_enuPinNum);
				Ret_enuError = MDIO_OK;
				break;
			case MDIO_PORTD:
				CLEAR_BIT(PORTD, Copy_enuPinNum);
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
	else
	{
		Ret_enuError = MDIO_InvalidPin;
	}
	return Ret_enuError;
}
MDIO_enuErrorStatus_t MDIO_enuSetPortValue(Copy_enuPortNum_t Copy_enuPortNum, Copy_enuPortState_t Copy_enuPortState)
{
	MDIO_enuErrorStatus_t Ret_enuError;

	switch (Copy_enuPortState)
	{
	case MDIO_ALL_LOW:
		switch (Copy_enuPortNum)
		{
		case MDIO_PORTA:
			PORTA = 0x0;
			Ret_enuError = MDIO_OK;
			break;

		case MDIO_PORTB:
			PORTB = 0x0;
			Ret_enuError = MDIO_OK;
			break;

		case MDIO_PORTC:
			PORTC = 0x0;
			Ret_enuError = MDIO_OK;
			break;

		case MDIO_PORTD:
			PORTD = 0x0;
			Ret_enuError = MDIO_OK;
			break;

		default:
			Ret_enuError = MDIO_InvalidPort;
			break;
		}
		break;

	case MDIO_ALL_HIGH:
		switch (Copy_enuPortNum)
		{
		case MDIO_PORTA:
			PORTA = 0xFF;
			Ret_enuError = MDIO_OK;
			break;

		case MDIO_PORTB:
			PORTB = 0xFF;
			Ret_enuError = MDIO_OK;

			break;

		case MDIO_PORTC:
			PORTC = 0xFF;
			Ret_enuError = MDIO_OK;
			break;

		case MDIO_PORTD:
			PORTD = 0xFF;
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
	return Ret_enuError;
}

MDIO_enuErrorStatus_t MDIO_enuGetPortValue(Copy_enuPortNum_t Copy_enuPortNum, u8 *add_pu8PortState)
{
	MDIO_enuErrorStatus_t Ret_enuError;

	switch (Copy_enuPortNum)
	{
	case MDIO_PORTA:
		*add_pu8PortState = PORTA;
		Ret_enuError = MDIO_OK;
		break;

	case MDIO_PORTB:
		*add_pu8PortState = PORTB;
		Ret_enuError = MDIO_OK;
		break;

	case MDIO_PORTC:
		*add_pu8PortState = PORTC;
		Ret_enuError = MDIO_OK;
		break;

	case MDIO_PORTD:
		*add_pu8PortState = PORTD;
		Ret_enuError = MDIO_OK;
		break;

	default:
		Ret_enuError = MDIO_InvalidPort;
		break;
	}
}

MDIO_enuErrorStatus_t MDIO_enuGetPinValue(Copy_enuPortNum_t Copy_enuPortNum, Copy_enuPinNum_t Copy_enuPinNum, u8 *Add_pu8PinValue)
{
	MDIO_enuErrorStatus_t Ret_enuError;
	if ((Copy_enuPinNum >= 0) && (Copy_enuPinNum < 8))
	{
		switch (Copy_enuPortNum)
		{

		case MDIO_PORTA:
			*Add_pu8PinValue = READ_BIT(PINA, Copy_enuPinNum);
			Ret_enuError = MDIO_OK;
			break;

		case MDIO_PORTB:
			*Add_pu8PinValue = READ_BIT(PINB, Copy_enuPinNum);
			Ret_enuError = MDIO_OK;
			break;

		case MDIO_PORTC:
			*Add_pu8PinValue = READ_BIT(PINC, Copy_enuPinNum);
			Ret_enuError = MDIO_OK;
			break;

		case MDIO_PORTD:
			*Add_pu8PinValue = READ_BIT(PIND, Copy_enuPinNum);
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

MDIO_enuErrorStatus_t MDIO_enuSetPortWValue(Copy_enuPortNum_t Copy_enuPortNum, u8 Copy_u8PortState)
{
	MDIO_enuErrorStatus_t Ret_enuError;

	switch (Copy_enuPortNum)
	{
	case MDIO_PORTA:
		PORTA = Copy_u8PortState;
		Ret_enuError = MDIO_OK;
		break;

	case MDIO_PORTB:
		PORTB = Copy_u8PortState;
		Ret_enuError = MDIO_OK;
		break;

	case MDIO_PORTC:
		PORTC = Copy_u8PortState;
		Ret_enuError = MDIO_OK;
		break;

	case MDIO_PORTD:
		PORTD = Copy_u8PortState;
		Ret_enuError = MDIO_OK;
		break;

	default:
		Ret_enuError = MDIO_InvalidPort;
		break;
	}
	return Ret_enuError;
}

MDIO_enuErrorStatus_t MDIO_enuInitPin(Copy_enuPinNum_t Copy_enuPinNum, Copy_enuPinConfigration_t Copy_enuPinConfigration)
{
	MDIO_enuErrorStatus_t Ret_enuError;
	Copy_enuPortNum_t port = Copy_enuPinNum / MDIO_NUM_OF_PINS;
	u8 pin_num = Copy_enuPinNum % MDIO_NUM_OF_PINS;

	if (Copy_enuPinNum > MDIO_PIN7)
	{
		Ret_enuError = MDIO_InvalidPin;
		return Ret_enuError;
	}

	switch (Copy_enuPinConfigration)
	{
	case MDIO_INFREE:
		switch (port)
		{
		case MDIO_PORTA:
			CLEAR_BIT(DDRA, pin_num);
			Ret_enuError = MDIO_OK;
			break;
		case MDIO_PORTB:
			CLEAR_BIT(DDRB, pin_num);
			Ret_enuError = MDIO_OK;
			break;
		case MDIO_PORTC:
			CLEAR_BIT(DDRC, pin_num);
			Ret_enuError = MDIO_OK;
			break;
		case MDIO_PORTD:
			CLEAR_BIT(DDRD, pin_num);
			Ret_enuError = MDIO_OK;
			break;
		default:
			Ret_enuError = MDIO_InvalidPort;
			break;
		}
		break;
	case MDIO_INPULLUP:
		switch (port)
		{
		case MDIO_PORTA:
			CLEAR_BIT(DDRA, pin_num);
			SET_BIT(PORTA, pin_num);
			Ret_enuError = MDIO_OK;
			break;
		case MDIO_PORTB:
			CLEAR_BIT(DDRB, pin_num);
			SET_BIT(PORTB, pin_num);
			Ret_enuError = MDIO_OK;
			break;
		case MDIO_PORTC:
			CLEAR_BIT(DDRC, pin_num);
			SET_BIT(PORTC, pin_num);
			Ret_enuError = MDIO_OK;
			break;
		case MDIO_PORTD:
			CLEAR_BIT(DDRD, pin_num);
			SET_BIT(PORTD, pin_num);
			Ret_enuError = MDIO_OK;
			break;
		default:
			Ret_enuError = MDIO_InvalidPort;
			break;
		}
		break;
	case MDIO_OUTPUT:
		switch (port)
		{
		case MDIO_PORTA:
			SET_BIT(DDRA, pin_num);
			Ret_enuError = MDIO_OK;
			break;
		case MDIO_PORTB:
			SET_BIT(DDRB, pin_num);
			Ret_enuError = MDIO_OK;
			break;
		case MDIO_PORTC:
			SET_BIT(DDRC, pin_num);
			Ret_enuError = MDIO_OK;
			break;
		case MDIO_PORTD:
			SET_BIT(DDRD, pin_num);
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
	return Ret_enuError;
}

void MDIO_vInit(void)
{
	MDIO_enuErrorStatus_t Ret_enuError;
	Copy_enuPinNum_t Local_uint8Iter;
	for (Local_uint8Iter = MDIO_PIN0; Local_uint8Iter < (MDIO_NUM_OF_PORTS * MDIO_NUM_OF_PINS); Local_uint8Iter++)
	{
		Ret_enuError = MDIO_enuInitPin(Local_uint8Iter, PinsStatusArray[Local_uint8Iter]);
		if ((Ret_enuError == MDIO_InvalidPort) || (Ret_enuError == MDIO_InvalidState))
		{
			break;
		}
	}
}
/*
void MDIO_vSetPin(Copy_enuPortNum_t Copy_u8PortNum, Copy_enuPinNum_t Copy_u8PinNum, Copy_enuPinState_t Copy_u8Value)
{

	if (Copy_u8PinNum > MDIO_PIN7)
	{
		return; // Invalid pin, exit
	}

	MDIO_gst_PORT_t *port;

	switch (Copy_u8PortNum)
	{
	case MDIO_PORTA:
		port = MDIO_gst_PORTA;
		break;
	case MDIO_PORTB:
		port = MDIO_gst_PORTB;
		break;
	case MDIO_PORTC:
		port = MDIO_gst_PORTC;
		break;
	case MDIO_PORTD:
		port = MDIO_gst_PORTD;
		break;
	default:
		return; // Invalid port, exit
	}

	if (Copy_u8Value == MDIO_HIGH)
	{
		port->DOR |= (1 << Copy_u8PinNum);
	}
	else if (Copy_u8Value == MDIO_LOW)
	{
		port->DOR &= ~(1 << Copy_u8PinNum);
	}
}
*/