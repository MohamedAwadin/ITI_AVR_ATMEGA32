#include "MEXTINT.h"

/************************************************************************/
/* Pointers to functions to be assigned to ISRs                         */
/************************************************************************/

static void (*INT0_Fptr)(void) = NULL_PTR;  // Callback function for INT0
static void (*INT1_Fptr)(void) = NULL_PTR;  // Callback function for INT1
static void (*INT2_Fptr)(void) = NULL_PTR;  // Callback function for INT2

/**
 * @brief Macro to check if the external interrupt source is valid.
 */
#define IS_EXTINT_SOURCE_VALID(_EXTINT_SOURCE_) (((_EXTINT_SOURCE_) >= MEXTINT_EXTI0_SOURCE) && ((_EXTINT_SOURCE_) <= MEXTINT_EXTI2_SOURCE))

/**
 * @brief Initializes the external interrupts based on the configuration macros.
 */
void MEXTINT_vInit(void) {
    u8 Local_u8TempReg = 0;

    // Configure INT0
#if (MEXTINT_EXTI0_SOURCE_STATE == MEXTINT_SOURCE_ENABLE)
    #if !((MEXTINT_EXTI0_SOURCE_CONFIG == MEXTINT_INT0_LOW_LEVEL) || \
          (MEXTINT_EXTI0_SOURCE_CONFIG == MEXTINT_INT0_LOGICAL_CHANGE) || \
          (MEXTINT_EXTI0_SOURCE_CONFIG == MEXTINT_INT0_FALLING_EDGE) || \
          (MEXTINT_EXTI0_SOURCE_CONFIG == MEXTINT_INT0_RISING_EDGE))
        #error "ERROR :: MCAL LAYER - MEXTINT :: Enable External Interrupt 0, and use Invalid Edge Configuration (MEXTINT_EXTI0_SOURCE_CONFIG)"
    #else
        SET_BIT(SREG, GIE);  // Enable global interrupts
        SET_BIT(GICR, INT0); // Enable INT0

        // Configure INT0 trigger mode
        Local_u8TempReg = MCUCR;
        Local_u8TempReg &= MEXTINT_INT0_CLRMASK;
        Local_u8TempReg |= MEXTINT_EXTI0_SOURCE_CONFIG;
        MCUCR = Local_u8TempReg;
    #endif
#elif (MEXTINT_EXTI0_SOURCE_STATE == MEXTINT_SOURCE_DISABLE)
    CLEAR_BIT(GICR, INT0);  // Disable INT0
#else
    #error "ERROR :: MCAL LAYER - MEXTINT :: External Interrupt 0 Invalid State Configuration (MEXTINT_EXTI0_SOURCE_STATE)"
#endif

    // Configure INT1
#if (MEXTINT_EXTI1_SOURCE_STATE == MEXTINT_SOURCE_ENABLE)
    #if !((MEXTINT_EXTI1_SOURCE_CONFIG == MEXTINT_INT1_LOW_LEVEL) || \
          (MEXTINT_EXTI1_SOURCE_CONFIG == MEXTINT_INT1_LOGICAL_CHANGE) || \
          (MEXTINT_EXTI1_SOURCE_CONFIG == MEXTINT_INT1_FALLING_EDGE) || \
          (MEXTINT_EXTI1_SOURCE_CONFIG == MEXTINT_INT1_RISING_EDGE))
        #error "ERROR :: MCAL LAYER - MEXTINT :: Enable External Interrupt 1, and use Invalid Configuration (MEXTINT_EXTI1_SOURCE_CONFIG)"
    #else
        SET_BIT(SREG, GIE);  // Enable global interrupts
        SET_BIT(GICR, INT1); // Enable INT1

        // Configure INT1 trigger mode
        Local_u8TempReg = MCUCR;
        Local_u8TempReg &= MEXTINT_INT1_CLRMASK;
        Local_u8TempReg |= (MEXTINT_EXTI1_SOURCE_CONFIG << ISC10);
        MCUCR = Local_u8TempReg;
    #endif
#elif (MEXTINT_EXTI1_SOURCE_STATE == MEXTINT_SOURCE_DISABLE)
    CLEAR_BIT(GICR, INT1);  // Disable INT1
