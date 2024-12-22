#include "MDIO.h"

//>>>>>>>>>>>>>>>>>>>>>>Task1<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int main(void)
{
    MDIO_enuSetPinConfigration(MDIO_PORTA,MDIO_PIN0,MDIO_OUTPUT);
	MDIO_enuSetPinConfigration(MDIO_PORTB,MDIO_PIN0,MDIO_OUTPUT);
	MDIO_enuSetPinConfigration(MDIO_PORTC,MDIO_PIN0,MDIO_OUTPUT);
	MDIO_enuSetPinConfigration(MDIO_PORTD,MDIO_PIN0,MDIO_OUTPUT);
	
	MDIO_enuSetPinConfigration(MDIO_PORTA,MDIO_PIN1,MDIO_INPULLUP);
	MDIO_enuSetPinConfigration(MDIO_PORTB,MDIO_PIN1,MDIO_INPULLUP);
	MDIO_enuSetPinConfigration(MDIO_PORTC,MDIO_PIN1,MDIO_INPULLUP);
	MDIO_enuSetPinConfigration(MDIO_PORTD,MDIO_PIN1,MDIO_INPULLUP);
	
	int ST_PB1 =0,ST_PB2 =0,ST_PB3 =0,ST_PB4 =0;
    while (1) 
    {
		MDIO_enuGetPinValue(MDIO_PORTA, MDIO_PIN1,&ST_PB1);
		MDIO_enuGetPinValue(MDIO_PORTB, MDIO_PIN1,&ST_PB2);
		MDIO_enuGetPinValue(MDIO_PORTC, MDIO_PIN1,&ST_PB3);
		MDIO_enuGetPinValue(MDIO_PORTD, MDIO_PIN1,&ST_PB4);
		
		if(ST_PB1 == 0){
			MDIO_enuSetPinValue(MDIO_PORTA , MDIO_PIN0 , MDIO_HIGH);
		}
		else
		{
			MDIO_enuSetPinValue(MDIO_PORTA , MDIO_PIN0 , MDIO_LOW);
		}
		if(ST_PB2 == 0){
			MDIO_enuSetPinValue(MDIO_PORTB , MDIO_PIN0 , MDIO_HIGH);
		}
		else
		{
			MDIO_enuSetPinValue(MDIO_PORTB , MDIO_PIN0 , MDIO_LOW);
		}
		if(ST_PB3 == 0){
			MDIO_enuSetPinValue(MDIO_PORTC , MDIO_PIN0 , MDIO_HIGH);
		}
		else
		{
			MDIO_enuSetPinValue(MDIO_PORTC , MDIO_PIN0 , MDIO_LOW);
		}
		if(ST_PB4 == 0){
			MDIO_enuSetPinValue(MDIO_PORTD , MDIO_PIN0 , MDIO_HIGH);
		}
		else
		{
			MDIO_enuSetPinValue(MDIO_PORTD , MDIO_PIN0 , MDIO_LOW);
		}
    }
	return 0;
}
