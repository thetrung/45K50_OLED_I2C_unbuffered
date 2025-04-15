/*
 * 20190312.014
 * OLED 128x32
 *
 * File: main.c
 * Processor: PIC16F1825
 * Author: wizlab.it
 */
#include "ssd1306_unbuffered.h"
#define SSD1306_128_64

#include "main.h"
#include "ssd1306_buffered.c"

void testdrawcircle(void) {
  for (i8 i = 0; i < SSD1306_LCDHEIGHT; i += 2) {
    SSD1306_DrawCircle(SSD1306_LCDWIDTH/2, SSD1306_LCDHEIGHT/2, i);
    SSD1306_Display();
    // delay(1);
  }
}
 
void testfillrect(void) {
  bool color = true;
  for (i8 i = 0; i < SSD1306_LCDHEIGHT/2; i += 3) {
    // alternate colors
    SSD1306_FillRect(i, i, SSD1306_LCDWIDTH - i*2, SSD1306_LCDHEIGHT - i*2, color);
    SSD1306_Display();
    // delay(1);
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
    // delay(1);
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
    // delay(1);
  }
}
 
void testdrawroundrect(void) {
  for (i8 i = 0; i < SSD1306_LCDHEIGHT/2 - 2; i += 2) {
    SSD1306_DrawRoundRect(i, i, SSD1306_LCDWIDTH - 2*i, SSD1306_LCDHEIGHT - 2*i, SSD1306_LCDHEIGHT/4 - i/2);
    SSD1306_Display();
    // delay(1);
  }
}
 
void testfillroundrect(void) {
  bool color = true;
  for (i8 i = 0; i < SSD1306_LCDHEIGHT/2 - 2; i += 2) {
    SSD1306_FillRoundRect(i, i, SSD1306_LCDWIDTH - 2*i, SSD1306_LCDHEIGHT - 2*i, SSD1306_LCDHEIGHT/4 - i/2, color);
    if(color)  color = false;
    else       color = true;
    SSD1306_Display();
    // delay(1);
  }
}
   
void testdrawrect(void) {
  for (i8 i = 0; i < SSD1306_LCDHEIGHT/2; i += 2) {
    SSD1306_DrawRect(i, i, SSD1306_LCDWIDTH - 2*i, SSD1306_LCDHEIGHT - 2*i);
    SSD1306_Display();
    // delay(1);
  }
}
 
