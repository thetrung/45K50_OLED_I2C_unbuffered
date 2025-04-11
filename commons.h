/*
 * 20190312.008
 * OLED 128x32
 *
 * File: commons.h
 * Processor: PIC16F1825
 * Author: wizlab.it
 */

#ifndef COMMONS_H
#define COMMONS_H

#include <xc.h>
#include <stdint.h>
#include "I2CMaster.h"
#include "OLED.h"

#define _XTAL_FREQ 16000000     //CPU Frequency

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
#define u8 uint8_t
#define u16 uint16_t

//External functions
extern void init(void);

#endif