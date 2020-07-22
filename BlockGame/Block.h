#pragma once

#include "Base.h"

class Block {
private:
	Base base;
	int shape, angle, x, y;
	int ab_x, ab_y;
	int ab_x2, ab_y2;
	int ghost_x, ghost_y;      //유령블록 x좌표, y좌표
	int next_block_shape;
	int flag;   
	int m_blind;      
	int blind;
	int m_speedup;
	int speedup;
	int swit;
	int att_block;
	int c_value[21][14];		 //입력된주변값을 더해 최적의도착장소를 알려줌
	int c_block[4][4];		 //블록이 가진고유값
	int c_angle;
	int c_x;
	int c_y;
public:
	Block();

	/**** Get 함수 & Set 함수 ****/
	int GetFlag();
	int GetMode();
	int GetBlind();
	int Getm_Blind();
	int GetSpeedup();
	int Getm_Speedup();
	int(*GetTotalBlock())[14];	//2차원 배열 리턴하는 방법!**
	int GetSwit();
	int GetLevel();
	int GetLine();
	int GetCLine();
	int GetSpeed();
	int GetAtt_Block();

	void SetAtt_Block(int _att);
	void SetFlag(int _flag);   // 1P, 2P 출력구분
	void SetMode(int _mode);   // 0: 1p모드, 1: 2p모드, 2: 컴퓨터모드, 3: 하드모드
	void SetBlind(int _blind);
	void Setm_Blind(int _blind);
	void SetSpeedup(int _speedup);
	void Setm_Speedup(int _speedup);
	void SetSwit(int _swit);

	/********	기본기능 함수	********/
	void Init();
	void InitScore();
	void Set(int level, int Cline);

	void block_start();
	int make_new_block();
	int show_next_block();
	int show_cur_block();
	int show_cur_block(int next_shape, int next_angle, int next_x, int next_y);
	int erase_cur_block();
	int move_block();
	int key(int is_gameover, char keytemp);
	int key2(int is_gameover, char keytemp);

	int merge_block();
	int strike_check();
	int strike_check(int next_angle);
	int show_total_block();
	int check_full_line();
	int show_gamestat();

	/*******	특수 기능		********/
	void ShowCombo(int _com);
	int pause();
	void ghost_block(int ch);
	void over_block();
	void clear_block();
	void Switch_Block(int(*arr)[14]);
	void show_inter();
	void attack_block(int num);
	int com(int is_gameover);	// 컴퓨터블록 이동
	void c_direction();			// 컴퓨터에게 최종목적지를 알려줌
	void copy_block(int ch);
};