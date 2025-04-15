/*
 * 20190312.014
 * OLED 128x32
 *
 * File: main.c
 * Processor: PIC16F1825
 * Author: wizlab.it
 */
#define SSD1306_128_64

#include "main.h"
#include "ssd1306_buffered.c"

void testdrawcircle(void) {
  for (i8 i = 0; i < SSD1306_LCDHEIGHT; i += 2) {
    SSD1306_DrawCircle(SSD1306_LCDWIDTH/2, SSD1306_LCDHEIGHT/2, i);
    SSD1306_Display();
    delay(1);
  }
}
 
void testfillrect(void) {
  bool color = true;
  for (i8 i = 0; i < SSD1306_LCDHEIGHT/2; i += 3) {
    // alternate colors
    SSD1306_FillRect(i, i, SSD1306_LCDWIDTH - i*2, SSD1306_LCDHEIGHT - i*2, color);
    SSD1306_Display();
    delay(1);
    if(color)  color = false;
    else       color = true;
  }
}
 
void testdrawtriangle(void) {
  for (i8 i = 0; i < SSD1306_LCDHEIGHT/2; i += 5) {
    SSD1306_DrawTriangle(SSD1306_LCDWIDTH/2,     SSD1306_LCDHEIGHT/2 - i,
                         SSD1306_LCDWIDTH/2 - i, SSD1306_LCDHEIGHT/2 + i,
                         SSD1306_LCDWIDTH/2 + i, SSD1306_LCDHEIGHT/2 + i);
    SSD1306_Display();
    delay(1);
  }
}
 
void testfilltriangle(void) {
  bool color = true;
  for (i16 i = SSD1306_LCDHEIGHT/2; i > 0; i -= 5) {
    SSD1306_FillTriangle(SSD1306_LCDWIDTH/2,     SSD1306_LCDHEIGHT/2 - i,
                         SSD1306_LCDWIDTH/2 - i, SSD1306_LCDHEIGHT/2 + i,
                         SSD1306_LCDWIDTH/2 + i, SSD1306_LCDHEIGHT/2 + i, color);
    if(color)  color = false;
    else       color = true;
    SSD1306_Display();
    delay(1);
  }
}
 
void testdrawroundrect(void) {
  for (i8 i = 0; i < SSD1306_LCDHEIGHT/2 - 2; i += 2) {
    SSD1306_DrawRoundRect(i, i, SSD1306_LCDWIDTH - 2*i, SSD1306_LCDHEIGHT - 2*i, SSD1306_LCDHEIGHT/4 - i/2);
    SSD1306_Display();
    delay(1);
  }
}
 
void testfillroundrect(void) {
  bool color = true;
  for (i8 i = 0; i < SSD1306_LCDHEIGHT/2 - 2; i += 2) {
    SSD1306_FillRoundRect(i, i, SSD1306_LCDWIDTH - 2*i, SSD1306_LCDHEIGHT - 2*i, SSD1306_LCDHEIGHT/4 - i/2, color);
    if(color)  color = false;
    else       color = true;
    SSD1306_Display();
    delay(1);
  }
}
   
void testdrawrect(void) {
  for (i8 i = 0; i < SSD1306_LCDHEIGHT/2; i += 2) {
    SSD1306_DrawRect(i, i, SSD1306_LCDWIDTH - 2*i, SSD1306_LCDHEIGHT - 2*i);
    SSD1306_Display();
    delay(1);
  }
}
 
void testdrawline() {  
  for (int i = 0; i < SSD1306_LCDWIDTH; i += 4) {
    SSD1306_DrawLine(0, 0, i, SSD1306_LCDHEIGHT - 1, true);
    SSD1306_Display();
    delay(1);
  }
  for (int i = 0; i < SSD1306_LCDHEIGHT; i += 4) {
    SSD1306_DrawLine(0, 0, SSD1306_LCDWIDTH - 1, i, true);
    SSD1306_Display();
    delay(1);
  }
  delay(250);
  
  SSD1306_ClearDisplay();
  for (int i = 0; i < SSD1306_LCDWIDTH; i += 4) {
    SSD1306_DrawLine(0, SSD1306_LCDHEIGHT - 1, i, 0, true);
    SSD1306_Display();
    delay(1);
  }
  for (int i = SSD1306_LCDHEIGHT - 1; i >= 0; i -= 4) {
    SSD1306_DrawLine(0, SSD1306_LCDHEIGHT - 1, SSD1306_LCDWIDTH - 1, i, true);
    SSD1306_Display();
    delay(1);
  }
  delay(250);
  
  SSD1306_ClearDisplay();
  for (int i = SSD1306_LCDWIDTH - 1; i >= 0; i -= 4) {
    SSD1306_DrawLine(SSD1306_LCDWIDTH - 1, SSD1306_LCDHEIGHT - 1, i, 0, true);
    SSD1306_Display();
    delay(1);
  }
  for (int i = SSD1306_LCDHEIGHT - 1; i >= 0; i -= 4) {
    SSD1306_DrawLine(SSD1306_LCDWIDTH - 1, SSD1306_LCDHEIGHT - 1, 0, i, true);
    SSD1306_Display();
    delay(1);
  }
  delay(250);
 
  SSD1306_ClearDisplay();
  for (int i = 0; i < SSD1306_LCDHEIGHT; i += 4) {
    SSD1306_DrawLine(SSD1306_LCDWIDTH - 1, 0, 0, i, true);
    SSD1306_Display();
    delay(1);
  }
  for (int i = 0; i < SSD1306_LCDWIDTH; i += 4) {
    SSD1306_DrawLine(SSD1306_LCDWIDTH - 1, 0, i, SSD1306_LCDHEIGHT - 1, true); 
    SSD1306_Display();
    delay(1);
  }
  delay(250);
}
 
