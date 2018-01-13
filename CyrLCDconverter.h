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

#include <WString.h>

#define WIN1251 0
#define UTF8 1

String xConvertToCyrLCD (String xString, unsigned char ucCodepage);
static char cConvertToCyrLCD (unsigned char ucChar);
static String utf8rus(String source);

/*
//Recoding array (replaced by switch construction for memory saving)
const unsigned char aucCyrylic[256] = {
0x84, 0x85, 0x94, 0xff, 0x86, 0x87, 0xdb, 0xcf, // pseudographic
0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, // pseudographic
0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf, // pseudographic
0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, // pseudographic
0xef, 0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, // pseudographic
0xa2, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, // pseudographic
0xfe, 0xff, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, // pseudographic
0xb5, 0xee, 0xef, 0xf0, 0xf1, 0xf2, 0xfd, 0xff, // pseudographic
0x41, 0xa0, 0x42, 0xa1, 0xe0, 0x45, 0xa3, 0xa4, // АБВГДЕЖЗ
0xa5, 0xa6, 0x4b, 0xa7, 0x4d, 0x48, 0x4f, 0xa8, // ИЙКЛМНОП
0x50, 0x43, 0x54, 0xa9, 0xaa, 0x58, 0xe1, 0xab, // РСТУФХЦЧ
0xac, 0xe2, 0xad, 0xae, 0x62, 0xaf, 0xb0, 0xb1, // ШЩЪЫЬЭЮЯ
0x61, 0xb2, 0xb3, 0xb4, 0xe3, 0x65, 0xb6, 0xb7, // абвгдежз
0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0x6f, 0xbe, // ийклмноп
0x70, 0x63, 0xbf, 0x79, 0xe4, 0x78, 0xe5, 0xc0, // рстуфхцч
0xc1, 0xe6, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, // шщъыьэюя
};
*/
	