#else
    #error "ERROR :: MCAL LAYER - MEXTINT :: External Interrupt 1 Invalid State Configuration (MEXTINT_EXTI1_SOURCE_STATE)"
#endif

    // Configure INT2
#if (MEXTINT_EXTI2_SOURCE_STATE == MEXTINT_SOURCE_ENABLE)
    #if !((MEXTINT_EXTI2_SOURCE_CONFIG == MEXTINT_INT2_FALLING_EDGE) || \
          (MEXTINT_EXTI2_SOURCE_CONFIG == MEXTINT_INT2_RISING_EDGE))
        #error "ERROR :: MCAL LAYER - MEXTINT :: Enable External Interrupt 2, and use Invalid Configuration (MEXTINT_EXTI2_SOURCE_CONFIG)"
    #else
        SET_BIT(SREG, GIE);  // Enable global interrupts
        SET_BIT(GICR, INT2); // Enable INT2

        // Configure INT2 trigger mode
        Local_u8TempReg = MCUCSR;
        Local_u8TempReg &= MEXTINT_INT2_CLRMASK;
        Local_u8TempReg |= (MEXTINT_EXTI2_SOURCE_CONFIG << ISC2);
        MCUCSR = Local_u8TempReg;
    #endif
#elif (MEXTINT_EXTI2_SOURCE_STATE == MEXTINT_SOURCE_DISABLE)
    CLEAR_BIT(GICR, INT2);  // Disable INT2
#else
    #error "ERROR :: MCAL LAYER - MEXTINT :: External Interrupt 2 Invalid State Configuration (MEXTINT_EXTI2_SOURCE_STATE)"
#endif
}

/**
 * @brief Sets the callback function for a specific external interrupt.
 * @param Copy_u8EXTINT_Source: External interrupt source (MEXTINT_EXTI0_SOURCE, MEXTINT_EXTI1_SOURCE, MEXTINT_EXTI2_SOURCE).
 * @param Local_Fptr: Pointer to the callback function.
 * @return MEXTINT_enumErrorStatus_t: Error status.
 */
MEXTINT_enumErrorStatus_t MEXTINT_enumSetCallBack(u8 Copy_u8EXTINT_Source, void (*Local_Fptr)(void)) {
    MEXTINT_enumErrorStatus_t Local_enuErrorStatus = MEXTINT_enumOK;

    // Check if the external interrupt source is valid
    if (!IS_EXTINT_SOURCE_VALID(Copy_u8EXTINT_Source)) {
        Local_enuErrorStatus = MEXTINT_enumInvalidEXTISOURCE;
    }
    // Check if the callback function pointer is valid
    else if (Local_Fptr == NULL_PTR) {
        Local_enuErrorStatus = MEXTINT_enumNullPtr;
    }
    // Assign the callback function to the appropriate interrupt
    else {
        switch (Copy_u8EXTINT_Source) {
            case MEXTINT_EXTI0_SOURCE:
                INT0_Fptr = Local_Fptr;
                break;
            case MEXTINT_EXTI1_SOURCE:
                INT1_Fptr = Local_Fptr;
                break;
            case MEXTINT_EXTI2_SOURCE:
                INT2_Fptr = Local_Fptr;
                break;
            default:
                // No action needed
                break;
        }
    }

    return Local_enuErrorStatus;
}

/**
 * @brief Enables global interrupts.
 */
void MEXTINT_vGLOBALENABLE(void) {
    sei();  // Enable global interrupts
}

/**
 * @brief Disables global interrupts.
 */
void MEXTINT_vGLOBALDISABLE(void) {
    cli();  // Disable global interrupts
}

/************************************************************************/
/* ISR Functions                                                        */
/************************************************************************/

/**
 * @brief ISR for external interrupt 0.
 */
ISR(INT0_vect) {
    if (INT0_Fptr != NULL_PTR) {
        INT0_Fptr();  // Call the assigned callback function
    }
}

/**
 * @brief ISR for external interrupt 1.
 */
ISR(INT1_vect) {
    if (INT1_Fptr != NULL_PTR) {
        INT1_Fptr();  // Call the assigned callback function
    }
}

/**
 * @brief ISR for external interrupt 2.
 */
ISR(INT2_vect) {
    if (INT2_Fptr != NULL_PTR) {
        INT2_Fptr();  // Call the assigned callback function
    }
}