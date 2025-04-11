/*
 * 20190306.002 -> 12th April, 2025
 * OLED 128x32  -> 128x64
 *
 * File: init.h
 * Processor: PIC16F1825 -> PIC18F45K50
 * Author: wizlab.it && thetrung
 */

#ifndef INIT_H
#define	INIT_H

#include "commons.h"

#pragma config FOSC = INTOSCIO  // Oscillator Selection (Internal oscillator)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)

void init(void);
void __interrupt() isr(void);

#endif