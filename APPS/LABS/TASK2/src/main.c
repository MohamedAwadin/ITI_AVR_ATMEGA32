#include "MDIO.h"
#define F_CPU	8000000UL
#include <util/delay.h>

int main(){
	
	
	MDIO_enuSetPortConfigration(MDIO_PORTA,MDIO_ALL_OUTPUT);
	//MDIO_enuSetPortValue(MDIO_PORTA , MDIO_ALL_HIGH);
	MDIO_enuSetPortConfigration(MDIO_PORTB,MDIO_ALL_INPULLUP);
	
	
	int ST_PB1 =0;
	while (1)
	{
		
		
		
		MDIO_enuGetPinValue(MDIO_PORTB, MDIO_PIN0,&ST_PB1);
		
		
		if(ST_PB1 == 0){
			MDIO_enuSetPortValue(MDIO_PORTA , MDIO_ALL_HIGH);
		}
		else
		{
			MDIO_enuSetPortValue(MDIO_PORTA ,MDIO_ALL_LOW);
		}
		
	}
	return 0;
	
	
	
}

