#pragma once

class Base {
public:
	Base();
	int   speed;   //숫자가 낮을수록 속도가 빠르다
	int stick_rate;      //막대가 나오는 확률 0~99 , 99면 막대기만 나옴
	int clear_line;
	int level;
	int total_block[21][14];      //화면에 표시되는 블럭들 -1:벽, 7:빈공간, 1~6:여러쌓인블럭
	static int ghost; // 유령블록 on/off 변수

	int score;
	int lines;
	bool item[4];
	int game_mode;

};
