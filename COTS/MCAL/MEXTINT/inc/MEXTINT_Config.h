#ifndef MEXTINT_CONFIG_H_
#define MEXTINT_CONFIG_H_

#include "MEXTINT.h"

/**
 * @brief Configuration macros for external interrupt trigger modes.
 */

/**
 * @brief Configuration for external interrupt 0 trigger mode.
 * Options:
 *   - MEXTINT_INT0_LOW_LEVEL      : Trigger on low level
 *   - MEXTINT_INT0_LOGICAL_CHANGE : Trigger on logical change
 *   - MEXTINT_INT0_FALLING_EDGE   : Trigger on falling edge
 *   - MEXTINT_INT0_RISING_EDGE    : Trigger on rising edge
 */
#define MEXTINT_EXTI0_SOURCE_CONFIG    MEXTINT_INT0_RISING_EDGE  // External interrupt 0 trigger mode

/**
 * @brief Configuration for external interrupt 1 trigger mode.
 * Options:
 *   - MEXTINT_INT1_LOW_LEVEL      : Trigger on low level
 *   - MEXTINT_INT1_LOGICAL_CHANGE : Trigger on logical change
 *   - MEXTINT_INT1_FALLING_EDGE   : Trigger on falling edge
 *   - MEXTINT_INT1_RISING_EDGE    : Trigger on rising edge
 */
#define MEXTINT_EXTI1_SOURCE_CONFIG    MEXTINT_INT1_RISING_EDGE  // External interrupt 1 trigger mode

/**
 * @brief Configuration for external interrupt 2 trigger mode.
 * Options:
 *   - MEXTINT_INT2_FALLING_EDGE   : Trigger on falling edge
 *   - MEXTINT_INT2_RISING_EDGE    : Trigger on rising edge
 */
#define MEXTINT_EXTI2_SOURCE_CONFIG    MEXTINT_INT2_RISING_EDGE  // External interrupt 2 trigger mode

/**
 * @brief Configuration macros for enabling/disabling external interrupts.
 */

/**
 * @brief Configuration for external interrupt 0 state.
 * Options:
 *   - MEXTINT_SOURCE_DISABLE : Disable external interrupt 0
 *   - MEXTINT_SOURCE_ENABLE  : Enable external interrupt 0
 */
#define MEXTINT_EXTI0_SOURCE_STATE     MEXTINT_SOURCE_ENABLE  // External interrupt 0 state

/**
 * @brief Configuration for external interrupt 1 state.
 * Options:
 *   - MEXTINT_SOURCE_DISABLE : Disable external interrupt 1
 *   - MEXTINT_SOURCE_ENABLE  : Enable external interrupt 1
 */
#define MEXTINT_EXTI1_SOURCE_STATE     MEXTINT_SOURCE_ENABLE  // External interrupt 1 state

/**
 * @brief Configuration for external interrupt 2 state.
 * Options:
 *   - MEXTINT_SOURCE_DISABLE : Disable external interrupt 2
 *   - MEXTINT_SOURCE_ENABLE  : Enable external interrupt 2
 */
#define MEXTINT_EXTI2_SOURCE_STATE     MEXTINT_SOURCE_ENABLE  // External interrupt 2 state

#endif /* MEXTINT_CONFIG_H_ */