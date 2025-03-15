#include "MTIMER.h"


/**************************** Private Variables *********************************/
static volatile void (*Timer0_OverflowCallback)(void) = NULL_PTR; /**< Timer0 Overflow ISR callback */
static volatile void (*Timer0_CompareCallback)(void) = NULL_PTR;  /**< Timer0 Compare match ISR callback */
static volatile void (*Timer2_OverflowCallback)(void) = NULL_PTR; /**< Timer2 Overflow ISR callback */
static volatile void (*Timer2_CompareCallback)(void) = NULL_PTR;  /**< Timer2 Compare match ISR callback */

/**************************** Validation Macros *********************************/
#define IS_VALID_MODE(Mode) \
    ((Mode) == TIMER_MODE_NORMAL || (Mode) == TIMER_MODE_PHASECORRECT || \
     (Mode) == TIMER_MODE_CTC || (Mode) == TIMER_MODE_FASTPWM)

#define IS_VALID_OC_MODE(OCMode) \
    ((OCMode) == TIMER_OC_DISCONNECTED || (OCMode) == TIMER_OC_TOGGLE || \
     (OCMode) == TIMER_OC_NON_INVERTING || (OCMode) == TIMER_OC_INVERTING)

#define IS_VALID_TIMER_0_PRESCALER(Prescaler) \
    ((Prescaler) <= TIMER_0_PRESCALER_EXT_RISING)

#define IS_VALID_TIMER_2_PRESCALER(Prescaler) \
    ((Prescaler) <= TIMER_2_PRESCALER_1024)

/**************************** Timer0 Implementations ****************************/

TIMER_enumErrorType TIMER_0_enumInit(const TIMER_strConfigType* ConfigPtr) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

    if (ConfigPtr == NULL_PTR) {
        Local_ErrorStatus = TIMER_NULL_PTR;
    }
    else if (!IS_VALID_MODE(ConfigPtr->Mode)) {
        Local_ErrorStatus = TIMER_INVALID_MODE;
    }
    else if (!IS_VALID_OC_MODE(ConfigPtr->OCMode)) {
        Local_ErrorStatus = TIMER_INVALID_OC_MODE;
    }
    else if (!IS_VALID_TIMER_0_PRESCALER(ConfigPtr->Prescaler.Timer0Prescaler)) {
        Local_ErrorStatus = TIMER_INVALID_PRESCALER;
    }
    else {
        u8 Local_u8TempReg = 0;
         
        Local_u8TempReg |= ConfigPtr->Mode;
        Local_u8TempReg |= ConfigPtr->OCMode;
        Local_u8TempReg |= ConfigPtr->Prescaler.Timer0Prescaler;
        TCCR0 = Local_u8TempReg;
        TCNT0 = ConfigPtr->InitialValue;
        OCR0 = ConfigPtr->CompareValue;
         
    }

    return Local_ErrorStatus;
}

TIMER_enumErrorType TIMER_0_enumStart(TIMER_0_enumPrescalerType Prescaler) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

    if (!IS_VALID_TIMER_0_PRESCALER(Prescaler)) {
        Local_ErrorStatus = TIMER_INVALID_PRESCALER;
    }
    else {
         
        TCCR0 &= TIMER_0_SCALER_CLR_BITS;
        TCCR0 |= Prescaler;
         
    }

    return Local_ErrorStatus;
}

TIMER_enumErrorType TIMER_0_enumStop(void) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

     
    TCCR0 &= TIMER_0_SCALER_CLR_BITS;
     

    return Local_ErrorStatus;
}

TIMER_enumErrorType TIMER_0_enumSetCounter(u8 Value) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

    TCNT0 = Value;

    return Local_ErrorStatus;
}

TIMER_enumErrorType TIMER_0_enumSetCompare(u8 Value) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

    OCR0 = Value;

    return Local_ErrorStatus;
}

TIMER_enumErrorType TIMER_0_enumGetTimeElapsed(u16* ValuePtr) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

    if (ValuePtr == NULL_PTR) {
        Local_ErrorStatus = TIMER_NULL_PTR;
    }
    else {
        *ValuePtr = (u16)TCNT0;
    }

    return Local_ErrorStatus;
}

