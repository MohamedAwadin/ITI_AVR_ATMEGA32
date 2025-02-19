#ifndef MEXTINT_PRIVATE_H_
#define MEXTINT_PRIVATE_H_

/**
 * @brief Masks for clearing interrupt configuration bits.
 */
#define MEXTINT_INT0_CLRMASK  ((u8)(0xFC))  // Mask for INT0 configuration bits
#define MEXTINT_INT1_CLRMASK  ((u8)(0xF3))  // Mask for INT1 configuration bits
#define MEXTINT_INT2_CLRMASK  ((u8)(0xBF))  // Mask for INT2 configuration bits

/****************** Interrupt Registers ******************************************/

/**
 * @brief Status Register (SREG) address.
 */
#define SREG    (*((volatile u8*)0x5F))  // Address of Status Register

/**
 * @brief Global Interrupt Enable (GIE) bit in SREG.
 */
#define GIE     (7U)  // Bit position for global interrupt enable

/**
 * @brief MCU Control and Status Register (MCUCSR) address.
 */
#define MCUCSR  (*(volatile unsigned char*)0x54)  // Address of MCUCSR

/**
 * @brief Interrupt Sense Control 2 (ISC2) bit in MCUCSR.
 */
#define ISC2    (6U)  // Bit position for INT2 trigger mode

/**
 * @brief MCU Control Register (MCUCR) address.
 */
#define MCUCR   (*(volatile unsigned char*)0x55)  // Address of MCUCR

/**
 * @brief Interrupt Sense Control 1 (ISC11, ISC10) bits in MCUCR.
 */
#define ISC11   (3U)  // Bit position for INT1 trigger mode (high bit)
#define ISC10   (2U)  // Bit position for INT1 trigger mode (low bit)

/**
 * @brief Interrupt Sense Control 0 (ISC01, ISC00) bits in MCUCR.
 */
#define ISC01   (1U)  // Bit position for INT0 trigger mode (high bit)
#define ISC00   (0U)  // Bit position for INT0 trigger mode (low bit)

/**
 * @brief General Interrupt Control Register (GICR) address.
 */
#define GICR    (*(volatile unsigned char*)0x5B)  // Address of GICR

/**
 * @brief External Interrupt Enable bits in GICR.
 */
#define INT1    (7U)  // Bit position for INT1 enable
#define INT0    (6U)  // Bit position for INT0 enable
#define INT2    (5U)  // Bit position for INT2 enable

/**
 * @brief General Interrupt Flag Register (GIFR) address.
 */
#define GIFR    (*(volatile unsigned char*)0x5A)  // Address of GIFR

/**
 * @brief External Interrupt Flag bits in GIFR.
 */
#define INTF1   (7U)  // Bit position for INT1 flag
#define INTF0   (6U)  // Bit position for INT0 flag
#define INTF2   (5U)  // Bit position for INT2 flag

/**
 * @brief Interrupt vector macros for external interrupts.
 */
#define INT0_vect   __vector_1  // Interrupt vector for INT0
#define INT1_vect   __vector_2  // Interrupt vector for INT1
#define INT2_vect   __vector_3  // Interrupt vector for INT2

/**
 * @brief Macros for enabling/disabling interrupts and defining ISRs.
 */
#define sei()  __asm__ __volatile__ ("sei" ::)  // Enable global interrupts
#define cli()  __asm__ __volatile__ ("cli" ::)  // Disable global interrupts
#define reti() __asm__ __volatile__ ("reti" ::) // Return from interrupt
#define ret()  __asm__ __volatile__ ("ret" ::)  // Return from function

#define ISR_NOBLOCK  __attribute__((interrupt))  // ISR attribute (non-blocking)
#define ISR_NAKED    __attribute__((naked))      // ISR attribute (naked)

/**
 * @brief Macro for defining ISR functions.
 */
#define ISR(vector, ...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)

#endif /* MEXTINT_PRIVATE_H_ */