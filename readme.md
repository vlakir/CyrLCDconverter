# CyrLCDconverter Arduino library

Converter of win1251 cyrillic for HD44780 based LCD display
Attention! Display must support cyrillic symbols

Useful both for WIN1251 and UTF8 strings with cyrillic symbols 
(in accordance with value of ucCodepage parameter). 
Latin symbols remain unchanged.

The library manipulates strings only , it does't contain any hardware-depended code for direct access to LCD display. 
You can use any driver for LCD display together with CyrLCDconverter. I recommend [LiquidCrystal library](https://bitbucket.org/fmalpartida/new-liquidcrystal/wiki/Home) by F. Malpartida.

### Example for LiquidCrystal library: 

```Arduino
#include <Wire.h> 
#include "LiquidCrystal_I2C.h" 
#include "CyrLCDconverter.h"

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