TIMER_enumErrorType TIMER_0_enumGetTimeRemaining(u16* ValuePtr) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

    if (ValuePtr == NULL_PTR) {
        Local_ErrorStatus = TIMER_NULL_PTR;
    }
    else if ((TCCR0 & TIMER_MODE_CTC) != TIMER_MODE_CTC) {
        Local_ErrorStatus = TIMER_INVALID_MODE;
    }
    else {
        *ValuePtr = (u16)(OCR0 - TCNT0);
    }

    return Local_ErrorStatus;
}

TIMER_enumErrorType TIMER_0_enumOverflowInterruptEnable(void) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

    SET_BIT(TIMSK, TOIE0);

    return Local_ErrorStatus;
}

TIMER_enumErrorType TIMER_0_enumOverflowInterruptDisable(void) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

    CLEAR_BIT(TIMSK, TOIE0);

    return Local_ErrorStatus;
}

TIMER_enumErrorType TIMER_0_enumCompareInterruptEnable(void) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

    SET_BIT(TIMSK, OCIE0);

    return Local_ErrorStatus;
}

TIMER_enumErrorType TIMER_0_enumCompareInterruptDisable(void) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

    CLEAR_BIT(TIMSK, OCIE0);

    return Local_ErrorStatus;
}

TIMER_enumErrorType TIMER_0_enumSetOverflowCallback(void (*CallbackPtr)(void)) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

    if (CallbackPtr == NULL_PTR) {
        Local_ErrorStatus = TIMER_NULL_PTR;
    }
    else {
         
        Timer0_OverflowCallback = CallbackPtr;
         
    }

    return Local_ErrorStatus;
}

TIMER_enumErrorType TIMER_0_enumSetCompareCallback(void (*CallbackPtr)(void)) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

    if (CallbackPtr == NULL_PTR) {
        Local_ErrorStatus = TIMER_NULL_PTR;
    }
    else {
         
        Timer0_CompareCallback = CallbackPtr;
         
    }

    return Local_ErrorStatus;
}

TIMER_enumErrorType TIMER_0_enumIsRunning(u8* StatusPtr) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

    if (StatusPtr == NULL_PTR) {
        Local_ErrorStatus = TIMER_NULL_PTR;
    }
    else {
        *StatusPtr = (TCCR0 & (CS02 | CS01 | CS00)) ? 1 : 0;
    }

    return Local_ErrorStatus;
}

/**************************** Timer2 Implementations ****************************/

TIMER_enumErrorType TIMER_2_enumInit(const TIMER_strConfigType* ConfigPtr) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

    if (ConfigPtr == NULL_PTR) {
        Local_ErrorStatus = TIMER_NULL_PTR;
    }
    else if (!IS_VALID_MODE(ConfigPtr->Mode)) {
        Local_ErrorStatus = TIMER_INVALID_MODE;
    }
    else if (!IS_VALID_OC_MODE(ConfigPtr->OCMode)) {
        Local_ErrorStatus = TIMER_INVALID_OC_MODE;
    }
    else if (!IS_VALID_TIMER_2_PRESCALER(ConfigPtr->Prescaler.Timer2Prescaler)) {
        Local_ErrorStatus = TIMER_INVALID_PRESCALER;
    }
    else {
        u8 Local_u8TempReg = 0;
         
        Local_u8TempReg |= ConfigPtr->Mode;
        Local_u8TempReg |= ConfigPtr->OCMode;
        Local_u8TempReg |= ConfigPtr->Prescaler.Timer2Prescaler;
        TCCR2 = Local_u8TempReg;
        TCNT2 = ConfigPtr->InitialValue;
        OCR2 = ConfigPtr->CompareValue;
         
    }

    return Local_ErrorStatus;
}

TIMER_enumErrorType TIMER_2_enumStart(TIMER_2_enumPrescalerType Prescaler) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

    if (!IS_VALID_TIMER_2_PRESCALER(Prescaler)) {
        Local_ErrorStatus = TIMER_INVALID_PRESCALER;
    }
    else {
         
        TCCR2 &= TIMER_2_SCALER_CLR_BITS;
        TCCR2 |= Prescaler;
         
    }

    return Local_ErrorStatus;
}

