#ifndef TIMER_H
#define TIMER_H

#include "StdTypes.h"
#include "Bit_Math.h"
#include "MTIMER_private.h"
#include "MEXTINT.h"

/*********************************** TIMER DRIVER **********************************************/

/**
 * @brief Error status codes for Timer operations
 */
typedef enum {
    TIMER_OK = 0,                /**< Operation successful */
    TIMER_INVALID_MODE,          /**< Invalid timer mode specified */
    TIMER_INVALID_OC_MODE,       /**< Invalid OC pin mode specified */
    TIMER_INVALID_PRESCALER,     /**< Invalid prescaler value */
    TIMER_NULL_PTR,              /**< Null pointer passed */
    TIMER_NOT_RUNNING,           /**< Timer not running when expected */
    TIMER_INVALID_TIMER          /**< Invalid timer specified */
} TIMER_enumErrorType;

/**
 * @brief Timer operating modes (shared for Timer0 and Timer2)
 */
typedef enum {
    TIMER_MODE_NORMAL = 0x00,       /**< Normal mode, overflow at 255 */
    TIMER_MODE_PHASECORRECT = 0x40, /**< Phase-correct PWM mode */
    TIMER_MODE_CTC = 0x08,          /**< Clear Timer on Compare Match */
    TIMER_MODE_FASTPWM = 0x48       /**< Fast PWM mode */
} TIMER_enumModeType;

/**
 * @brief Timer OC pin behavior modes (shared for Timer0 and Timer2)
 */
typedef enum {
    TIMER_OC_DISCONNECTED = 0x00, /**< OC pin disconnected */
    TIMER_OC_TOGGLE = 0x10,       /**< Toggle OC on compare match */
    TIMER_OC_NON_INVERTING = 0x20,/**< Non-inverting mode (PWM) */
    TIMER_OC_INVERTING = 0x30     /**< Inverting mode (PWM) */
} TIMER_enumOCModeType;

/**
 * @brief Timer0 clock prescaler options
 */
typedef enum {
    TIMER_0_PRESCALER_STOP = 0x00, /**< Stop the timer */
    TIMER_0_PRESCALER_1 = 0x01,    /**< No prescaler (F_CPU) */
    TIMER_0_PRESCALER_8 = 0x02,    /**< Prescaler /8 */
    TIMER_0_PRESCALER_64 = 0x03,   /**< Prescaler /64 */
    TIMER_0_PRESCALER_256 = 0x04,  /**< Prescaler /256 */
    TIMER_0_PRESCALER_1024 = 0x05, /**< Prescaler /1024 */
    TIMER_0_PRESCALER_EXT_FALLING = 0x06, /**< External clock, falling edge */
    TIMER_0_PRESCALER_EXT_RISING = 0x07   /**< External clock, rising edge */
} TIMER_0_enumPrescalerType;

/**
 * @brief Timer2 clock prescaler options
 */
typedef enum {
    TIMER_2_PRESCALER_STOP = 0x00, /**< Stop the timer */
    TIMER_2_PRESCALER_1 = 0x01,    /**< No prescaler (F_CPU) */
    TIMER_2_PRESCALER_8 = 0x02,    /**< Prescaler /8 */
    TIMER_2_PRESCALER_32 = 0x03,   /**< Prescaler /32 */
    TIMER_2_PRESCALER_64 = 0x04,   /**< Prescaler /64 */
    TIMER_2_PRESCALER_128 = 0x05,  /**< Prescaler /128 */
    TIMER_2_PRESCALER_256 = 0x06,  /**< Prescaler /256 */
    TIMER_2_PRESCALER_1024 = 0x07  /**< Prescaler /1024 */
} TIMER_2_enumPrescalerType;

/**
 * @brief Configuration structure for Timers
 */
