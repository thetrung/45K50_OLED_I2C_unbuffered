/*
 * 20190312.014
 * OLED 128x32
 *
 * File: OLED.c
 * Processor: PIC16F1825
 * Author: wizlab.it
 */

#include "OLED.h"

void OLED_Command(uint8_t c) {
    I2C_Master_Start();
    I2C_Master_Address(_OLED_ADDR, I2C_MODE_WRITE); //Send address
    I2C_Master_Write((uint8_t)0x00);          //Control byte, next is command
    I2C_Master_Write(c);                            //Command
    I2C_Master_Stop();
}

void OLED_Commands(const uint8_t *c, uint8_t n) {
    I2C_Master_Start();
    I2C_Master_Address(_OLED_ADDR, I2C_MODE_WRITE); //Send address
    I2C_Master_Write((uint8_t)0x00);          //Control byte, next are commands
    while(n--) {                                    //Loop in commands...
        I2C_Master_Write(*c);
        c++;
    }
    I2C_Master_Stop();
}

void OLED_SetPageAndColumnAddress(const uint8_t startPage, const uint8_t endPage, const uint8_t startColumn, const uint8_t endColumn) {
    /*
    uint8_t commands[] = {
        SSD1306_PAGEADDR,   //Set page address
        startPage,
        endPage,
        SSD1306_COLUMNADDR, //Set column address
        startColumn,
        endColumn
    };
    */
    uint8_t commands[6];
    commands[0] = SSD1306_PAGEADDR;
    commands[1] = startPage;
    commands[2] = endPage;
    commands[3] = SSD1306_COLUMNADDR;
    commands[4] = startColumn;
    commands[5] = endColumn;
    OLED_Commands(commands, sizeof(commands));
}

void OLED_Init(void) {
    const uint8_t commands[] = {
        SSD1306_DISPLAYOFF,             //Switch off display (0xAE)
        SSD1306_SETDISPLAYCLOCKDIV,     //Set Display Clock Divide (0xD5)
            0x80,                       //Clock divide is 0x80
        SSD1306_SETMULTIPLEX,           //Set Multiplex Ratio (0xA8)
            0x3F,                       //Fixed to 0x1F (32 lines)
        SSD1306_SETDISPLAYOFFSET,       //Set Display Offset (0xD3)
            0x00,                       //No offset (0x00)
        SSD1306_SETSTARTLINE,           //Set Display Start Line (0x40) as line 0 (0x00)
        SSD1306_CHARGEPUMP,             //Set Charge Pump (0x8D)
            0x14,                       //Enabled (0x14, internal VCC)
        SSD1306_MEMORYMODE,             //Memory Addressing Mode (0x20)
            0x01,                       //Vertical addressing mode (0x01)
        SSD1306_SEGREMAP,               //Segment Re-map (0xA0) as COL0=SEG0 (0x00)
        SSD1306_COMSCANINC,             //Scan Direction: from 0 to N (0xC0)
        SSD1306_SETCOMPINS,             //COM Pins (0xDA)
            0x12,                       //Sequential, disabled remap
        SSD1306_SETCONTRAST,            //Contrast Control (0x81)
            0x8F,                       //Contrast to 0x8F
        SSD1306_SETPRECHARGE,           //Pre-charge Period (0xD9)
            0xF1,                       //Period to 0xF1
        SSD1306_SETVCOMDETECT,          //VCOMH Deselect Level (0xDB)
            0x20,                       //Level to 0x20
        SSD1306_DISPLAYALLON_RESUME,    //Display based on RAM (0xA4)
        SSD1306_NORMALDISPLAY,          //Normal display (0xA6)
        SSD1306_DEACTIVATE_SCROLL,      //Deactivate scroll (0x2E)
        SSD1306_DISPLAYON               //Turn on display (0xAF)
    };
    OLED_Commands(commands, sizeof(commands));
    OLED_ClearDisplay();
}

void OLED_ClearDisplay(void) {
    OLED_SetPageAndColumnAddress(0x00, 0x07, 0x00, 0x7F);

    I2C_Master_Start();
    I2C_Master_Address(_OLED_ADDR, I2C_MODE_WRITE); //Send address
    I2C_Master_Write((uint8_t)0x40);          //Control byte, next are data
    for(uint16_t byte=0; byte<FRAMEBUFFER; byte++) {       //Send a blank image (all zeroes)
        I2C_Master_Write(0X00);
    }
    I2C_Master_Stop();
}

void OLED_InvertDisplay(uint8_t i) {
  OLED_Command((i == 0x01) ? SSD1306_INVERTDISPLAY : SSD1306_NORMALDISPLAY);
}

void OLED_DATA_WRITE(
    const uint8_t startPage, 
    const uint8_t endPage, 
    const uint8_t startColumn, 
    const uint8_t endColumn){
    OLED_SetPageAndColumnAddress(startPage, endPage, startColumn, endColumn);
    I2C_Master_Start();
    I2C_Master_Address(_OLED_ADDR, I2C_MODE_WRITE);     //Send address
    I2C_Master_Write((uint8_t)0x40);                    //Control byte, next are data
}

/*
 * The nature of frame-buffer display is overwritten continuously with values.
 */
void OLED_DrawBitmap(const uint8_t startPage, const uint8_t endPage, const uint8_t startColumn, const uint8_t endColumn, const uint8_t *bitmap, uint16_t bitmapSize) {
    
    OLED_DATA_WRITE(startPage, endPage, startColumn, endColumn);
    
    for(uint16_t byte=0; byte<bitmapSize; byte++) {     //Loop into bitmap data...
        I2C_Master_Write(*bitmap);
        bitmap++;
    }
    I2C_Master_Stop();
}

#define i8 uint8_t
#define i16 uint16_t

void OLED_DrawLine(
    const uint8_t x1, 
    const uint8_t y1, 
    const uint8_t x2, 
    const uint8_t y2){
    
}

/**
 * Draw a Rectangle directly to display :
 * - x ---> x + width 
 * - y ---> (y + height) % 8
 * @param 8-bit x 
 * @param 8-bit y
 * @param width
 * @param height
 */
void OLED_DrawRectangle(
    const i8 x, // 0..127
    const i8 y, // 0..63
    const i8 width, 
    const i8 height){
    const i8 page_start = y > 7 ? y % 8 : 0;
    const i8 page_end   = y + height > 7 ? (y + height) % 8 : 0; 
    
    OLED_SetPageAndColumnAddress(page_start, page_end, x, x + width);
    OLED_DATA_WRITE(page_start, page_end, x, x + width);
    
    const i8 page0 = 0b11111111; // pretend that we only fill 128x1
    I2C_Master_Write(page0);
    
    for(i8 _x = 0; _x < x + width-2; _x++){
        const i8 page = 0b10000001; // pretend that we only fill 128x1
        I2C_Master_Write(page);
    }
    
//    const i8 page = 0b11111111; // pretend that we only fill 128x1
    I2C_Master_Write(page0);
    
    I2C_Master_Stop();
}