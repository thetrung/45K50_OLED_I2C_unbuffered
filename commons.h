/* NOTE :: thetrung @ 12th April, 2025 ::
 *  
 * - Embrace on better Short-hand in simple C/Rust-style :
 *   Which I want to embrace over C++ & complex MCC generated code.
 *
 * - Things should be simple & minimal, like whatever RTOS we gonna build.
 * 
 * - With unbuffered rendering, finding expensive PIC/MCU is no longer necessary.
 * 
 * - Maybe, now beefy Pico/STM32/ESP32 are just for prototyping on Arduino-IDE.
 *   Then we port whatever worked well into PICs.
 */

#ifndef COMMONS_H
#define COMMONS_H

#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define _XTAL_FREQ 16000000     //CPU Frequency
// uintX_t
#define u8 uint8_t
#define u16 uint16_t
// intX_t
#define i8 int8_t
#define i16 int16_t

// MODE
#define LOW 0
#define HIGH 1

// I/O
#define INPUT 1
#define OUTPUT 0

// PORT-A
#define RA0 LATA0
#define RA1 LATA1
#define RA2 LATA2
#define RA3 LATA3
#define RA4 LATA4
#define RA5 LATA5
#define RA6 LATA6
#define RA7 LATA7

// PINMODE
#define PIN_RA0 TRISA0
#define PIN_RA1 TRISA1
#define PIN_RA2 TRISA2
#define PIN_RA3 TRISA3
#define PIN_RA4 TRISA4
#define PIN_RA5 TRISA5
#define PIN_RA6 TRISA6
#define PIN_RA7 TRISA7

// FUNCTIONS 
#define pinMode(PIN, MODE) (PIN = MODE)
#define digitalWrite(PORT, STATE) (PORT = STATE)
#define min(x1, x2) (x1 < x2 ? x1 : x2)
#define max(x1, x2) (x1 > x2 ? x1 : x2)

#define delay __delay_ms

//External functions
extern void init(void);

#endif