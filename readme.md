# CyrLCDconverter Arduino library

Converter of win1251 cyrillic for HD44780 based LCD display
Attention! Display must support cyrillic symbols

Useful both for WIN1251 and UTF8 strings with cyrillic symbols 
(in accordance with value of ucCodepage parameter). 
Latin symbols remain unchanged.

### Example for LiquidCrystal library: 

```c++
#include <Wire.h> 
#include "LiquidCrystal_I2C.h" 
#include "CyrLCDconverter.h"

// set the LCD address to 0x27 for a 20 chars 4 line display
// Set the pins on the I2C chip used for LCD connections:
//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

void setup()   
{
	lcd.begin(20,4);
	lcd.backlight();	
	
	//Attention! Cyrillic strings may be corrupted by Arduino IDE.
	//Test this app in an external editor.
	
	lcd.setCursor(0,0);
	lcd.print(xConvertToCyrLCD (F("Быть или не быть?"), WIN1251));
	delay(500);	
	
	lcd.setCursor(0,1);
	lcd.print(xConvertToCyrLCD (F("Р’РѕС‚ РІ С‡С‘Рј РІРѕРїСЂРѕСЃ"), UTF8));
	delay(500);  
	
	lcd.setCursor(0,2);
	lcd.print(F("To be or not to be?"));
	delay(500);	
	
	lcd.setCursor(0,3);
	lcd.print(F("That is the question"));
}

void loop()
{

}
```

For more info about LiquidCrystal library see:
https://bitbucket.org/fmalpartida/new-liquidcrystal/wiki/Home 

