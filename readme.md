# CyrLCDconverter arduino library

Converter of win1251 cyrillic for HD44780 based LCD display
Attention! Display must support cyrillic symbols

Useful both for WIN1251 and UTF8 strings with cyrillic symbols 
(in accordance with value of ucCodepage parameter). 
Latin symbols remain unchanged.

### Example for LiquidCrystal library: 

```c++
lcd.print(xConvertToCyrLCD (F("Быть или not to be?")), WIN1251);
```

For more info about LiquidCrystal library see:
https://bitbucket.org/fmalpartida/new-liquidcrystal/wiki/Home 