typedef struct {
    TIMER_enumModeType Mode;           /**< Timer operating mode */
    TIMER_enumOCModeType OCMode;       /**< OC pin behavior */
    union {
        TIMER_0_enumPrescalerType Timer0Prescaler; /**< Timer0 prescaler */
        TIMER_2_enumPrescalerType Timer2Prescaler; /**< Timer2 prescaler */
    } Prescaler;                   /**< Clock prescaler (union for type safety) */
    u8 InitialValue;               /**< Initial TCNT value (0-255) */
    u8 CompareValue;               /**< Initial OCR value (0-255) */
} TIMER_strConfigType;

/* Timer0 Functions */

/**
 * @brief Initialize Timer0 with the specified configuration.
 * @param ConfigPtr Pointer to the configuration structure for Timer0.
 * @return TIMER_enumErrorType Error status:
 *         - TIMER_OK: Success
 *         - TIMER_NULL_PTR: ConfigPtr is NULL
 *         - TIMER_INVALID_MODE: Invalid mode specified
 *         - TIMER_INVALID_OC_MODE: Invalid OC0 mode specified
 *         - TIMER_INVALID_PRESCALER: Invalid prescaler value
 * @note Configures TCCR0, TCNT0, and OCR0 registers atomically.
 */
TIMER_enumErrorType TIMER_0_enumInit(const TIMER_strConfigType* ConfigPtr);

/**
 * @brief Start Timer0 with the specified prescaler.
 * @param Prescaler Clock prescaler to apply (TIMER_0_enumPrescalerType).
 * @return TIMER_enumErrorType Error status:
 *         - TIMER_OK: Success
 *         - TIMER_INVALID_PRESCALER: Invalid prescaler value
 * @note Updates TCCR0 CS bits atomically.
 */
TIMER_enumErrorType TIMER_0_enumStart(TIMER_0_enumPrescalerType Prescaler);

/**
 * @brief Stop Timer0 by clearing the prescaler.
 * @return TIMER_enumErrorType Error status (always TIMER_OK).
 * @note Updates TCCR0 CS bits atomically to stop the timer.
 */
TIMER_enumErrorType TIMER_0_enumStop(void);

/**
 * @brief Set the Timer0 counter value (TCNT0).
 * @param Value Value to set (0-255).
 * @return TIMER_enumErrorType Error status (always TIMER_OK).
 */
TIMER_enumErrorType TIMER_0_enumSetCounter(u8 Value);

/**
 * @brief Set the Timer0 output compare value (OCR0).
 * @param Value Value to set (0-255).
 * @return TIMER_enumErrorType Error status (always TIMER_OK).
 * @note Affects PWM output on PB3 (OC0) if enabled.
 */
TIMER_enumErrorType TIMER_0_enumSetCompare(u8 Value);

/**
 * @brief Get the elapsed time from Timer0 (current TCNT0 value).
 * @param ValuePtr Pointer to store the elapsed time (0-255).
 * @return TIMER_enumErrorType Error status:
 *         - TIMER_OK: Success
 *         - TIMER_NULL_PTR: ValuePtr is NULL
 */
TIMER_enumErrorType TIMER_0_enumGetTimeElapsed(u16* ValuePtr);

/**
 * @brief Get the remaining time to reach OCR0 in CTC mode.
 * @param ValuePtr Pointer to store the remaining time (0-255).
 * @return TIMER_enumErrorType Error status:
 *         - TIMER_OK: Success
 *         - TIMER_NULL_PTR: ValuePtr is NULL
 *         - TIMER_INVALID_MODE: Timer not in CTC mode
 */
TIMER_enumErrorType TIMER_0_enumGetTimeRemaining(u16* ValuePtr);

/**
 * @brief Enable Timer0 overflow interrupt.
 * @return TIMER_enumErrorType Error status (always TIMER_OK).
 * @note Sets TOIE0 in TIMSK. Requires global interrupts enabled (sei()).
 */
TIMER_enumErrorType TIMER_0_enumOverflowInterruptEnable(void);

/**
 * @brief Disable Timer0 overflow interrupt.
 * @return TIMER_enumErrorType Error status (always TIMER_OK).
 * @note Clears TOIE0 in TIMSK.
 */
