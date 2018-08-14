/*
Vladimir Kirievskiy (C) 2018
********************************************************************************************
* @brief 
* Converter of win1251 cyrillic for HD44780 based LCD display 
* 
* SDK:	Arduino IDE 1.8.5
*
********************************************************************************************
* @author V. Kirievskiy - vek2006_73@@mail.ru
* This software is furnished "as is", without technical support, and with no 
* warranty, express or implied, as to its usefulness for any purpose.
*/

#include "CyrLCDconverter.h" 

/*
 * @brief 
 * Class for converter of cyrillic strings for HD44780 based LCD display
 * Attention! Display must support cyrillic characters
 * 
 * @param	 ucCodepage	- 	codepage of original string: WIN1251 || UTF8
 */ 
ConvertToCyrLCD::ConvertToCyrLCD (byte ucCodepage)
{
	ConvertToCyrLCD::ucCodepage = ucCodepage;
}

/*
 * @brief 
 * Converter of cyrillic strings for HD44780 based LCD display
 * 
 * @param	 xString	- 	original string in win1251 codepage
 * @return string with translated cyrillic characters (latin characters remain unchanged)		
 */ 
String ConvertToCyrLCD::convert(String xString)
{
	if (ucCodepage == UTF8) {
		xString = utf8rus(xString);
	}	
	
	for (int i=0; i<xString.length(); i++) 
	{  
		if ((unsigned char) xString[i] > 0x7F) // cyrillic - recode
		{
			xString[i] = cConvertToCyrLCD( (unsigned char) xString[i]-0x80);
		} // latin - remain unchanged
	}		
	return xString;	
}

// Recode russian fonts from UTF-8 to Windows-1251
String ConvertToCyrLCD::utf8rus(String source)
{
  int i,k;
  String target;
  unsigned char n;
  char m[2] = { '0', '\0' };

  k = source.length(); i = 0;

  while (i < k) {
    n = source[i]; i++;

    if (n >= 0xC0) {
      switch (n) {
        case 0xD0: {
          n = source[i]; i++;
          if (n == 0x81) { n = 0xA8; break; }
          if (n >= 0x90 && n <= 0xBF) n = n + 0x30;
          break;
        }
        case 0xD1: {
          n = source[i]; i++;
          if (n == 0x91) { n = 0xB8; break; }
          if (n >= 0x80 && n <= 0x8F) n = n + 0x70;
          break;
        }
      }
    }
    m[0] = n; target = target + String(m);
  }
return target;
}

