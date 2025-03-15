#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

/* Timer0 Bit Masks */
#define TIMER_0_SCALER_CLR_BITS    (u8)(0xF8)  /**< Clear CS02:CS00 bits (0b11111000) */
#define TIMER_0_MODE_CLR_BITS      (u8)(0xB7)  /**< Clear WGM01, WGM00 bits (0b10110111) */
#define TIMER_0_OC0_MODE_CLR_BITS  (u8)(0xCF)  /**< Clear COM01, COM00 bits (0b11001111) */

/* Timer2 Bit Masks */
#define TIMER_2_SCALER_CLR_BITS    (u8)(0xF8)  /**< Clear CS22:CS20 bits (0b11111000) */
#define TIMER_2_MODE_CLR_BITS      (u8)(0xB7)  /**< Clear WGM21, WGM20 bits (0b10110111) */
#define TIMER_2_OC2_MODE_CLR_BITS  (u8)(0xCF)  /**< Clear COM21, COM20 bits (0b11001111) */

/* Timer0 Registers */
#define TCNT0   (*(volatile unsigned char*)0x52) /**< Timer0 Counter Register */
#define TCCR0   (*(volatile unsigned char*)0x53) /**< Timer0 Control Register */
#define OCR0    (*(volatile unsigned char*)0x5C) /**< Timer0 Output Compare Register */

/* Timer2 Registers */
#define TCNT2   (*(volatile unsigned char*)0x44) /**< Timer2 Counter Register */
#define TCCR2   (*(volatile unsigned char*)0x45) /**< Timer2 Control Register */
#define OCR2    (*(volatile unsigned char*)0x43) /**< Timer2 Output Compare Register */

/* Shared Registers */
#define TIFR    (*(volatile unsigned char*)0x58) /**< Timer Interrupt Flag Register */
#define TIMSK   (*(volatile unsigned char*)0x59) /**< Timer Interrupt Mask Register */

/* TCCR0 Bit Definitions */
#define FOC0    7 /**< Force Output Compare */
#define WGM00   6 /**< Waveform Generation Mode 0 */
#define COM01   5 /**< Compare Output Mode 1 */
#define COM00   4 /**< Compare Output Mode 0 */
#define WGM01   3 /**< Waveform Generation Mode 1 */
#define CS02    2 /**< Clock Select 2 */
#define CS01    1 /**< Clock Select 1 */
#define CS00    0 /**< Clock Select 0 */

/* TCCR2 Bit Definitions */
#define FOC2    7 /**< Force Output Compare */
#define WGM20   6 /**< Waveform Generation Mode 0 */
#define COM21   5 /**< Compare Output Mode 1 */
#define COM20   4 /**< Compare Output Mode 0 */
#define WGM21   3 /**< Waveform Generation Mode 1 */
#define CS22    2 /**< Clock Select 2 */
#define CS21    1 /**< Clock Select 1 */
#define CS20    0 /**< Clock Select 0 */

/* TIMSK Bit Definitions */
#define OCIE2   7 /**< Timer2 Output Compare Interrupt Enable */
#define TOIE2   6 /**< Timer2 Overflow Interrupt Enable */
#define OCIE0   1 /**< Timer0 Output Compare Interrupt Enable */
#define TOIE0   0 /**< Timer0 Overflow Interrupt Enable */

/* TIFR Bit Definitions */
#define OCF2    7 /**< Timer2 Output Compare Flag */
#define TOV2    6 /**< Timer2 Overflow Flag */
#define OCF0    1 /**< Timer0 Output Compare Flag */
#define TOV0    0 /**< Timer0 Overflow Flag */

#endif /* TIMER_PRIVATE_H */