#pragma once

#include "Block.h"
#include "global.h"

using namespace std;

Block::Block() {

	ab_x = 5;         // 1p ������ǥ
	ab_y = 1;
	ab_x2 = 55;         // 2p ������ǥ
	ab_y2 = 1;
	flag = 0;         // 1p, 2p key�Է�& ȭ����ġ ����
	swit = 0;
}

int Block::GetFlag() { return flag; }
int Block::GetMode() { return base.game_mode; }
int Block::GetBlind() { return blind; }
int Block::Getm_Blind() { return m_blind; }
int Block::GetSpeedup() { return speedup; }
int Block::Getm_Speedup() { return m_speedup; }
int(*Block::GetTotalBlock())[14]{ return base.total_block; }		//////������ �迭 �����ϴ� �Լ�
int Block::GetSwit() { return swit; }
int Block::GetLevel() { return base.level; }
int Block::GetLine() { return base.lines; }
int Block::GetCLine() { return base.clear_line; }
int Block::GetSpeed() { return base.speed; }
int Block::GetAtt_Block() { return att_block; }
void Block::SetFlag(int _flag) { flag = _flag; };
void Block::SetMode(int _mode) { base.game_mode = _mode; };
void Block::SetBlind(int _blind) { blind = _blind; }
void Block::Setm_Blind(int _blind) { m_blind = _blind; }
void Block::SetSpeedup(int _speedup) { speedup = _speedup; }
void Block::Setm_Speedup(int _speedup) { m_speedup = _speedup; }
void Block::SetSwit(int _swit) { swit = _swit; }
void Block::SetAtt_Block(int _att) { att_block = _att; }
void Block::Init()
{
	int i, j;

	if (base.game_mode == 3)
		copy_block(1);
	else
		copy_block(0); // �����ϴ� �� ������ (1: �ϵ� �� 0: �⺻ ��)

	srand((unsigned)time(NULL));
	next_block_shape = -1; //// ���ӿ���������, next����� �������������� ù��° ����� �Ǵ°� ����
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 14; j++)
		{
			if ((j == 0) || (j == 13))
			{
				base.total_block[i][j] = -1;
			}
			else {
				base.total_block[i][j] = 7;
			}
		}
	}

	for (j = 0; j < 14; j++)         //ȭ���� ���� ���� ���� -1�� ä���.
		base.total_block[20][j] = -1;



	for (int i = 0; i < 4; i++)		// �����۹迭�ʱ�ȭ
		base.item[i] = 0;

	//�������� �ʱ�ȭ
	base.level = 0;
	base.lines = 0;
	blind = 0;
	m_blind = 0;
	speedup = 0;
	m_speedup = 0;
	att_block = 0;

	if (base.game_mode == 2) { // ��ǻ�ͺ��� �ʱ�ȭ
		c_x = 0;
		c_y = 0;
		c_angle = 0;
		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < 14; j++) {
				if (j == 0 || j == 13 || i == 20)
					c_value[i][j] = 10;
				else {
					if (base.total_block[i][j] == 7)
						c_value[i][j] = 0;
					else
						c_value[i][j] = 40;
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (block[shape][angle][i][j])
					c_block[i][j] = 20;
				else
					c_block[i][j] = 0;
			}
		}
	}

}
void Block::InitScore() { base.score = 0; }
void Block::Set(int _level, int _Cline)
{
	base.level = _level;
	base.speed = 40 - (_level * 2);

	base.stick_rate = 20 - (_level);
	base.clear_line = 5 + (_level * 3);
}
void Block::block_start() {
	ghost_x = x = 5;
	ghost_y = y = -1;
	angle = 0;
	if (next_block_shape < 0 || next_block_shape > 6)
		next_block_shape = make_new_block();
	shape = next_block_shape;
	next_block_shape = make_new_block();
	show_next_block();
	return;
}
int Block::make_new_block() {
	int i;
	i = rand() % 100;
	if (i <= base.stick_rate)      //����� ����Ȯ�� ���
		return 0;                     //����� ������� ����

	return (rand() % 6) + 1;      //shape���� 1~6�� ���� ��
}
int Block::show_next_block()
{
	int i, j;

	for (i = 1; i < 7; i++)
	{
		if (flag == 0)
		{
			SetColor(WHITE);
			gotoxy(34, 0);
			cout << "== NEXT ==";
			gotoxy(33, i);
		}
		else
		{
			SetColor(WHITE);
			gotoxy(84, 0);
			cout << "== NEXT ==";
			gotoxy(83, i);
		}
		for (j = 0; j < 6; j++)
		{
			if (i == 1 || i == 6 || j == 0 || j == 5)
			{
				SetColor((base.level + 1) % 6 + 1);
				cout << "��";
			}
			else {
				cout << "  ";
			}

		}
	}
	show_cur_block(next_block_shape, 0, 15, 1);
	return 0;
}
int Block::show_cur_block() {
	int po_x;
	int po_y;
	if (flag == 0) {
		po_x = ab_x;
		po_y = ab_y;
	}
	else {
		po_x = ab_x2;
		po_y = ab_y2;
	}
	if (m_blind == 0) {
		switch (shape) {
		case 0:
			SetColor(RED);
			break;
		case 1:
			SetColor(BLUE);
			break;
		case 2:
			SetColor(SKY_BLUE);
			break;
		case 3:
			SetColor(WHITE);
			break;
		case 4:
			SetColor(YELLOW);
			break;
		case 5:
			SetColor(VOILET);
			break;
		case 6:
			SetColor(GREEN);
			break;
		}

		ghost_block(0);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if ((j + y) < 0)
					continue;

				if (block[shape][angle][j][i] == 1) {
					gotoxy((i + x) * 2 + po_x, j + y + po_y);
					if (base.game_mode == 3)
						cout << "��";
					else
						cout << "��";
				}
			}
		}
	}
	SetColor(BLACK);
	gotoxy(77, 23);
	return 0;
}
int Block::show_cur_block(int next_shape, int next_angle, int next_x, int next_y) {

	int po_x;
	int po_y;
	if (flag == 0) {
		po_x = ab_x;
		po_y = ab_y;
	}
	else {
		po_x = ab_x2;
		po_y = ab_y2;
	}
	switch (next_shape) {
	case 0:
		SetColor(RED);
		break;
	case 1:
		SetColor(BLUE);
		break;
	case 2:
		SetColor(SKY_BLUE);
		break;
	case 3:
		SetColor(WHITE);
		break;
	case 4:
		SetColor(YELLOW);
		break;
	case 5:
		SetColor(VOILET);
		break;
	case 6:
		SetColor(GREEN);
		break;
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if ((j + next_y) < 0)
				continue;

			if (block[next_shape][next_angle][j][i] == 1) {
				gotoxy((i + next_x) * 2 + po_x, j + next_y + po_y);
				if (base.game_mode == 3)
					cout << "��";
				else
					cout << "��";
			}
		}
	}
	SetColor(BLACK);
	gotoxy(77, 23);
	return 0;
}
int Block::erase_cur_block() {
	int po_x;
	int po_y;
	if (flag == 0) {
		po_x = ab_x;
		po_y = ab_y;
	}
	else {
		po_x = ab_x2;
		po_y = ab_y2;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[shape][angle][j][i] == 1) {
				gotoxy((i + x) * 2 + po_x, j + y + po_y);
				cout << "  ";
			}
		}
	}
	SetColor(GRAY);
	gotoxy(2 + po_x, 2 + po_y);
	cout << "========================";

	ghost_block(1);
	return 0;
}
int Block::move_block() {

	int r_com = 0;
	erase_cur_block();
	y++;   //���� ��ĭ �Ʒ��� ����
	if (strike_check() == 1) {
		y--;
		r_com = merge_block();
		for (int i = 1; i < 13; i++) {
			if (base.total_block[2][i] != 7)   //���ӿ���
				return 1;
		}
		ShowCombo(r_com);	//�޺� �����ֱ�
		block_start();   //angle,x,y�� ��������
		return 2;
	}
	return 0;
}
int Block::key(int is_gameover, char keytemp) {    //1p�� Ű �Է�

	if (keytemp == EXT_KEY)
	{
		keytemp = _getch();
		switch (keytemp)
		{
		case KEY_UP:      //ȸ���ϱ�
			if (strike_check((angle + 1) % 4) == 0) {
				erase_cur_block();
				angle = (angle + 1) % 4;
				show_cur_block();
				break;
			}
			break;
		case KEY_LEFT:      //�������� �̵�
			if (x > 1)
			{
				erase_cur_block();
				x--;
				if (strike_check() == 1)
					x++;
				show_cur_block();
			}
			break;
		case KEY_RIGHT:      //���������� �̵�

			if (x < 14)
			{
				erase_cur_block();
				x++;
				if (strike_check() == 1)
					x--;
				show_cur_block();
			}
			break;
		case KEY_DOWN:      //�Ʒ��� �̵�
			is_gameover = move_block();
			show_cur_block();
			break;
		}
	}
	else if (keytemp == 32)   //�����̽��ٸ� ��������
	{
		while (is_gameover == 0)
		{
			is_gameover = move_block();
		}
		show_cur_block();
	}

	if (base.game_mode == 1 && ((keytemp >= '7' && keytemp <= '9') || keytemp == '0')) {
		switch (keytemp) {
		case '7':
			if (base.item[0] == 1) {
				clear_block();
				base.item[0] = 0;
			}
			break;
		case '8':
			if (base.item[1] == 1) {
				blind = 10;
				base.item[1] = 0;
			}
			break;
		case '9':
			if (base.item[2] == 1) {
				speedup = 20;
				base.item[2] = 0;
			}
			break;
		case '0':
			if (base.item[3] == 1) {
				swit = 1;
				base.item[3] = 0;
			}
			break;
		}
		show_gamestat();
	}
	return is_gameover;

}
int Block::key2(int is_gameover, char keytemp) {         //2p�� key�Է�


	switch (keytemp)
	{
	case 'r':      //ȸ���ϱ�

		if (strike_check((angle + 1) % 4) == 0) {
			erase_cur_block();
			angle = (angle + 1) % 4;
			show_cur_block();
			break;
		}
		break;
	case 'd':      //�������� �̵�
		if (x > 1)
		{
			erase_cur_block();
			x--;
			if (strike_check() == 1)
				x++;

			show_cur_block();
		}
		break;
	case 'g':      //���������� �̵�

		if (x < 14)
		{
			erase_cur_block();
			x++;
			if (strike_check() == 1)
				x--;
			show_cur_block();
		}
		break;
	case 'f':      //�Ʒ��� �̵�
		is_gameover = move_block();
		show_cur_block();
		fflush(stdin);
		break;


	}
	if (keytemp == 'z')   //�����̽��ٸ� ��������
	{
		while (is_gameover == 0)
		{
			is_gameover = move_block();
		}
		show_cur_block();
	}

	if (base.game_mode == 1 && (keytemp >= '1' && keytemp <= '4')) {
		switch (keytemp) {
		case '1':
			if (base.item[0] == 1) {
				clear_block();
				base.item[0] = 0;
			}
			break;
		case '2':
			if (base.item[1] == 1) {
				blind = 10;
				base.item[1] = 0;
			}
			break;
		case '3':
			if (base.item[2] == 1) {
				speedup = 20;
				base.item[2] = 0;
			}
			break;
		case '4':
			if (base.item[3] == 1) {
				swit = 1;
				base.item[3] = 0;
			}
			break;
		}
	}
	return is_gameover;

}
int Block::com(int is_gameover) {			//��ǻ�ʹ������
	c_direction();
	//ȸ���ϱ�
	if ((angle % 4) < (c_angle % 4)) {
		if (strike_check((angle + 1) % 4) == 0) {
			erase_cur_block();
			angle = (angle + 1) % 4;
			show_cur_block();
		}
	}
	//�������� �̵�
	else if (x > c_x) {
		if (x > 1) {
			erase_cur_block();
			x--;
			if (strike_check() == 1)
				x++;

			show_cur_block();
		}
	}
	//���������� �̵�
	else if (x < c_x) {
		if (x < 14)
		{
			erase_cur_block();
			x++;
			if (strike_check() == 1)
				x--;
			show_cur_block();
		}
	}

	else if (x == c_x && angle == c_angle) {
		while (is_gameover == 0) {
			is_gameover = move_block();
		}
		show_cur_block();
	}
	return is_gameover;
}
void Block::c_direction() {
	int temp_y = y;
	int temp_x = x;
	int temp_angle = angle;
	int path = 0;
	int cir = 1;

	for (angle = 0; angle < 4; angle++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (block[shape][angle][i][j])
					c_block[i][j] = 20;
				else
					c_block[i][j] = 0;
			}
		}
		for (x = 1; x < 13; x++) {
			cir = 1;
			y = temp_y;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (block[shape][angle][i][j]) {
						if (x + j >= 13)
							cir = 0;
					}
					if (cir == 0)
						break;
				}
			}
			if (cir == 0)
				continue;

			for (int i = 0; i < 21; i++) {
				for (int j = 0; j < 14; j++) {
					if (j == 0 || j == 13 || i == 20)
						c_value[i][j] = 10;
					else {
						if (base.total_block[i][j] == 7)
							c_value[i][j] = 0;
						else
							c_value[i][j] = 40;
					}
				}
			}
			while (!strike_check(angle)) {			// ����� ���Ƿ� ����
				y++;
			}
			y--;
			int temp_path = 0;
			int count = 0;
			int k;
			for (k = 0; k < 4; k++) {
				for (int j = 0; j < 4; j++) {
					if (block[shape][angle][k][j]) {
						c_value[y + k][x + j] += c_block[k][j];
						count++;
					}
				}
				if (count == 4)
					break;
			}
			for (int j = 0; j < 14; j++)
				temp_path += c_value[y + k][j];
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (c_block[i][j] == 20) {
						if (c_value[y + i + 1][x + j] == 0)
							temp_path -= 50;
					}
				}
			}
			if (temp_path > path) {
				c_x = x;
				c_y = y;
				c_angle = angle;
				path = temp_path;
			}
		}
	}
	x = temp_x;
	y = temp_y;
	angle = temp_angle;
}
int Block::merge_block()
{
	int i, j;
	int r_com; //�޺����� �����ϱ�����
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (base.total_block[y + i][x + j] == 7 && block[shape][angle][i][j] == 1) {
				base.total_block[y + i][x + j] = shape;
			}
		}
	}
	r_com = check_full_line();
	show_total_block();

	return r_com;
}
int Block::strike_check()
{
	int i, j;
	int block_dat;

	for (i = 0; i < 4; i++)
	{
		if ((y + i) < 0)
			continue;
		for (j = 0; j < 4; j++)
		{
			if (((x + j) == 0) || ((x + j) == 13))
				block_dat = 1;
			else {
				if (base.total_block[y + i][x + j] != 7)
					block_dat = 1;
				else
					block_dat = 0;
			}

			if ((block_dat == 1) && (block[shape][angle][i][j] == 1))                                                                     //�������� ��ǥ�� ��������
			{
				return 1;
			}
		}
	}
	return 0;
}
int Block::strike_check(int next_angle)
{
	int i, j;
	int block_dat;

	for (i = 0; i < 4; i++)
	{
		if ((y + i) < 0)
			continue;
		for (j = 0; j < 4; j++)
		{
			if (((x + j) == 0) || ((x + j) == 13))
				block_dat = 1;
			else {
				if (base.total_block[y + i][x + j] != 7)
					block_dat = 1;
				else
					block_dat = 0;
			}

			if ((block_dat == 1) && (block[shape][next_angle][i][j] == 1))                                                                     //�������� ��ǥ�� ��������
			{
				return 1;
			}
		}
	}
	return 0;
}
int Block::show_total_block()
{
	int po_x;
	int po_y;
	if (flag == 0) {
		po_x = ab_x;
		po_y = ab_y;
	}
	else {
		po_x = ab_x2;
		po_y = ab_y2;
	}
	int i, j;
	SetColor(DARK_GRAY);
	for (i = 0; i < 21; i++)
	{
		for (j = 0; j < 14; j++)
		{
			if (j == 0 || j == 13 || i == 20)      //������ ���� �ܺ� ���� ����
			{
				SetColor((base.level % 6) + 1);
				gotoxy((j * 2) + po_x, i + po_y);
				cout << "��";
			}
			else if (base.total_block[i][j] != 7)
			{
				switch (base.total_block[i][j]) {
				case 0:
					SetColor(RED);
					break;
				case 1:
					SetColor(BLUE);
					break;
				case 2:
					SetColor(SKY_BLUE);
					break;
				case 3:
					SetColor(WHITE);
					break;
				case 4:
					SetColor(YELLOW);
					break;
				case 5:
					SetColor(VOILET);
					break;
				case 6:
					SetColor(GREEN);
					break;
				case 8:
					SetColor(DARK_GRAY);
					break;
				}
				gotoxy((j * 2) + po_x, i + po_y);
				if (base.game_mode == 3)
					cout << "��";
				else
					cout << "��";
			}
			else if (i != 2) {
				gotoxy((j * 2) + po_x, i + po_y);
				cout << "  ";
			}
		}
	}
	SetColor(GRAY);
	gotoxy(2 + po_x, 2 + po_y);
	cout << "========================";

	SetColor(BLACK);
	gotoxy(77, 23);
	return 0;
}
int Block::check_full_line()
{
	int count = 0;
	int po_x;
	int po_y;
	if (flag == 0) {
		po_x = ab_x;
		po_y = ab_y;
	}
	else {
		po_x = ab_x2;
		po_y = ab_y2;
	}
	int i, j, k;
	for (i = 0; i < 20; i++)
	{
		for (j = 1; j < 13; j++)
		{
			if (base.total_block[i][j] == 7)
				break;
		}
		if (j == 13)   //������ �� ä������
		{
			count++; //�޺�����
			show_total_block();
			SetColor(RED);
			gotoxy(1 * 2 + po_x, i + po_y);
			cout << "�������������";
			Sleep(80);
			gotoxy(1 * 2 + po_x, i + po_y);
			cout << "�������������";
			Sleep(50);
			gotoxy(1 * 2 + po_x, i + po_y);
			cout << "                        ";
			for (k = i; k > 0; k--)
			{
				for (j = 1; j < 13; j++)
					base.total_block[k][j] = base.total_block[k - 1][j];
			}
			for (j = 1; j < 13; j++)
				base.total_block[0][j] = 7;



			if (base.game_mode == 1 || base.game_mode == 2)
				att_block++;
			else
			{
				base.score += 100 + (base.level + 1) * 10;
				base.lines += 1;
			}
		}

	}
	if (base.game_mode == 1) {
		if (count > 1)		//1���̻��� ����� �������� �������� (�޺�) 
		{
			int pos;
			//pos = 3;		
			pos = rand() % 4;		// ������ ������ ����
			base.item[pos] = 1;
		}
	}
	else
		if (count > 1)		//�޺� �߰�����
			base.score += 10 * count;

	show_gamestat();
	return count;	//�޺����� ����
}
int Block::show_gamestat()
{

	static int printed_text = 0;

	int alp = 0;
	if (flag == 1) {
		alp += 50;
		printed_text = 1;
	}
	if (base.game_mode == 0)
	{
		SetColor(WHITE);
		gotoxy(11, 23);
		cout << "�� Classic Mode ��";
	}
	if (base.game_mode == 1)
	{
		SetColor(WHITE);
		gotoxy(35, 23);
		cout << "�� 1P vs 2P Mode ��";

		gotoxy(15, 22);
		cout << "[  1P  ]";
		gotoxy(65, 22);
		cout << "[  2P  ]";

	}
	if (base.game_mode == 2)
	{
		SetColor(WHITE);
		gotoxy(35, 23);
		cout << "�� 1P vs Com Mode ��";

		gotoxy(15, 22);
		cout << "[  1P  ]";
		gotoxy(65, 22);
		cout << "[  Com  ]";
	}
	if (base.game_mode == 3)
	{
		SetColor(WHITE);
		gotoxy(11, 23);
		cout << "�� Extream Mode ��";
	}
	if (base.game_mode == 0 || base.game_mode == 3) {

		gotoxy(35 + alp, 7);
		cout << "STAGE";

		gotoxy(35 + alp, 9);
		cout << "SCORE";

		gotoxy(35 + alp, 12);
		cout << "LINES";

		gotoxy(41 + alp, 7);
		cout << base.level + 1;
		gotoxy(35 + alp, 10);
		cout << base.score;
		gotoxy(35 + alp, 13);
		cout << "  ";
		gotoxy(35 + alp, 13);
		cout << base.clear_line - base.lines;
	}
	if (base.game_mode == 1) {
		for (int i = 0; i < 4; i++) {
			if (base.item[i] == 1)
				SetColor(YELLOW);
			switch (i) {
			case 0:
				gotoxy(35 + alp, 10);
				cout << " �� CLEAR";
				if (flag == 0) {
					gotoxy(35 + alp, 10);
					cout << " ��";
				}
				break;
			case 1:
				gotoxy(35 + alp, 12);
				cout << " �� BLIND";
				if (flag == 0) {
					gotoxy(35 + alp, 12);
					cout << " ��";
				}
				break;
			case 2:
				gotoxy(35 + alp, 14);
				cout << " �� SPEEDUP";
				if (flag == 0) {
					gotoxy(35 + alp, 14);
					cout << " ��";
				}
				break;
			case 3:
				gotoxy(35 + alp, 16);
				cout << " �� SWITCH";
				if (flag == 0) {
					gotoxy(35 + alp, 16);
					cout << " ��";
				}
				break;
			}
			SetColor(GRAY);
		}
	}

	return 0;
}
void Block::ShowCombo(int _com)
{
	int alp = 0;
	if (flag == 1)
		alp += 50;

	if (_com > 1)
	{
		SetColor(YELLOW);
		gotoxy(35 + alp, 18);
		cout << _com << " Combo!!";
	}
	else
	{
		gotoxy(35 + alp, 18);
		cout << "             ";
	}
}
int Block::pause() {

	system("cls");
	SetColor(WHITE);
	for (int i = 1; i < 8; i++)
	{
		gotoxy(27, i + 7);
		for (int j = 0; j < 12; j++)
		{
			if (i == 1 || i == 7 || j == 0 || j == 11)
			{
				cout << "��";
			}
			else {
				cout << "  ";
			}
		}
	}
	gotoxy(34, 8);
	cout << " P A U S E";
	gotoxy(28, 16);
	cout << "��, �� : �̵� / SPACE : ����";
	char chtemp;
	int ch = 1;
	while (1)
	{
		if (ch == 1)
		{
			gotoxy(30, 10);
			cout << " �� �̾��ϱ�  ";
			gotoxy(30, 11);
			cout << "�� �ٽ��ϱ�  ";
			gotoxy(30, 12);
			cout << "�� �޴��� ���ư���";
		}
		else if (ch == 2)
		{
			gotoxy(30, 10);
			cout << "�� �̾��ϱ�  ";
			gotoxy(30, 11);
			cout << " �� �ٽ��ϱ�  ";
			gotoxy(30, 12);
			cout << "�� �޴��� ���ư���";
		}
		else if (ch == 3)
		{
			gotoxy(30, 10);
			cout << "�� �̾��ϱ�  ";
			gotoxy(30, 11);
			cout << "�� �ٽ��ϱ�  ";
			gotoxy(30, 12);
			cout << " �� �޴��� ���ư���";
		}
		chtemp = _getch();

		if (chtemp == 72)
		{
			if (ch == 2)
			{
				ch = 1;
				continue;
			}

			if (ch == 3)
			{
				ch = 2;
				continue;
			}
		}
		if (chtemp == 80)
		{
			if (ch == 1)
			{
				ch = 2;
				continue;
			}
			if (ch == 2)
			{
				ch = 3;
				continue;
			}
		}
		if (chtemp == 32)
		{
			break;
		}
	}
	system("cls");
	if (ch == 3)
		return 3;
	else if (ch == 2)
		return 2;
	show_gamestat();
	show_next_block();
	show_cur_block();
	show_total_block();
	return 0;
}
void Block::ghost_block(int ch) {
	int po_x;
	int po_y;
	if (flag == 0) {
		po_x = ab_x;
		po_y = ab_y;
	}
	else {
		po_x = ab_x2;
		po_y = ab_y2;
	}

	if (ch == 0) {
		int temp_y = y;
		ghost_y = y;
		ghost_x = x;
		while (!strike_check()) {
			ghost_y++;
			y++;
		}
		ghost_y--;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if ((j + ghost_y) < 0)
					continue;

				if (block[shape][angle][j][i] == 1) {
					gotoxy((i + ghost_x) * 2 + po_x, j + ghost_y + po_y);
					if (Base::ghost == 1) // �ɼǿ��� on �϶�
						cout << "��";
				}
			}
		}
		y = temp_y;
	}
	else if (ch == 1) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (block[shape][angle][j][i] == 1) {
					gotoxy((i + ghost_x) * 2 + po_x, j + ghost_y + po_y);
					cout << "  ";
					//break;
				}
			}
		}
	}
}
void Block::over_block() {
	int po_x;
	int po_y;
	if (flag == 0) {
		po_x = ab_x;
		po_y = ab_y;
	}
	else {
		po_x = ab_x2;
		po_y = ab_y2;
	}
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			if (base.total_block[i][j] != 7) {
				SetColor(GRAY);
				gotoxy((j * 2) + po_x, i + po_y);
				cout << "��";
			}
			else {
				gotoxy((j * 2) + po_x, i + po_y);
				cout << "  ";
			}
		}
		Sleep(30);
	}
	SetColor(BLACK);
	gotoxy(77, 23);
}
void Block::clear_block() {

	int po_x;
	int po_y;
	if (flag == 0) {
		po_x = ab_x;
		po_y = ab_y;
	}
	else {
		po_x = ab_x2;
		po_y = ab_y2;
	}

	for (int j = 1; j < 13; j++) {
		if (base.total_block[19][j] != 7) {
			SetColor(BLUE);
			gotoxy(j * 2 + po_x, 19 + po_y);
			cout << "��";
			Sleep(30);
		}
	}
	for (int k = 19; k > 0; k--) {
		for (int j = 1; j < 13; j++)
			base.total_block[k][j] = base.total_block[k - 1][j];
	}
	for (int j = 1; j < 13; j++)
		base.total_block[0][j] = 7;
	show_total_block();
}
void Block::Switch_Block(int(*arr)[14])
{
	int temp[21][14];

	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			temp[i][j] = base.total_block[i][j];		//��ȯ
			base.total_block[i][j] = arr[i][j];
			arr[i][j] = temp[i][j];
		}
	}
	//return temp2;		//_block�� total_block[][]�� �ȹٲ� -> �����ؼ� �ٽ� �Լ� ȣ��
}
void Block::show_inter()
{
	int alp = 0;
	if (flag == 1) {
		alp += 50;
	}

	if (base.game_mode == 1) {
		gotoxy(35 + alp, 8);
		SetColor(WHITE);
		cout << ":: ITEM ::";
		for (int i = 0; i < 9; i++)
		{
			gotoxy(33 + alp, 9 + i);
			SetColor(WHITE);
			cout << "��";
			gotoxy(47 + alp, 9 + i);
			SetColor(WHITE);
			cout << "��";
		}
	}
}
void Block::attack_block(int num) {
	for (int k = num; k > 0; k--) {
		for (int i = 0; i < 19; i++) {
			for (int j = 1; j < 13; j++) {
				base.total_block[i][j] = base.total_block[i + 1][j];
			}
		}
		for (int i = 1; i < 13; i++) {
			base.total_block[19][i] = 8;
		}
		for (int i = 0; i < 3; i++)
			base.total_block[19][rand() % 12 + 1] = 7;
	}
	ghost_y -= num;
	show_total_block();
}
void Block::copy_block(int ch) {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 4; l++) {
					block[i][j][k][l] = 0;
				}
			}
		}
	}
	if (ch == 0)
	{
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					for (int l = 0; l < 4; l++) {
						block[i][j][k][l] = a_block[i][j][k][l];
					}
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					for (int l = 0; l < 4; l++) {
						block[i][j][k][l] = h_block[i][j][k][l];
					}
				}
			}
		}
	}
}
