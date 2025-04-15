/* 
 * File:   ssd1306.h
 * Author: thetrung
 *
 * Created on April 15, 2025, 5:05 PM
 */
#ifndef SSD1306_H
#define	SSD1306_H

#include "commons.h"
#include "I2CMaster.h"


//------------------------------ Definitions ---------------------------------//

#ifndef SSD1306_I2C_ADDRESS
  #define SSD1306_I2C_ADDRESS   0x3C
#endif

#if !defined SSD1306_128_32 && !defined SSD1306_96_16
#define SSD1306_128_64
#endif
#if defined SSD1306_128_32 && defined SSD1306_96_16
  #error "Only one SSD1306 display can be specified at once"
#endif

#if defined SSD1306_128_64
  #define SSD1306_LCDWIDTH            128
  #define SSD1306_LCDHEIGHT            64
#endif
#if defined SSD1306_128_32
  #define SSD1306_LCDWIDTH            128
  #define SSD1306_LCDHEIGHT            32
#endif
#if defined SSD1306_96_16
  #define SSD1306_LCDWIDTH             96
  #define SSD1306_LCDHEIGHT            16
#endif

#define SSD1306_SETCONTRAST          0x81
#define SSD1306_DISPLAYALLON_RESUME  0xA4
#define SSD1306_DISPLAYALLON         0xA5
#define SSD1306_NORMALDISPLAY        0xA6
#define SSD1306_INVERTDISPLAY_       0xA7
#define SSD1306_DISPLAYOFF           0xAE
#define SSD1306_DISPLAYON            0xAF
#define SSD1306_SETDISPLAYOFFSET     0xD3
#define SSD1306_SETCOMPINS           0xDA
#define SSD1306_SETVCOMDETECT        0xDB
#define SSD1306_SETDISPLAYCLOCKDIV   0xD5
#define SSD1306_SETPRECHARGE         0xD9
#define SSD1306_SETMULTIPLEX         0xA8
#define SSD1306_SETLOWCOLUMN         0x00
#define SSD1306_SETHIGHCOLUMN        0x10
#define SSD1306_SETSTARTLINE         0x40
#define SSD1306_MEMORYMODE           0x20
#define SSD1306_COLUMNADDR           0x21
#define SSD1306_PAGEADDR             0x22
#define SSD1306_COMSCANINC           0xC0
#define SSD1306_COMSCANDEC           0xC8
#define SSD1306_SEGREMAP             0xA0
#define SSD1306_CHARGEPUMP           0x8D
#define SSD1306_EXTERNALVCC          0x01
#define SSD1306_SWITCHCAPVCC         0x02

// Scrolling #defines
#define SSD1306_ACTIVATE_SCROLL                      0x2F
#define SSD1306_DEACTIVATE_SCROLL                    0x2E
#define SSD1306_SET_VERTICAL_SCROLL_AREA             0xA3
#define SSD1306_RIGHT_HORIZONTAL_SCROLL              0x26
#define SSD1306_LEFT_HORIZONTAL_SCROLL               0x27
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL  0x2A

#define ssd1306_swap(a, b) { i16 t = a; a = b; b = t; }

#define font Font
#define font2 Font2
#define bit_test(var, bit) (((var) & (1 << (bit)))!= 0)

u8 _i2caddr, _vccstate, x_pos, y_pos, text_size;
bool wrap = true;

void ssd1306_command(u8 c);
void SSD1306_Begin(u8 vccstate, u8 i2caddr);
void SSD1306_DrawPixel(u8 x, u8 y, bool color);
void SSD1306_StartScrollRight(u8 start, u8 stop);
void SSD1306_StartScrollLeft(u8 start, u8 stop);
void SSD1306_StartScrollDiagRight(u8 start, u8 stop);
void SSD1306_StartScrollDiagLeft(u8 start, u8 stop);
void SSD1306_StopScroll(void);
void SSD1306_Dim(bool dim);
void SSD1306_Display(void);
void SSD1306_ClearDisplay(void);
void SSD1306_DrawLine(i16 x0, i16 y0, i16 x1, i16 y1, bool color);
void SSD1306_DrawFastHLine(u8 x, u8 y, u8 w, bool color);
void SSD1306_DrawFastVLine(u8 x, u8 y, u8 h, bool color);
void SSD1306_FillRect(u8 x, u8 y, u8 w, u8 h, bool color);
void SSD1306_FillScreen(bool color);
void SSD1306_DrawCircle(i16 x0, i16 y0, i16 r);
void SSD1306_DrawCircleHelper(i16 x0, i16 y0, i16 r, u8 cornername);
void SSD1306_FillCircle(i16 x0, i16 y0, i16 r, bool color);
void SSD1306_FillCircleHelper(i16 x0, i16 y0, i16 r, u8 cornername, i16 delta, bool color);
void SSD1306_DrawRect(u8 x, u8 y, u8 w, u8 h);
void SSD1306_DrawRoundRect(u8 x, u8 y, u8 w, u8 h, u8 r);
void SSD1306_FillRoundRect(u8 x, u8 y, u8 w, u8 h, u8 r, bool color);
void SSD1306_DrawTriangle(u8 x0, u8 y0, u8 x1, u8 y1, u8 x2, u8 y2);
void SSD1306_FillTriangle(i16 x0, i16 y0, i16 x1, i16 y1, i16 x2, i16 y2, bool color);
void SSD1306_DrawChar(u8 x, u8 y, u8 c, u8 size);
void SSD1306_DrawText(u8 x, u8 y, char *_text, u8 size);
void SSD1306_TextSize(u8 t_size);
void SSD1306_GotoXY(u8 x, u8 y);
void SSD1306_Print(u8 c);
void SSD1306_PutCustomC(const u8 *c);
void SSD1306_SetTextWrap(bool w);
void SSD1306_InvertDisplay(bool i);
void SSD1306_DrawBMP(u8 x, u8 y, const u8 *bitmap, u8 w, u8 h);
#endif