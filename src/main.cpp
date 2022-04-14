#include <Arduino.h>
#include <LiquidCrystal.h>

#include "settings.h"

LiquidCrystal lcd = LiquidCrystal(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

void setup() {
    lcd.begin(LCD_COLS, LCD_ROWS);
}

uint8_t customChar[] = { // custom char with 0b00000 as default value for every row
    0,0,0,0,0,0,0,0
};

uint8_t charIndex = 0;
uint8_t col = 0; // current col to draw char at
uint8_t row = 0; // current row to draw char at

void loop() {
    lcd.createChar(charIndex, customChar);

    for (uint8_t i = 0; i < 8; i++) {
        customChar[i]++;
    }

    lcd.setCursor(col, row);
    lcd.write(charIndex);

    col++;

    if (col > LCD_COLS) {
        col = 0;
        row++;
        if (row > LCD_ROWS) {
            row = 0;
        }
    }

    charIndex++;
    if (charIndex > 7) {
        charIndex = 0;
    }

    delay(100);
}