//Recoding array was replaced by switch construction for memory saving
char ConvertToCyrLCD::cConvertToCyrLCD (unsigned char ucChar) 
{
	unsigned char ucResult;
	switch (ucChar) {
		case 0: {ucResult = 0x84; break;}
		case 1: {ucResult = 0x85; break;}
		case 2: {ucResult = 0x94; break;}
		case 3: {ucResult = 0xff; break;}
		case 4: {ucResult = 0x86; break;}
		case 5: {ucResult = 0x87; break;}
		case 6: {ucResult = 0xdb; break;}
		case 7: {ucResult = 0xcf; break;}
		
		case 8: {ucResult = 0xd0; break;}
		case 9: {ucResult = 0xd1; break;}
		case 10: {ucResult = 0xd2; break;}
		case 11: {ucResult = 0xd3; break;}
		case 12: {ucResult = 0xd4; break;}
		case 13: {ucResult = 0xd5; break;}
		case 14: {ucResult = 0xd6; break;}
		case 15: {ucResult = 0xd7; break;}	

		case 16: {ucResult = 0xd8; break;}
		case 17: {ucResult = 0xd9; break;}
		case 18: {ucResult = 0xda; break;}
		case 19: {ucResult = 0xdb; break;}
		case 20: {ucResult = 0xdc; break;}
		case 21: {ucResult = 0xdd; break;}
		case 22: {ucResult = 0xde; break;}
		case 23: {ucResult = 0xdf; break;}

		case 24: {ucResult = 0xe7; break;}
		case 25: {ucResult = 0xe8; break;}
		case 26: {ucResult = 0xe9; break;}
		case 27: {ucResult = 0xea; break;}
		case 28: {ucResult = 0xeb; break;}
		case 29: {ucResult = 0xec; break;}
		case 30: {ucResult = 0xed; break;}
		case 31: {ucResult = 0xee; break;}
		
		case 32: {ucResult = 0xef; break;}
		case 33: {ucResult = 0xf0; break;}
		case 34: {ucResult = 0xf1; break;}
		case 35: {ucResult = 0xf2; break;}
		case 36: {ucResult = 0xf3; break;}
		case 37: {ucResult = 0xf4; break;}
		case 38: {ucResult = 0xf5; break;}
		case 39: {ucResult = 0xf6; break;}
		
		case 40: {ucResult = 0xa2; break;}
		case 41: {ucResult = 0xf7; break;}
		case 42: {ucResult = 0xf8; break;}
		case 43: {ucResult = 0xf9; break;}
		case 44: {ucResult = 0xfa; break;}
		case 45: {ucResult = 0xfb; break;}
		case 46: {ucResult = 0xfc; break;}
		case 47: {ucResult = 0xfd; break;}

		case 48: {ucResult = 0xfe; break;}
		case 49: {ucResult = 0xff; break;}
		case 50: {ucResult = 0xe7; break;}
		case 51: {ucResult = 0xe8; break;}
		case 52: {ucResult = 0xe9; break;}
		case 53: {ucResult = 0xea; break;}
		case 54: {ucResult = 0xeb; break;}
		case 55: {ucResult = 0xec; break;}
	
		case 56: {ucResult = 0xb5; break;}
		case 57: {ucResult = 0xee; break;}
		case 58: {ucResult = 0xef; break;}
		case 59: {ucResult = 0xf0; break;}
		case 60: {ucResult = 0xf1; break;}
		case 61: {ucResult = 0xf2; break;}
		case 62: {ucResult = 0xfd; break;}
		case 63: {ucResult = 0xff; break;}
		
		case 64: {ucResult = 0x41; break;}
		case 65: {ucResult = 0xa0; break;}
		case 66: {ucResult = 0x42; break;}
		case 67: {ucResult = 0xa1; break;}
		case 68: {ucResult = 0xe0; break;}
		case 69: {ucResult = 0x45; break;}
		case 70: {ucResult = 0xa3; break;}
		case 71: {ucResult = 0xa4; break;}
		
		case 72: {ucResult = 0xa5; break;}
		case 73: {ucResult = 0xa6; break;}
		case 74: {ucResult = 0x4b; break;}
		case 75: {ucResult = 0xa7; break;}
		case 76: {ucResult = 0x4d; break;}
		case 77: {ucResult = 0x48; break;}
		case 78: {ucResult = 0x4f; break;}
		case 79: {ucResult = 0xa8; break;}
		
		case 80: {ucResult = 0x50; break;}
		case 81: {ucResult = 0x43; break;}
		case 82: {ucResult = 0x54; break;}
		case 83: {ucResult = 0xa9; break;}
		case 84: {ucResult = 0xaa; break;}
		case 85: {ucResult = 0x58; break;}
		case 86: {ucResult = 0xe1; break;}
		case 87: {ucResult = 0xab; break;}
		
		case 88: {ucResult = 0xac; break;}
		case 89: {ucResult = 0xe2; break;}
		case 90: {ucResult = 0xad; break;}
		case 91: {ucResult = 0xae; break;}
		case 92: {ucResult = 0x62; break;}
		case 93: {ucResult = 0xaf; break;}
		case 94: {ucResult = 0xb0; break;}
		case 95: {ucResult = 0xb1; break;}
		
		case 96: {ucResult = 0x61; break;}
		case 97: {ucResult = 0xb2; break;}
		case 98: {ucResult = 0xb3; break;}
		case 99: {ucResult = 0xb4; break;}
		case 100: {ucResult = 0xe3; break;}
		case 101: {ucResult = 0x65; break;}
		case 102: {ucResult = 0xb6; break;}
		case 103: {ucResult = 0xb7; break;}
	
		case 104: {ucResult = 0xb8; break;}
		case 105: {ucResult = 0xb9; break;}
		case 106: {ucResult = 0xba; break;}
		case 107: {ucResult = 0xbb; break;}
		case 108: {ucResult = 0xbc; break;}
		case 109: {ucResult = 0xbd; break;}
		case 110: {ucResult = 0x6f; break;}
		case 111: {ucResult = 0xbe; break;}
		
		case 112: {ucResult = 0x70; break;}
		case 113: {ucResult = 0x63; break;}
		case 114: {ucResult = 0xbf; break;}
		case 115: {ucResult = 0x79; break;}
		case 116: {ucResult = 0xe4; break;}
		case 117: {ucResult = 0x78; break;}
		case 118: {ucResult = 0xe5; break;}
		case 119: {ucResult = 0xc0; break;}
		
		case 120: {ucResult = 0xc1; break;}
		case 121: {ucResult = 0xe6; break;}
		case 122: {ucResult = 0xc2; break;}
		case 123: {ucResult = 0xc3; break;}
		case 124: {ucResult = 0xc4; break;}
		case 125: {ucResult = 0xc5; break;}
		case 126: {ucResult = 0xc6; break;}
		case 127: {ucResult = 0xc7; break;} // "я"		
		default: ucResult = 0x00; 			
	}
	return ucResult;
}
 
 
 
