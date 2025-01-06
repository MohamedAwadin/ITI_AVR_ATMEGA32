

#include "MDIO.h"
#include "MPORT.h"


int main(void)
{
	// MPORT_enuSetPinDirection(MPORT_PIN_A1 , MPORT_PORT_PIN_OUTPUT);
	// MPORT_enuSetPinDirection(MPORT_PIN_C3 , MPORT_PORT_PIN_INPUT);
	// MPORT_enuSetPinMode(MPORT_PIN_C3 , MPORT_PIN_MODE_INPUT_PULLUP);
	MPort_vInit();
	
	
	u8 ST_PB1 =0;
	while (1)
	{

		MDIO_enuGetPinValue(GET_HIGH_NIB(MPORT_PIN_C3),GET_LOW_NIB(MPORT_PIN_C3),&ST_PB1);
		if(ST_PB1 == 0){
			
			MDIO_enuSetPinValue(GET_HIGH_NIB(MPORT_PIN_A1),GET_LOW_NIB(MPORT_PIN_A1), MDIO_LOW);
		}
		else
		{
			
			MDIO_enuSetPinValue(GET_HIGH_NIB(MPORT_PIN_A1),GET_LOW_NIB(MPORT_PIN_A1), MDIO_HIGH);
		}
		
	}
	return 0;

	
    
}