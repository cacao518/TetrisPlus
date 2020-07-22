#pragma once

#include "Base.h"

class Block {
private:
	Base base;
	int shape, angle, x, y;
	int ab_x, ab_y;
	int ab_x2, ab_y2;
	int ghost_x, ghost_y;      //���ɺ�� x��ǥ, y��ǥ
	int next_block_shape;
	int flag;   
	int m_blind;      
	int blind;
	int m_speedup;
	int speedup;
	int swit;
	int att_block;
	int c_value[21][14];		 //�Էµ��ֺ����� ���� �����ǵ�����Ҹ� �˷���
	int c_block[4][4];		 //����� ����������
	int c_angle;
	int c_x;
	int c_y;
public:
	Block();

	/**** Get �Լ� & Set �Լ� ****/
	int GetFlag();
	int GetMode();
	int GetBlind();
	int Getm_Blind();
	int GetSpeedup();
	int Getm_Speedup();
	int(*GetTotalBlock())[14];	//2���� �迭 �����ϴ� ���!**
	int GetSwit();
	int GetLevel();
	int GetLine();
	int GetCLine();
	int GetSpeed();
	int GetAtt_Block();

	void SetAtt_Block(int _att);
	void SetFlag(int _flag);   // 1P, 2P ��±���
	void SetMode(int _mode);   // 0: 1p���, 1: 2p���, 2: ��ǻ�͸��, 3: �ϵ���
	void SetBlind(int _blind);
	void Setm_Blind(int _blind);
	void SetSpeedup(int _speedup);
	void Setm_Speedup(int _speedup);
	void SetSwit(int _swit);

	/********	�⺻��� �Լ�	********/
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

	/*******	Ư�� ���		********/
	void ShowCombo(int _com);
	int pause();
	void ghost_block(int ch);
	void over_block();
	void clear_block();
	void Switch_Block(int(*arr)[14]);
	void show_inter();
	void attack_block(int num);
	int com(int is_gameover);	// ��ǻ�ͺ�� �̵�
	void c_direction();			// ��ǻ�Ϳ��� ������������ �˷���
	void copy_block(int ch);
};