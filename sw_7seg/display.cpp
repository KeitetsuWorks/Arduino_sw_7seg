/*
 * File:   display.cpp
 * Author: Keitetsu
 *
 * Created on 2015/02/22
 */

#include "stdafx.h"
#include "display.h"

/*
 * 7セグメントLED表示関数
 *
 * 引数:
 * byte font_id	表示するフォントのID
 *
 * 復帰値:
 * なし
 */
void display7seg(byte font_id)
{
	const byte font[11] = {
		// gfedcba	7セグメントLED 点灯パターン
		0b00111111,	// 0
		0b00000110,	// 1
		0b01011011,	// 2
		0b01001111,	// 3
		0b01100110,	// 4
		0b01101101,	// 5
		0b01111101,	// 6
		0b00100111,	// 7
		0b01111111,	// 8
		0b01101111,	// 9
		0b00000000	// 表示なし
	};
	
	PORTD = (PORTD & 0b00011111)	// 点灯パターン出力（出力ピン番号は不連続）
			| (font[font_id] << 5);
	PORTB = (PORTD & 0b11001100)
			| ((font[font_id] >> 3) & 0b00000011)
			| ((font[font_id] >> 1) & 0b00110000);
}
