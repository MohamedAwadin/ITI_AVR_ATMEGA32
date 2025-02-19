#ifndef MEXTINT_H_
#define MEXTINT_H_

#include "StdTypes.h"
#include "Bit_Math.h"
#include "MemMap.h"
#include "MEXTINT_Config.h"
#include "MEXTINT_Private.h"

/**
 * @brief Macros for external interrupt 0 trigger modes.
 */
#define MEXTINT_INT0_LOW_LEVEL         (0U)  // Low-level trigger
#define MEXTINT_INT0_LOGICAL_CHANGE    (1U)  // Logical change trigger
#define MEXTINT_INT0_FALLING_EDGE      (2U)  // Falling edge trigger
#define MEXTINT_INT0_RISING_EDGE       (3U)  // Rising edge trigger

/**
 * @brief Macros for external interrupt 1 trigger modes.
 */
#define MEXTINT_INT1_LOW_LEVEL         (0U)  // Low-level trigger
#define MEXTINT_INT1_LOGICAL_CHANGE    (1U)  // Logical change trigger
#define MEXTINT_INT1_FALLING_EDGE      (2U)  // Falling edge trigger
#define MEXTINT_INT1_RISING_EDGE       (3U)  // Rising edge trigger

/**
 * @brief Macros for external interrupt 2 trigger modes.
 */
#define MEXTINT_INT2_FALLING_EDGE      (0U)  // Falling edge trigger
#define MEXTINT_INT2_RISING_EDGE       (1U)  // Rising edge trigger

/**
 * @brief Macros for external interrupt sources.
 */
#define MEXTINT_EXTI0_SOURCE           (1U)  // External interrupt 0
#define MEXTINT_EXTI1_SOURCE           (2U)  // External interrupt 1
#define MEXTINT_EXTI2_SOURCE           (3U)  // External interrupt 2

/**
 * @brief Macros for enabling/disabling external interrupt sources.
 */
#define MEXTINT_SOURCE_DISABLE         (0U)  // Disable interrupt source
#define MEXTINT_SOURCE_ENABLE          (1U)  // Enable interrupt source

/**
 * @brief Enumeration for error statuses.
 */
typedef enum {
    MEXTINT_enumNOK,               // Operation failed
    MEXTINT_enumOK,                // Operation succeeded
    MEXTINT_enumInvalidEXTISOURCE, // Invalid external interrupt source
    MEXTINT_enumNullPtr            // Null pointer passed
} MEXTINT_enumErrorStatus_t;

/**
 * @brief Initializes the external interrupts based on the configuration macros.
 */
void MEXTINT_vInit(void);

/**
 * @brief Sets the callback function for a specific external interrupt.
 * @param Copy_u8EXTINT_Source: External interrupt source (MEXTINT_EXTI0_SOURCE, MEXTINT_EXTI1_SOURCE, MEXTINT_EXTI2_SOURCE).
 * @param Local_Fptr: Pointer to the callback function.
 * @return MEXTINT_enumErrorStatus_t: Error status.
 */
MEXTINT_enumErrorStatus_t MEXTINT_enumSetCallBack(u8 Copy_u8EXTINT_Source, void (*Local_Fptr)(void));

/**
 * @brief Enables global interrupts.
 */
void MEXTINT_vGLOBALENABLE(void);

/**
 * @brief Disables global interrupts.
 */
void MEXTINT_vGLOBALDISABLE(void);

#endif /* MEXTINT_H_ */