TIMER_enumErrorType TIMER_0_enumOverflowInterruptDisable(void);

/**
 * @brief Enable Timer0 compare match interrupt.
 * @return TIMER_enumErrorType Error status (always TIMER_OK).
 * @note Sets OCIE0 in TIMSK. Requires global interrupts enabled (sei()).
 */
TIMER_enumErrorType TIMER_0_enumCompareInterruptEnable(void);

/**
 * @brief Disable Timer0 compare match interrupt.
 * @return TIMER_enumErrorType Error status (always TIMER_OK).
 * @note Clears OCIE0 in TIMSK.
 */
TIMER_enumErrorType TIMER_0_enumCompareInterruptDisable(void);

/**
 * @brief Set the callback function for Timer0 overflow interrupt.
 * @param CallbackPtr Pointer to the callback function to execute on overflow.
 * @return TIMER_enumErrorType Error status:
 *         - TIMER_OK: Success
 *         - TIMER_NULL_PTR: CallbackPtr is NULL
 * @note Callback is called in TIMER0_OVF_vect ISR if interrupt is enabled.
 */
TIMER_enumErrorType TIMER_0_enumSetOverflowCallback(void (*CallbackPtr)(void));

/**
 * @brief Set the callback function for Timer0 compare match interrupt.
 * @param CallbackPtr Pointer to the callback function to execute on compare match.
 * @return TIMER_enumErrorType Error status:
 *         - TIMER_OK: Success
 *         - TIMER_NULL_PTR: CallbackPtr is NULL
 * @note Callback is called in TIMER0_OC_vect ISR if interrupt is enabled.
 */
TIMER_enumErrorType TIMER_0_enumSetCompareCallback(void (*CallbackPtr)(void));

/**
 * @brief Check if Timer0 is running.
 * @param StatusPtr Pointer to store the running status (1 = running, 0 = stopped).
 * @return TIMER_enumErrorType Error status:
 *         - TIMER_OK: Success
 *         - TIMER_NULL_PTR: StatusPtr is NULL
 */
TIMER_enumErrorType TIMER_0_enumIsRunning(u8* StatusPtr);

/* Timer2 Functions */

/**
 * @brief Initialize Timer2 with the specified configuration.
 * @param ConfigPtr Pointer to the configuration structure for Timer2.
 * @return TIMER_enumErrorType Error status:
 *         - TIMER_OK: Success
 *         - TIMER_NULL_PTR: ConfigPtr is NULL
 *         - TIMER_INVALID_MODE: Invalid mode specified
 *         - TIMER_INVALID_OC_MODE: Invalid OC2 mode specified
 *         - TIMER_INVALID_PRESCALER: Invalid prescaler value
 * @note Configures TCCR2, TCNT2, and OCR2 registers atomically.
 */
TIMER_enumErrorType TIMER_2_enumInit(const TIMER_strConfigType* ConfigPtr);

/**
 * @brief Start Timer2 with the specified prescaler.
 * @param Prescaler Clock prescaler to apply (TIMER_2_enumPrescalerType).
 * @return TIMER_enumErrorType Error status:
 *         - TIMER_OK: Success
 *         - TIMER_INVALID_PRESCALER: Invalid prescaler value
 * @note Updates TCCR2 CS bits atomically.
 */
TIMER_enumErrorType TIMER_2_enumStart(TIMER_2_enumPrescalerType Prescaler);

/**
 * @brief Stop Timer2 by clearing the prescaler.
 * @return TIMER_enumErrorType Error status (always TIMER_OK).
 * @note Updates TCCR2 CS bits atomically to stop the timer.
 */
TIMER_enumErrorType TIMER_2_enumStop(void);

/**
 * @brief Set the Timer2 counter value (TCNT2).
 * @param Value Value to set (0-255).
 * @return TIMER_enumErrorType Error status (always TIMER_OK).
 */
TIMER_enumErrorType TIMER_2_enumSetCounter(u8 Value);