TIMER_enumErrorType TIMER_2_enumStop(void) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

     
    TCCR2 &= TIMER_2_SCALER_CLR_BITS;
     

    return Local_ErrorStatus;
}

TIMER_enumErrorType TIMER_2_enumSetCounter(u8 Value) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

    TCNT2 = Value;

    return Local_ErrorStatus;
}

TIMER_enumErrorType TIMER_2_enumSetCompare(u8 Value) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

    OCR2 = Value;

    return Local_ErrorStatus;
}

TIMER_enumErrorType TIMER_2_enumGetTimeElapsed(u16* ValuePtr) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

    if (ValuePtr == NULL_PTR) {
        Local_ErrorStatus = TIMER_NULL_PTR;
    }
    else {
        *ValuePtr = (u16)TCNT2;
    }

    return Local_ErrorStatus;
}

TIMER_enumErrorType TIMER_2_enumGetTimeRemaining(u16* ValuePtr) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

    if (ValuePtr == NULL_PTR) {
        Local_ErrorStatus = TIMER_NULL_PTR;
    }
    else if ((TCCR2 & TIMER_MODE_CTC) != TIMER_MODE_CTC) {
        Local_ErrorStatus = TIMER_INVALID_MODE;
    }
    else {
        *ValuePtr = (u16)(OCR2 - TCNT2);
    }

    return Local_ErrorStatus;
}

TIMER_enumErrorType TIMER_2_enumOverflowInterruptEnable(void) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

    SET_BIT(TIMSK, TOIE2);

    return Local_ErrorStatus;
}

TIMER_enumErrorType TIMER_2_enumverflowInterruptDisable(void) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

    CLEAR_BIT(TIMSK, TOIE2);

    return Local_ErrorStatus;
}

TIMER_enumErrorType TIMER_2_enumCompareInterruptEnable(void) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

    SET_BIT(TIMSK, OCIE2);

    return Local_ErrorStatus;
}

TIMER_enumErrorType TIMER_2_enumCompareInterruptDisable(void) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

    CLEAR_BIT(TIMSK, OCIE2);

    return Local_ErrorStatus;
}

TIMER_enumErrorType TIMER_2_enumSetOverflowCallback(void (*CallbackPtr)(void)) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

    if (CallbackPtr == NULL_PTR) {
        Local_ErrorStatus = TIMER_NULL_PTR;
    }
    else {
         
        Timer2_OverflowCallback = CallbackPtr;
         
    }

    return Local_ErrorStatus;
}

TIMER_enumErrorType TIMER_2_enumSetCompareCallback(void (*CallbackPtr)(void)) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

    if (CallbackPtr == NULL_PTR) {
        Local_ErrorStatus = TIMER_NULL_PTR;
    }
    else {
         
        Timer2_CompareCallback = CallbackPtr;
         
    }

    return Local_ErrorStatus;
}

TIMER_enumErrorType TIMER_2_enumIsRunning(u8* StatusPtr) {
    TIMER_enumErrorType Local_ErrorStatus = TIMER_OK;

    if (StatusPtr == NULL_PTR) {
        Local_ErrorStatus = TIMER_NULL_PTR;
    }
    else {
        *StatusPtr = (TCCR2 & (CS22 | CS21 | CS20)) ? 1 : 0;
    }

    return Local_ErrorStatus;
}

/**************************** Interrupt Service Routines ************************/

ISR(TIMER0_OVF_vect) {
    if (Timer0_OverflowCallback != NULL_PTR) {
        Timer0_OverflowCallback();
    }
}

ISR(TIMER0_OC_vect) {
    if (Timer0_CompareCallback != NULL_PTR) {
        Timer0_CompareCallback();
    }
}

ISR(TIMER2_OVF_vect) {
    if (Timer2_OverflowCallback != NULL_PTR) {
        Timer2_OverflowCallback();
    }
}

ISR(TIMER2_COMP_vect) {
    if (Timer2_CompareCallback != NULL_PTR) {
        Timer2_CompareCallback();
    }
}