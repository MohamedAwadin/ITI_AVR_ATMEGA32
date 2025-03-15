#include "MEXTINT.h"

static void (*INT0_Fptr)(void) = NULL_PTR;
static void (*INT1_Fptr)(void) = NULL_PTR;
static void (*INT2_Fptr)(void) = NULL_PTR;

#define IS_EXTINT_SOURCE_VALID(_EXTINT_SOURCE_) (((_EXTINT_SOURCE_) >= MEXTINT_EXTI0_SOURCE) && ((_EXTINT_SOURCE_) <= MEXTINT_EXTI2_SOURCE))

void MEXTINT_vInit(void) {
    u8 Local_u8TempReg = 0;

    cli(); // Ensure atomic configuration

    // Configure INT0
#if (MEXTINT_EXTI0_SOURCE_STATE == MEXTINT_SOURCE_ENABLE)
    #if !((MEXTINT_EXTI0_SOURCE_CONFIG == MEXTINT_INT0_LOW_LEVEL) || \
          (MEXTINT_EXTI0_SOURCE_CONFIG == MEXTINT_INT0_LOGICAL_CHANGE) || \
          (MEXTINT_EXTI0_SOURCE_CONFIG == MEXTINT_INT0_FALLING_EDGE) || \
          (MEXTINT_EXTI0_SOURCE_CONFIG == MEXTINT_INT0_RISING_EDGE))
        #error "ERROR :: MCAL LAYER - MEXTINT :: Invalid INT0 Config"
    #else
        SET_BIT(GICR, INT0);
        Local_u8TempReg = MCUCR;
        Local_u8TempReg &= MEXTINT_INT0_CLRMASK;
        Local_u8TempReg |= MEXTINT_EXTI0_SOURCE_CONFIG;
        MCUCR = Local_u8TempReg;
    #endif
#else
    CLEAR_BIT(GICR, INT0);
#endif

    // Configure INT1
#if (MEXTINT_EXTI1_SOURCE_STATE == MEXTINT_SOURCE_ENABLE)
    #if !((MEXTINT_EXTI1_SOURCE_CONFIG == MEXTINT_INT1_LOW_LEVEL) || \
          (MEXTINT_EXTI1_SOURCE_CONFIG == MEXTINT_INT1_LOGICAL_CHANGE) || \
          (MEXTINT_EXTI1_SOURCE_CONFIG == MEXTINT_INT1_FALLING_EDGE) || \
          (MEXTINT_EXTI1_SOURCE_CONFIG == MEXTINT_INT1_RISING_EDGE))
        #error "ERROR :: MCAL LAYER - MEXTINT :: Invalid INT1 Config"
    #else
        SET_BIT(GICR, INT1);
        Local_u8TempReg = MCUCR;
        Local_u8TempReg &= MEXTINT_INT1_CLRMASK;
        Local_u8TempReg |= (MEXTINT_EXTI1_SOURCE_CONFIG << ISC10);
        MCUCR = Local_u8TempReg;
    #endif
#else
    CLEAR_BIT(GICR, INT1);
#endif

    // Configure INT2
#if (MEXTINT_EXTI2_SOURCE_STATE == MEXTINT_SOURCE_ENABLE)
    #if !((MEXTINT_EXTI2_SOURCE_CONFIG == MEXTINT_INT2_FALLING_EDGE) || \
          (MEXTINT_EXTI2_SOURCE_CONFIG == MEXTINT_INT2_RISING_EDGE))
        #error "ERROR :: MCAL LAYER - MEXTINT :: Invalid INT2 Config"
    #else
        SET_BIT(GICR, INT2);
        Local_u8TempReg = MCUCSR;
        Local_u8TempReg &= MEXTINT_INT2_CLRMASK;
        Local_u8TempReg |= (MEXTINT_EXTI2_SOURCE_CONFIG << ISC2);
        MCUCSR = Local_u8TempReg;
    #endif
#else
    CLEAR_BIT(GICR, INT2);
#endif

    sei(); // Enable global interrupts once after all configs
}

MEXTINT_enumErrorStatus_t MEXTINT_enumSetCallBack(u8 Copy_u8EXTINT_Source, void (*Local_Fptr)(void)) {
    MEXTINT_enumErrorStatus_t Local_enuErrorStatus = MEXTINT_enumOK;

    if (!IS_EXTINT_SOURCE_VALID(Copy_u8EXTINT_Source)) {
        Local_enuErrorStatus = MEXTINT_enumInvalidEXTISOURCE;
    }
    else if (Local_Fptr == NULL_PTR) {
        Local_enuErrorStatus = MEXTINT_enumNullPtr;
    }
    else {
        switch (Copy_u8EXTINT_Source) {
            case MEXTINT_EXTI0_SOURCE: INT0_Fptr = Local_Fptr; break;
            case MEXTINT_EXTI1_SOURCE: INT1_Fptr = Local_Fptr; break;
            case MEXTINT_EXTI2_SOURCE: INT2_Fptr = Local_Fptr; break;
        }
    }

    return Local_enuErrorStatus;
}

void MEXTINT_vGLOBALENABLE(void) {
    sei();
}

void MEXTINT_vGLOBALDISABLE(void) {
    cli();
}

ISR(INT0_vect) {
    if (INT0_Fptr != NULL_PTR) {
        INT0_Fptr();
    }
}

ISR(INT1_vect) {
    if (INT1_Fptr != NULL_PTR) {
        INT1_Fptr();
    }
}

ISR(INT2_vect) {
    if (INT2_Fptr != NULL_PTR) {
        INT2_Fptr();
    }
}