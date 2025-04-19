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
#include "I2CMaster.h"
#include "ssd1306_buffered.h"
#include "ssd1306_unbuffered.h"
// Functionalities 
#pragma config FOSC = INTOSCIO  // Oscillator Selection (Internal oscillator)
#pragma config WDTEN = OFF      // Watch-Dog-Enable = OFF
#pragma config MCLRE = OFF      // MCLR-Enable = OFF : LOW on reset.
// Code Protection
#pragma config CP0 = ON         // Code Protection for Flash Memory (block 0)
#pragma config CP1 = ON         // Code Protection for Flash Memory (block 1)
#pragma config CP2 = ON         // Code Protection for Flash Memory (block 2)
#pragma config CP3 = ON         // Code Protection for Flash Memory (block 3)
#pragma config CPB = ON         // Code Protection for Boot Block.
#pragma config CPD = ON        // Code Protection for Data Memory (RAM).
// Write Protection (per block)
#pragma config WRT0 = ON         // Write Protection for Flash Memory.
#pragma config WRT1 = ON         // Write Protection for Flash Memory.
#pragma config WRT2 = ON         // Write Protection for Flash Memory.
#pragma config WRT3 = ON         // Write Protection for Flash Memory.
#pragma config WRTB = ON        // Write Protection for Boot Block.
#pragma config WRTC = ON        // Write Protection for Config bits Registers.
#pragma config WRTD = ON       // Write Protection for Data Memory.
// Block External-Block-Table-Read :
#pragma config EBTR0 = OFF        // Read Protection for table-reading block 0. 
#pragma config EBTR1 = OFF        // Read Protection for table-reading block 1. 
#pragma config EBTR2 = OFF        // Read Protection for table-reading block 2. 
#pragma config EBTR3 = OFF        // Read Protection for table-reading block 3. 
#pragma config EBTRB = ON        // Read Protection for table-reading boot block. 
// Programming Mode 
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
void init(void);
void __interrupt() isr(void);

#endif