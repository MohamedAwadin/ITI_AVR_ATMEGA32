
#ifndef MPORT_LCFG_H
#define MPORT_LCFG_H

#include "MPORT.h"

typedef struct 
{
    MPORT_enuPortPinDir_t Direction;
    MPORT_enuPortPinMode_t Mode;
} MPORT_structPortPinDirAndMode_t;

#define MPORT_NUM_OF_ALL_PINS   32

#endif

