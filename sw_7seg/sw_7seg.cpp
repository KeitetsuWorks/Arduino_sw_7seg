/*
 * File:   sw_7seg.cpp
 * Author: Keitetsu
 *
 * Created on 2015/02/22
 */

#include "stdafx.h"
#include "display.h"

/*
 * ピンアサイン
 */
#define PIN_SW1 16

/*
 * グローバル変数
 */
byte count;

void setup()
{
	// 7セグメントLED PIN設定
	pinMode(2, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(12, OUTPUT);
	pinMode(13, OUTPUT);
	
	// SW PIN設定
	pinMode(PIN_SW1, INPUT_PULLUP);
	
	count = 0;
	display7seg(count);
}

void loop()
{
	byte sw1_state;
	static byte sw1_state_prev = HIGH;
	
	sw1_state = digitalRead(PIN_SW1);
	if(sw1_state == LOW){				// SW1が押下されている場合
		delay(10);						// 10ミリ秒の待ち時間
		sw1_state = digitalRead(PIN_SW1);
		if(sw1_state == LOW){			// SW1の状態を再確認（チャタリング対策）
			if(sw1_state_prev == HIGH){	// 前回，SW1が押下されていなかった場合
				count++;				// カウント値をインクリメント
			}
			sw1_state_prev = LOW;		// 今回のSW1の状態を記録
		}
		else{
			sw1_state_prev = HIGH;		// 今回のSW1の状態を記録
		}
	}
	else{								// SW1が押下されていない場合
		sw1_state_prev = HIGH;			// 今回のSW1の状態を記録
	}
	
	if(count > 9){						// 表示は10進数1桁
		count = 0;
	}
	display7seg(count);
}