/**
 * @brief Set the Timer2 output compare value (OCR2).
 * @param Value Value to set (0-255).
 * @return TIMER_enumErrorType Error status (always TIMER_OK).
 * @note Affects PWM output on PB7 (OC2) if enabled.
 */
TIMER_enumErrorType TIMER_2_enumSetCompare(u8 Value);

/**
 * @brief Get the elapsed time from Timer2 (current TCNT2 value).
 * @param ValuePtr Pointer to store the elapsed time (0-255).
 * @return TIMER_enumErrorType Error status:
 *         - TIMER_OK: Success
 *         - TIMER_NULL_PTR: ValuePtr is NULL
 */
TIMER_enumErrorType TIMER_2_enumGetTimeElapsed(u16* ValuePtr);

/**
 * @brief Get the remaining time to reach OCR2 in CTC mode.
 * @param ValuePtr Pointer to store the remaining time (0-255).
 * @return TIMER_enumErrorType Error status:
 *         - TIMER_OK: Success
 *         - TIMER_NULL_PTR: ValuePtr is NULL
 *         - TIMER_INVALID_MODE: Timer not in CTC mode
 */
TIMER_enumErrorType TIMER_2_enumGetTimeRemaining(u16* ValuePtr);

/**
 * @brief Enable Timer2 overflow interrupt.
 * @return TIMER_enumErrorType Error status (always TIMER_OK).
 * @note Sets TOIE2 in TIMSK. Requires global interrupts enabled (sei()).
 */
TIMER_enumErrorType TIMER_2_enumOverflowInterruptEnable(void);

/**
 * @brief Disable Timer2 overflow interrupt.
 * @return TIMER_enumErrorType Error status (always TIMER_OK).
 * @note Clears TOIE2 in TIMSK.
 */
TIMER_enumErrorType TIMER_2_enumOverflowInterruptDisable(void);

/**
 * @brief Enable Timer2 compare match interrupt.
 * @return TIMER_enumErrorType Error status (always TIMER_OK).
 * @note Sets OCIE2 in TIMSK. Requires global interrupts enabled (sei()).
 */
TIMER_enumErrorType TIMER_2_enumCompareInterruptEnable(void);

/**
 * @brief Disable Timer2 compare match interrupt.
 * @return TIMER_enumErrorType Error status (always TIMER_OK).
 * @note Clears OCIE2 in TIMSK.
 */
TIMER_enumErrorType TIMER_2_enumCompareInterruptDisable(void);

/**
 * @brief Set the callback function for Timer2 overflow interrupt.
 * @param CallbackPtr Pointer to the callback function to execute on overflow.
 * @return TIMER_enumErrorType Error status:
 *         - TIMER_OK: Success
 *         - TIMER_NULL_PTR: CallbackPtr is NULL
 * @note Callback is called in TIMER2_OVF_vect ISR if interrupt is enabled.
 */
TIMER_enumErrorType TIMER_2_enumSetOverflowCallback(void (*CallbackPtr)(void));

/**
 * @brief Set the callback function for Timer2 compare match interrupt.
 * @param CallbackPtr Pointer to the callback function to execute on compare match.
 * @return TIMER_enumErrorType Error status:
 *         - TIMER_OK: Success
 *         - TIMER_NULL_PTR: CallbackPtr is NULL
 * @note Callback is called in TIMER2_COMP_vect ISR if interrupt is enabled.
 */
TIMER_enumErrorType TIMER_2_enumSetCompareCallback(void (*CallbackPtr)(void));

/**
 * @brief Check if Timer2 is running.
 * @param StatusPtr Pointer to store the running status (1 = running, 0 = stopped).
 * @return TIMER_enumErrorType Error status:
 *         - TIMER_OK: Success
 *         - TIMER_NULL_PTR: StatusPtr is NULL
 */
TIMER_enumErrorType TIMER_2_enumIsRunning(u8* StatusPtr);

#endif /* TIMER_H */