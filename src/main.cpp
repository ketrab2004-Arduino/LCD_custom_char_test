#include <Arduino.h>
#include <LiquidCrystal.h>

#include "settings.h"

LiquidCrystal lcd = LiquidCrystal(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

void setup() {
    lcd.begin(LCD_COLS, LCD_ROWS);
}

uint8_t customChar[] = {
    0,0,0,0,0,0,0,0 // custom char with 0b00000 as default value for every row
};

uint8_t charIndex = 0; // what index to use for the current custom char
uint8_t col = 0; // current col to draw char at
uint8_t row = 0; // current row to draw char at

void loop() {
    lcd.createChar(charIndex, customChar); // create custom char (from previous loop())

    lcd.setCursor(col, row);
    lcd.write(charIndex); // write the created custom char

    for (uint8_t i = 0; i < 8; i++) {
        customChar[i]++; // increase every row of the custom char by 1
    }

    col++; // increase col by 1
    if (col > LCD_COLS) { // if col is beyond the max
        col = 0; // reset
        row++; // increase row by 1
        if (row > LCD_ROWS) { // if row is beyond the max
            row = 0; // reset it
        }
    }

    charIndex++; // increase char index
    if (charIndex > 7) { // if it's beyond the max
        charIndex = 0; // go back to 0
    }

    delay(100); // delay to easily see what is going on
}