void testdrawline() {  
  for (int i = 0; i < SSD1306_LCDWIDTH; i += 4) {
    SSD1306_DrawLine(0, 0, i, SSD1306_LCDHEIGHT - 1, true);
    SSD1306_Display();
    // delay(1);
  }
  for (int i = 0; i < SSD1306_LCDHEIGHT; i += 4) {
    SSD1306_DrawLine(0, 0, SSD1306_LCDWIDTH - 1, i, true);
    SSD1306_Display();
    // delay(1);
  }
  delay(250);
  
  SSD1306_ClearDisplay();
  for (int i = 0; i < SSD1306_LCDWIDTH; i += 4) {
    SSD1306_DrawLine(0, SSD1306_LCDHEIGHT - 1, i, 0, true);
    SSD1306_Display();
    // delay(1);
  }
  for (int i = SSD1306_LCDHEIGHT - 1; i >= 0; i -= 4) {
    SSD1306_DrawLine(0, SSD1306_LCDHEIGHT - 1, SSD1306_LCDWIDTH - 1, i, true);
    SSD1306_Display();
    // delay(1);
  }
  delay(250);
  
  SSD1306_ClearDisplay();
  for (int i = SSD1306_LCDWIDTH - 1; i >= 0; i -= 4) {
    SSD1306_DrawLine(SSD1306_LCDWIDTH - 1, SSD1306_LCDHEIGHT - 1, i, 0, true);
    SSD1306_Display();
    // delay(1);
  }
  for (int i = SSD1306_LCDHEIGHT - 1; i >= 0; i -= 4) {
    SSD1306_DrawLine(SSD1306_LCDWIDTH - 1, SSD1306_LCDHEIGHT - 1, 0, i, true);
    SSD1306_Display();
    // delay(1);
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

int AN0_value;
int AN0_prev;
void ADC_Init(void)
{    
    TRISA = 0xFF;	/* Set as input port */
    ADCON1 = 0x0E;	/* Ref vtg is VDD and Configure pin as analog pin */
    ADCON2 = 0x92;	/* Right Justified, 4Tad and Fosc/32. */
    ADRESH=0;		/* Flush ADC output Register */
    ADRESL=0;   
}
int ADC_Read(int channel)
{
    int digital;

    /* Channel 0 is selected i.e.(CHS3CHS2CHS1CHS0=0000) & ADC is disabled */
    ADCON0 =(ADCON0 & 0b11000011)|((channel<<2) & 0b00111100);  
    
    ADCON0 |= ((1<<ADON)|(1<<GO));	/*Enable ADC and start conversion*/

    /* Wait for End of conversion i.e. Go/done'=0 conversion completed */
    while(ADCON0bits.GO_nDONE==1);

    digital = (ADRESH*256) | (ADRESL);	/*Combine 8-bit LSB and 2-bit MSB*/
    return(digital/10);
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
      
    SSD1306_Begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);
    blink();       
    delay(100);
//   
//    // draw many lines
//    blink();
//    testdrawline();
//    SSD1306_Display();
//    delay(2000);
//    SSD1306_ClearDisplay();
//
//    // draw rectangles
//    blink();
//    testdrawrect();
//    SSD1306_Display();
//    delay(2000);
//    SSD1306_ClearDisplay();
//
//    // draw multiple rectangles
//    blink();
//    testfillrect();
//    SSD1306_Display();
//    delay(2000);
//    SSD1306_ClearDisplay();
//
//    // draw mulitple circles
//    blink();
//    testdrawcircle();
//    SSD1306_Display();
//    delay(2000);
//    SSD1306_ClearDisplay();
//
//    // draw a white circle, 10 pixel radius
//    blink();
//    SSD1306_FillCircle(SSD1306_LCDWIDTH/2, SSD1306_LCDHEIGHT/2, 10, true);
//    SSD1306_Display();
//    delay(2000);
//    SSD1306_ClearDisplay();
//
//    
//    blink();
//    testdrawroundrect();
//    SSD1306_Display();
//    delay(2000);
//    SSD1306_ClearDisplay();
//
//    blink();
//    testfillroundrect();
//    SSD1306_Display();
//    delay(2000);
//    SSD1306_ClearDisplay();
//
//    blink();
//    testdrawtriangle();
//    SSD1306_Display();
//    delay(2000);
//    SSD1306_ClearDisplay();
//
//    blink();
//    testfilltriangle();
//    SSD1306_Display();
//    delay(2000);
//    SSD1306_ClearDisplay();
//
//    blink();
//    // draw scrolling text
//    testscrolltext();
//    SSD1306_Display();
//    delay(2000);
//    SSD1306_ClearDisplay();
//
//    blink();
//    // text display tests
//    char txt[9];
//    SSD1306_DrawText(2, 7, "Hello, world!", 1);
//
//    sprintf(txt, "%.6f", 3.141592);
//    SSD1306_DrawText(2, 16, txt, 1);
//
//    SSD1306_DrawText(2, 26, "0x", 2);
//
//    sprintf(txt, "%LX", 0xDEADBEEF);
//    SSD1306_DrawText(26, 26, txt, 2);
//    SSD1306_Display();
//    delay(2000);

    
    init_OLED();  
//     // prepare to read AN0 with ADC :
//     pinMode(PIN_RA0, INPUT);
    
     OLED_Draw_H_Line(0, 127, 0);
     delay(100);
     OLED_Draw_H_Line(0, 127, 8);
     delay(100);
 //    OLED_Draw_H_Line(0, 127, 16);
     OLED_Draw_H_Line(0, 127, 32);
     delay(100);
 //    OLED_Draw_H_Line(0, 127, 47);
     OLED_Draw_H_Line(0, 127, 55);
     delay(100);
     OLED_Draw_H_Line(0, 127, 63);
     delay(100);
 //    OLED_Draw_H_Line(0, 127, 2);
 //    OLED_Draw_H_Line(0, 127, 7);
 //    OLED_Draw_H_Line(0, 127, 8);
     OLED_Draw_V_Line(0, 0, 63);
     delay(100);
     OLED_Draw_V_Line(63, 0, 63);
     delay(100);
     OLED_Draw_V_Line(127, 0, 63);
     delay(100);
    
    /**
     * TEXT RENDERING TEST :
     * - 8 LINES at cost of 9 Pixels each.
     * - HEIGHT [0..9]
     * - WIDTH 5 
     */
//    OLED_Printf(" Hello World...Super Long "  ,0, 0);
//    delay(1);
//    OLED_Printf(" 01234567890 ~"  ,0, 9);
//    delay(1);
//    OLED_Printf(" QWERTYUIOP[]\\",0, 18);
//    delay(1);
//    OLED_Printf(" ASDFGHJKL:;  " ,0, 27);
//    delay(1);
//    OLED_Printf(" ZXCVBNM,./  "  ,0, 36);
//    delay(1);
//    OLED_Printf(" +-*/=!@#$%^&"  ,0, 45);
//    delay(1);
//    OLED_Printf(" NEWLINE "      ,0, 54);
//    delay(1);
    OLED_Printfi("        R E A D Y         "  ,0, 63);
    delay(100);
//    OLED_StartScrollRight(0x00, 0x0F);
//    delay(2000);
//    OLED_StopScroll();
//    delay(1000);
//    OLED_StartScrollLeft(0x00, 0x0F);
//    delay(2000);
//    OLED_StopScroll();
//    delay(1000);    
//    OLED_StartScrollDiagRight(0x00, 0x07);
//    delay(2000);
//    OLED_StartScrollDiagLeft(0x00, 0x07);
//    delay(2000);
//    OLED_StopScroll();

    ADC_Init();
    delay(10); //ms
    //Loop
    while(1) loop();
}

void blink(void){
    // Set pin RA0 as OUTPUT 
   pinMode(PIN_RA1, OUTPUT);
   
    digitalWrite(RA1, HIGH);
    delay(1);
    digitalWrite(RA1, LOW);
    delay(1);
}

char text_ADC[12];
bool wait_first = true;
bool is_cleared = false; // clear once :
/*==============================================================================
 * Loop routine
 *============================================================================*/
void loop(void) {
    delay(1);
    AN0_value = ADC_Read(0);
    if(wait_first && AN0_value!=0) {
        AN0_prev=AN0_value;
        wait_first = false; // done.
    }
    if(AN0_value!=AN0_prev){
        if(!is_cleared){
            OLED_ClearDisplay();
            is_cleared = true;
        }
        sprintf(text_ADC, "ADC = %d", AN0_value);
        OLED_Printf(text_ADC, 0, 36);
        OLED_Erase_H_Line(AN0_value, 102, 48);
        delay(1);
        OLED_Draw_H_Line(0, AN0_value, 48);
        AN0_prev = AN0_value;
        delay(16);
    }

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
   //Invert
//    OLED_InvertDisplay(invert);
//    invert++;
//    if(invert > 0x01) invert = 0x00;
}