void testscrolltext(void) {
  SSD1306_ClearDisplay();
  SSD1306_DrawText(58, 8, "scroll", 2);
  SSD1306_Display();
  delay(1);
 
  SSD1306_StartScrollRight(0x00, 0x0F);
  delay(2000);
  SSD1306_StopScroll();
  delay(1000);
  SSD1306_StartScrollLeft(0x00, 0x0F);
  delay(2000);
  SSD1306_StopScroll();
  delay(1000);    
  SSD1306_StartScrollDiagRight(0x00, 0x07);
  delay(2000);
  SSD1306_StartScrollDiagLeft(0x00, 0x07);
  delay(2000);
  SSD1306_StopScroll();
}

/*==============================================================================
 * Main routine
 *  - Initialize system
 *  - Loop forever
 *============================================================================*/
void main(void) {
    init();
    blink();       // indicate finished init()
    delay(100);
    
//    init_OLED();    
    SSD1306_Begin(SSD1306_SWITCHCAPVCC, 0x3C);
    blink();       
    delay(100);
   
    SSD1306_ClearDisplay();
    delay(100);
    
    // SSD1306_FillScreen(true);
    SSD1306_DrawPixel(20,20, true); 
   
    SSD1306_Display();
    
    // draw many lines
    blink();
    testdrawline();
    SSD1306_Display();
    delay(2000);
    SSD1306_ClearDisplay();

    // draw rectangles
    blink();
    testdrawrect();
    SSD1306_Display();
    delay(2000);
    SSD1306_ClearDisplay();

    // draw multiple rectangles
    blink();
    testfillrect();
    SSD1306_Display();
    delay(2000);
    SSD1306_ClearDisplay();

    // draw mulitple circles
    blink();
    testdrawcircle();
    SSD1306_Display();
    delay(2000);
    SSD1306_ClearDisplay();

    // draw a white circle, 10 pixel radius
    blink();
    SSD1306_FillCircle(SSD1306_LCDWIDTH/2, SSD1306_LCDHEIGHT/2, 10, true);
    SSD1306_Display();
    delay(2000);
    SSD1306_ClearDisplay();

    
    blink();
    testdrawroundrect();
    SSD1306_Display();
    delay(2000);
    SSD1306_ClearDisplay();

    blink();
    testfillroundrect();
    SSD1306_Display();
    delay(2000);
    SSD1306_ClearDisplay();

    blink();
    testdrawtriangle();
    SSD1306_Display();
    delay(2000);
    SSD1306_ClearDisplay();

    blink();
    testfilltriangle();
    SSD1306_Display();
    delay(2000);
    SSD1306_ClearDisplay();

    blink();
    // draw scrolling text
    testscrolltext();
    SSD1306_Display();
    delay(2000);
    SSD1306_ClearDisplay();

    blink();
    // text display tests
    char txt[9];
    SSD1306_DrawText(2, 7, "Hello, world!", 1);

    sprintf(txt, "%.6f", 3.141592);
    SSD1306_DrawText(2, 16, txt, 1);

    SSD1306_DrawText(2, 26, "0x", 2);

    sprintf(txt, "%LX", 0xDEADBEEF);
    SSD1306_DrawText(26, 26, txt, 2);
    SSD1306_Display();
    delay(2000);

//     // prepare to read AN1 with ADC :
// //    pinMode(PIN_RA1, INPUT);
    
//     OLED_Draw_H_Line(0, 127, 0);
//     OLED_Draw_H_Line(0, 127, 8);
// //    OLED_Draw_H_Line(0, 127, 16);
//     OLED_Draw_H_Line(0, 127, 32);
// //    OLED_Draw_H_Line(0, 127, 47);
//     OLED_Draw_H_Line(0, 127, 55);
//     OLED_Draw_H_Line(0, 127, 63);
// //    OLED_Draw_H_Line(0, 127, 2);
// //    OLED_Draw_H_Line(0, 127, 7);
// //    OLED_Draw_H_Line(0, 127, 8);
//     OLED_Draw_V_Line(0, 0, 63);
//     OLED_Draw_V_Line(63, 0, 63);
//     OLED_Draw_V_Line(127, 0, 63);
    // Char Size = 4
    // Render mode : 
    // - MEM_HORZ
    // - COMDEC
    // - 
//    OLED_PutChar('A', 123, 31);
    /**
     * TEXT RENDERING TEST :
     * - 8 LINES at cost of 9 Pixels each.
     * - HEIGHT [0..9]
     * - WIDTH 5 
     */
//    OLED_Printf(" Hello World "  ,0, 0);
//    OLED_Printf(" 01234567890~"  ,0, 9);
//    OLED_Printf(" QWERTYUIOP[]\\",0, 18);
//    OLED_Printf(" ASDFGHJKL:;  " ,0, 27);
//    OLED_Printf(" ZXCVBNM,./  "  ,0, 36);
//    OLED_Printf(" +-*/=!@#$%^&"  ,0, 45);
//    OLED_Printf(" NEWLINE "      ,0, 54);
//    OLED_Printf(" R E A D Y   "  ,0, 63);

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
    delay(100);
    //Test
//   const ui8_t image[] = {
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