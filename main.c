/*
 * 20190312.014
 * OLED 128x32
 *
 * File: main.c
 * Processor: PIC16F1825
 * Author: wizlab.it
 */

#include "main.h"

u8 invert = 0x00;

/*==============================================================================
 * Main routine
 *  - Initialize system
 *  - Loop forever
 *============================================================================*/
void main(void) {
    init();
    blink();       // indicate finished init()
    delay(100);
    
    init_OLED();    
    blink();       
    delay(100);
    
    // prepare to read AN1 with ADC :
//    pinMode(PIN_RA1, INPUT);
    
//    OLED_DrawRectangle(0,0, 127, 8);
    OLED_Draw_H_Line(0, 127, 0);
    OLED_Draw_H_Line(0, 127, 31);
    OLED_Draw_H_Line(0, 127, 63);
//    OLED_Draw_H_Line(0, 127, 2);
//    OLED_Draw_H_Line(0, 127, 7);
//    OLED_Draw_H_Line(0, 127, 8);
    OLED_Draw_V_Line(0, 0, 63);
    OLED_Draw_V_Line(63, 0, 63);
    OLED_Draw_V_Line(127, 0, 63);

    //Loop
    while(1) loop();
}

void blink(void){
    // Set pin RA0 as OUTPUT 
   pinMode(PIN_RA0, OUTPUT);
   
    digitalWrite(RA0, HIGH);
    delay(1);
    digitalWrite(RA0, LOW);
    delay(1);
}

/*==============================================================================
 * Loop routine
 *============================================================================*/
void loop(void) {
    __delay_ms(100);
    
    //Test
//   const uint8_t image[] = {
//        
//        0b00001111,
//        0b00001001,
//        0b00001001,
//        0b00001001,
//        0b00001001,
//        0b00001001,
//        0b00001001,
//        0b00001001,
//        0b00001001,
//        0b00001001,
//        0b00001111,
//        
//   };
//   OLED_DrawBitmap(0, 0, 0, 127, image, sizeof(image));
    //OLED_DrawBitmap(0x00, 0x03, 0x40, 0x7F, image, sizeof(image));
    //OLED_DrawBitmap(0x00, 0x03, 0x60, 0x7F, image, sizeof(image));
    //Invert
//    OLED_InvertDisplay(invert);
//    invert++;
//    if(invert > 0x01) invert = 0x00;
}