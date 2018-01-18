/*
Vladimir Kirievskiy (C) 2018
********************************************************************************************
* @brief 
* Demo for CyrLCDconverter library
* 
* SDK:	Arduino IDE 1.8.5
*
********************************************************************************************
* @author V. Kirievskiy - vek2006_73@@mail.ru
* This software is furnished "as is", without technical support, and with no 
* warranty, express or implied, as to its usefulness for any purpose.
*/

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











