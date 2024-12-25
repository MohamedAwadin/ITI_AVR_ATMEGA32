#include "MDIO.h"

//>>>>>>>>>>>>>>>>>>>>>>Task4<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int main(void)
{
    MDIO_vInit();
    MDIO_enuSetPinValue(MDIO_PORTA , MDIO_PIN0 , MDIO_HIGH);
	u8 ST_PB1 =0,ST_PB2 =0,ST_PB3 =0;
    while (1) 
    {
		MDIO_enuGetPinValue(MDIO_PORTB, MDIO_PIN0,&ST_PB1);
		MDIO_enuGetPinValue(MDIO_PORTB, MDIO_PIN1,&ST_PB2);
		MDIO_enuGetPinValue(MDIO_PORTB, MDIO_PIN2,&ST_PB3);
		
		
		if(ST_PB1 == 0){
			MDIO_enuSetPinValue(MDIO_PORTA , MDIO_PIN0 , MDIO_HIGH);
		}
		else
		{
			MDIO_enuSetPinValue(MDIO_PORTA , MDIO_PIN0 , MDIO_LOW);
		}
		if(ST_PB2 == 0){
			MDIO_enuSetPinValue(MDIO_PORTA , MDIO_PIN1 , MDIO_HIGH);
		}
		else
		{
			MDIO_enuSetPinValue(MDIO_PORTA , MDIO_PIN1 , MDIO_LOW);
		}
		if(ST_PB3 == 0){
			MDIO_enuSetPinValue(MDIO_PORTA , MDIO_PIN2 , MDIO_HIGH);
		}
		else
		{
			MDIO_enuSetPinValue(MDIO_PORTA , MDIO_PIN2 , MDIO_LOW);
		}
		
    }
	return 0;
}
