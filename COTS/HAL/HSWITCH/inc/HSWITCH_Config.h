#ifndef HSWITCH_CONFIG_H
#define HSWITCH_CONFIG_H

#include "HSWITCH.h"

/* Number of Switches in the System */
#define NUM_OF_SWITCHES 3

/* Switch Names (Indices for the configuration array) */
#define SWITCH_0   0  // Switch 0
#define SWITCH_1   1  // Switch 1
#define SWITCH_2   2  // Switch 2

/* Switch Configuration Array (Defined in HSWITCH_Config.c) */
extern const HSWITCH_strConfig_t HSWITCH_strConfigArray[NUM_OF_SWITCHES];

#endif /* HSWITCH_CONFIG_H */