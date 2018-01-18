# CyrLCDconverter

A simple converter of cyrillic strings for HD44780 based LCD display.

**Attention! It can't synthesize new character patterns. Display must have hardware support of cyrillic symbols.**

Useful both for WIN1251 and UTF8 strings with cyrillic characters 
(in accordance with value of ucCodepage parameter). 
Latin characters remain unchanged.

The utility manipulates strings only, it does't contain any hardware-depended code for direct access to LCD display. 
You can use any driver for LCD display together with CyrLCDconverter. I recommend [LiquidCrystal library](https://bitbucket.org/fmalpartida/new-liquidcrystal/wiki/Home) by F. Malpartida.

### Example: 

```C++
#include <Wire.h> 

// https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads
#include "LiquidCrystal_I2C.h" 

#include "CyrLCDconverter.h"

// set the LCD address to 0x27 for a 20 chars 4 line display
// Set the pins on the I2C chip used for LCD connections:
//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address


void setup()   
{
	
	ConvertToCyrLCD converter = ConvertToCyrLCD(UTF8);
	
	lcd.begin(20,4); 

	lcd.backlight();	
	
	//Attention! Cyrillic strings may be corrupted by Arduino IDE.
	//Test this app in an external editor.
	
	lcd.setCursor(0,0);
	lcd.print(converter.convert (F("Быть или не быть?")));
	delay(500);	
	
	lcd.setCursor(0,1);
	lcd.print(converter.convert (F("Вот в чем вопрос?")));
	delay(500);  
	
	lcd.setCursor(0,2);
	lcd.print(converter.convert (F("To be or not to be?")));
	delay(500);	
	
	lcd.setCursor(0,3);
	lcd.print(converter.convert (F("That is the question")));
}

void loop()
{

}
```


