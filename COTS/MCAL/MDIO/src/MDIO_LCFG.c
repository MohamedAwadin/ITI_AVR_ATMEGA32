


#include "MDIO.h"
#include "MDIO_PBCFG.h"
#include "MDIO_LCFG.h"


	
const Copy_enuPinConfigration_t PinsStatusArray[MDIO_NUM_OF_PINS * MDIO_NUM_OF_PORTS]={
	
	MDIO_OUTPUT,      /* Port A Pin 0 */
	MDIO_OUTPUT,      /* Port A Pin 1 */
	MDIO_OUTPUT,      /* Port A Pin 2 */
	MDIO_OUTPUT,      /* Port A Pin 3 */
	MDIO_OUTPUT,      /* Port A Pin 4 */
	MDIO_OUTPUT,      /* Port A Pin 5 */
	MDIO_OUTPUT,        /* Port A Pin 6 */
	MDIO_OUTPUT,        /* Port A Pin 7 */
	MDIO_INPULLUP,      /* Port B Pin 0   / */
	MDIO_INPULLUP,      /* Port B Pin 1   /*/
	MDIO_INPULLUP,		 /* Port B Pin 2 / INT2*/
	MDIO_INPULLUP,		 /* Port B Pin 3   /OC0*/
	MDIO_OUTPUT,		 /* Port B Pin 4 */
	MDIO_OUTPUT,		 /* Port B Pin 5 */
	MDIO_OUTPUT,		 /* Port B Pin 6 */
	MDIO_OUTPUT,		 /* Port B Pin 7 */
	MDIO_OUTPUT,		 /* Port C Pin 0 */
	MDIO_OUTPUT,		 /* Port C Pin 1 */
	MDIO_OUTPUT,		 /* Port C Pin 2 */
	MDIO_OUTPUT,		 /* Port C Pin 3 */
	MDIO_OUTPUT,		 /* Port C Pin 4 */
	MDIO_OUTPUT,		 /* Port C Pin 5 */
	MDIO_OUTPUT,		 /* Port C Pin 6 */
	MDIO_OUTPUT,		 /* Port C Pin 7 */
	MDIO_OUTPUT,		 /* Port D Pin 0 */
	MDIO_OUTPUT,		 /* Port D Pin 1 */
    MDIO_INPULLUP,      /* Port D Pin 2 */
	MDIO_OUTPUT,      /* Port D Pin 3 / INT1 */
	MDIO_INPULLUP,		 /* Port D Pin 4 */
	MDIO_OUTPUT,		 /* Port D Pin 5 */
	MDIO_INFREE,		 /* Port D Pin 6 /   ICP*/
	MDIO_OUTPUT		 /* Port D Pin 7 */
};	