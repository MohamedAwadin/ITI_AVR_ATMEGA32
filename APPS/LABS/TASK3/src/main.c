#include "MDIO.h"

int main(void)
{
	MDIO_enuSetPortConfigration(MDIO_PORTA,MDIO_ALL_OUTPUT);
	//MDIO_enuSetPortValue(MDIO_PORTA , MDIO_ALL_HIGH);
	MDIO_enuSetPortConfigration(MDIO_PORTB,MDIO_ALL_INPULLUP);
	int counter = 0;
	int ST_PB1 =0;
	while (1)
	{
		MDIO_enuGetPinValue(MDIO_PORTB, MDIO_PIN0,&ST_PB1);
		if(ST_PB1 == 0){
			MDIO_enuSetPortWValue(MDIO_PORTA,counter);
			if(counter == 255){
				counter = -1 ;
			}
			counter ++ ;
			while(ST_PB1 == 0){
				MDIO_enuGetPinValue(MDIO_PORTB, MDIO_PIN0,&ST_PB1);	
			}
		}
		
		
	}
	return 0;
}