#ifndef HLCD_PRIVATE_H_
#define HLCD_PRIVATE_H_

#define _8Bit 1
#define _4Bit 2 

#define HLCD_CLEAR_MODE_INS 0x01
#define HLCD_FUNC_SET__4Bit 0x02
#define HLCD_CGRAM_ST_CC    0x40




#define HLCD_LINE1_ADDRESS          0x80  
#define HLCD_LINE2_ADDRESS          0xC0  



/* Timing Delays (in milliseconds) */
#define HLCD_POWER_UP_DELAY         50    
#define HLCD_COMMAND_DELAY          1     
#define HLCD_CLEAR_DELAY            2     





#endif