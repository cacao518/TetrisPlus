#pragma once

#include "Action.h"
#include "global.h"

using namespace std;

int Action::show_logo(Block block)
{
	block.copy_block(0);

	for (int i = 1; i < 27; i++)
	{
		gotoxy(11, i);
		cout << "��";
		gotoxy(74, i);
		cout << "��";
		Sleep(20);
	}

	gotoxy(15, 5);
	cout << "������������������������������������������������������������������������������������������������";
	Sleep(30);
	gotoxy(15, 6);
	cout << "���ǢǢ�  �ǢǢ�  �ǢǢ�   �Ǣ�     ��   �ǢǢ� ��";
	Sleep(30);
	gotoxy(15, 7);
	cout << "��  ��    ��        ��     �� ��    ��   ��     ��";
	Sleep(30);
	gotoxy(15, 8);
	cout << "��  ��    �ǢǢ�    ��     �Ȣ�     ��   �ǢǢ� ��   ��";
	Sleep(30);
	gotoxy(15, 9);
	cout << "��  ��    ��        ��     �� ��    ��       �� �� �ˢˢ�";
	Sleep(30);
	gotoxy(15, 10);
	cout << "��  ��    �ǢǢ�    ��     ��  ��   ��   �ǢǢ� ��   ��";
	Sleep(30);
	gotoxy(15, 11);
	cout << "������������������������������������������������������������������������������������������������";
	Sleep(50);
	SetColor(GRAY);
	gotoxy(15, 12);
	cout << "      :: Konkuk univ. Computer Engineering ::";

	return 0;
}
void Action::ShowMenu(int* menu)
{
	Block _block;
	_block.copy_block(0);

	SetColor(GRAY);

	for (int i = 0; i < 14; i++)
	{
		gotoxy(28 + (i * 2), 16);
		cout << "��";
		gotoxy(54 - (i * 2), 25);
		cout << "��";
		Sleep(20);
	}
	SetColor(WHITE);
	gotoxy(30, 18);
	cout << "�� ��  Classic ���  ��";
	Sleep(40);
	gotoxy(30, 19);
	cout << "�� �� 1P vs 2P  ��� �� ";
	Sleep(40);
	gotoxy(30, 20);
	cout << "�� �� 1P vs Com ��� ��";
	Sleep(40);
	gotoxy(30, 21);
	cout << "�� ��  Extream ���  ��";
	Sleep(40);
	gotoxy(30, 22);
	cout << "�� ��     ��  ��     ��";
	Sleep(40);
	gotoxy(30, 23);
	cout << "�� ��     ��  ��     ��";
	Sleep(50);

	for (int i = 0; i >= 0; i++)
	{
		if (i % 40 == 0)
		{
			for (int j = 0; j < 25; j++)
			{
				gotoxy(0, 4 + j);
				cout << "          ";
				gotoxy(76, 4 + j);
				cout << "         ";
			}
			_block.show_cur_block(rand() % 7, rand() % 4, -1, 4);
			_block.show_cur_block(rand() % 7, rand() % 4, -1, 10);
			_block.show_cur_block(rand() % 7, rand() % 4, -1, 16);
			_block.show_cur_block(rand() % 7, rand() % 4, -1, 22);
			_block.show_cur_block(rand() % 7, rand() % 4, 36, 4);
			_block.show_cur_block(rand() % 7, rand() % 4, 36, 10);
			_block.show_cur_block(rand() % 7, rand() % 4, 36, 16);
			_block.show_cur_block(rand() % 7, rand() % 4, 36, 22);
			break;
		}
	}

	SetColor(WHITE);
	gotoxy(28, 26);
	cout << "��, �� : �̵� / SPACE : ����";
	char chtemp;
	*menu = 0;

	while (1)
	{
		if (*menu == 0)
		{
			SetColor(SKY_BLUE);
			gotoxy(30, 18);
			cout << " �� ��  Classic ���  ��";
			SetColor(WHITE);
			gotoxy(30, 19);
			cout << "�� �� 1P vs 2P  ��� �� ";
			gotoxy(30, 20);
			cout << "�� �� 1P vs Com ��� ��";
			gotoxy(30, 21);
			cout << "�� ��  Extream ���  ��";
			gotoxy(30, 22);
			cout << "�� ��     ��  ��     ��";
			gotoxy(30, 23);
			cout << "�� ��     ��  ��     ��";
		}
		else if (*menu == 1)
		{
			gotoxy(30, 18);
			cout << "�� ��  Classic ���  ��";
			SetColor(SKY_BLUE);
			gotoxy(30, 19);
			cout << " �� �� 1P vs 2P  ��� �� ";
			SetColor(WHITE);
			gotoxy(30, 20);
			cout << "�� �� 1P vs Com ��� ��";
			gotoxy(30, 21);
			cout << "�� ��  Extream ���  ��";
			gotoxy(30, 22);
			cout << "�� ��     ��  ��     ��";
			gotoxy(30, 23);
			cout << "�� ��     ��  ��     ��";
		}
		else if (*menu == 2)
		{
			gotoxy(30, 18);
			cout << "�� ��  Classic ���  ��";
			gotoxy(30, 19);
			cout << "�� �� 1P vs 2P  ��� �� ";
			SetColor(SKY_BLUE);
			gotoxy(30, 20);
			cout << " �� �� 1P vs Com ��� ��";
			SetColor(WHITE);
			gotoxy(30, 21);
			cout << "�� ��  Extream ���  ��";
			gotoxy(30, 22);
			cout << "�� ��     ��  ��     ��";
			gotoxy(30, 23);
			cout << "�� ��     ��  ��     ��";
		}
		else if (*menu == 3)
		{
			gotoxy(30, 18);
			cout << "�� ��  Classic ���  ��";
			gotoxy(30, 19);
			cout << "�� �� 1P vs 2P  ��� �� ";
			gotoxy(30, 20);
			cout << "�� �� 1P vs Com ��� ��";
			SetColor(SKY_BLUE);
			gotoxy(30, 21);
			cout << " �� ��  Extream ���  ��";
			SetColor(WHITE);
			gotoxy(30, 22);
			cout << "�� ��     ��  ��     ��";
			gotoxy(30, 23);
			cout << "�� ��     ��  ��     ��";
		}
		else if (*menu == 4)
		{
			gotoxy(30, 18);
			cout << "�� ��  Classic ���  ��";
			gotoxy(30, 19);
			cout << "�� �� 1P vs 2P  ��� �� ";
			gotoxy(30, 20);
			cout << "�� �� 1P vs Com ��� ��";
			gotoxy(30, 21);
			cout << "�� ��  Extream ���  ��";
			SetColor(SKY_BLUE);
			gotoxy(30, 22);
			cout << " �� ��     ��  ��     ��";
			SetColor(WHITE);
			gotoxy(30, 23);
			cout << "�� ��     ��  ��     ��";
		}
		else if (*menu == 5)
		{
			gotoxy(30, 18);
			cout << "�� ��  Classic ���  ��";
			gotoxy(30, 19);
			cout << "�� �� 1P vs 2P  ��� �� ";
			gotoxy(30, 20);
			cout << "�� �� 1P vs Com ��� ��";
			gotoxy(30, 21);
			cout << "�� ��  Extream ���  ��";
			gotoxy(30, 22);
			cout << "�� ��     ��  ��     ��";
			SetColor(SKY_BLUE);
			gotoxy(30, 23);
			cout << " �� ��     ��  ��     ��";
			SetColor(WHITE);
		}
		chtemp = _getch();
		if (chtemp == 72)
		{
			if (*menu == 1)
			{
				*menu = 0;
				continue;
			}
			if (*menu == 2)
			{
				*menu = 1;
				continue;

			}
			if (*menu == 3)
			{
				*menu = 2;
				continue;
			}
			if (*menu == 4)
			{
				*menu = 3;
				continue;
			}
			if (*menu == 5)
			{
				*menu = 4;
				continue;

			}
		}
		if (chtemp == 80)
		{
			if (*menu == 0)
			{
				*menu = 1;
				continue;
			}
			if (*menu == 1)
			{
				*menu = 2;
				continue;

			}
			if (*menu == 2)
			{
				*menu = 3;
				continue;

			}
			if (*menu == 3)
			{
				*menu = 4;
				continue;
			}
			if (*menu == 4)
			{
				*menu = 5;
				continue;
			}
		}
		if (chtemp == 32)
		{
			system("cls");
			return;
		}

	}
}
void Action::GameManager(int* menu)
{
	if (*menu == 0)
	{
		Play1(); // 1p ���
	}
	if (*menu == 1)
	{
		Play1Play2(); // 1p vs 2p ���
	}
	if (*menu == 2)
	{
		Play1Com2(); // 1p vs com ���
	}
	if (*menu == 3)
	{
		HardPlay1(); // �ϵ� ���
	}
	if (*menu == 4)
	{
		Option(); // ����
	}
	if (*menu == 5)
	{
		system("cls");
	}
}
void Action::Option()
{
	int menu = 0;
	char chtemp;
	for (int i = 0; i < 14; i++)
	{
		gotoxy(28 + (i * 2), 5);
		cout << "��";
		gotoxy(54 - (i * 2), 11);
		cout << "��";
		Sleep(20);
	}

	SetColor(WHITE);
	gotoxy(33, 4);
	cout << "   ::: Option :::";

	gotoxy(29, 13);
	cout << "��, �� : �̵� / SPACE : ����";

	while (1)
	{
		if (menu == 0)
		{
			SetColor(YELLOW);
			gotoxy(30, 7);
			cout << " �� ���� ��� ǥ�� [ ON ]  ";
			SetColor(WHITE);
			gotoxy(30, 8);
			cout << "�� ���� ��� ǥ�� [ OFF ] ";
			gotoxy(30, 9);
			cout << "�� �޴��� ���ư���";
		}
		else if (menu == 1)
		{
			gotoxy(30, 7);
			cout << "�� ���� ��� ǥ�� [ ON ]  ";
			SetColor(YELLOW);
			gotoxy(30, 8);
			cout << " �� ���� ��� ǥ�� [ OFF ] ";
			SetColor(WHITE);
			gotoxy(30, 9);
			cout << "�� �޴��� ���ư���";
		}
		else if (menu == 2)
		{
			gotoxy(30, 7);
			cout << "�� ���� ��� ǥ�� [ ON ]  ";
			gotoxy(30, 8);
			cout << "�� ���� ��� ǥ�� [ OFF ] ";
			SetColor(YELLOW);
			gotoxy(30, 9);
			cout << " �� �޴��� ���ư���";
			SetColor(WHITE);
		}
		chtemp = _getch();
		if (chtemp == 72)
		{
			if (menu == 1)
			{
				menu = 0;
				continue;
			}
			if (menu == 2)
			{
				menu = 1;
				continue;
			}
		}
		if (chtemp == 80)
		{
			if (menu == 0)
			{
				menu = 1;
				continue;
			}
			if (menu == 1)
			{
				menu = 2;
				continue;
			}
		}
		if (menu == 2 && chtemp == 32)
		{
			system("cls");
			return;
		}
		if (menu == 0 && chtemp == 32)
		{
			Base::ghost = 1;
			system("cls");
			return;
		}
		if (menu == 1 && chtemp == 32)
		{
			Base::ghost = 0;
			system("cls");
			return;
		}
	}
}
int Action::input_data(int mode)
{
	int r_level = 0;
	char chtemp;
	fflush(stdin);
	SetColor(GRAY);

	for (int i = 0; i < 14; i++)
	{
		gotoxy(28 + (i * 2), 5);
		cout << "��";
		gotoxy(54 - (i * 2), 16);
		cout << "��";
		Sleep(20);
	}

	SetColor(WHITE);
	gotoxy(33, 4);
	cout << "::: Stage Select :::";

	gotoxy(30, 17);
	cout << "��, �� : �̵� / SPACE : ����";

	if (mode == 0)
	{
		SetColor(SKY_BLUE);
		gotoxy(33, 2);
		cout << "�� Classic Mode ��";
	}
	if (mode == 3)
	{
		SetColor(RED);
		gotoxy(33, 2);
		cout << "�� Extream Mode ��";
	}
	while (1)
	{
		for (int j = 0; j < 8; j++)
		{
			SetColor(WHITE);
			gotoxy(35, 7 + j);
			cout << "��   Stage   " << j + 1 << " ";
			if (r_level == j)
			{
				SetColor(YELLOW);
				gotoxy(35, 7 + j);
				cout << " ��  Stage   " << j + 1 << " ";
				SetColor(WHITE);
			}
		}
		chtemp = _getch();
		if (chtemp == 72)
		{
			if (r_level == 1)
			{
				r_level = 0;
				continue;
			}
			if (r_level == 2)
			{
				r_level = 1;
				continue;

			}
			if (r_level == 3)
			{
				r_level = 2;
				continue;
			}
			if (r_level == 4)
			{
				r_level = 3;
				continue;
			}
			if (r_level == 5)
			{
				r_level = 4;
				continue;
			}
			if (r_level == 6)
			{
				r_level = 5;
				continue;
			}
			if (r_level == 7)
			{
				r_level = 6;
				continue;
			}
		}
		if (chtemp == 80)
		{
			if (r_level == 0)
			{
				r_level = 1;
				continue;
			}
			if (r_level == 1)
			{
				r_level = 2;
				continue;
			}
			if (r_level == 2)
			{
				r_level = 3;
				continue;
			}
			if (r_level == 3)
			{
				r_level = 4;
				continue;
			}
			if (r_level == 4)
			{
				r_level = 5;
				continue;
			}
			if (r_level == 5)
			{
				r_level = 6;
				continue;
			}
			if (r_level == 6)
			{
				r_level = 7;
				continue;
			}
		}
		if (chtemp == 32)
		{
			break;
		}
	}

	system("cls");
	return r_level;
}
int Action::show_gameover(Block block) {

	int alp = 0;

	if (block.GetFlag() != 0)
		alp += 50;

	block.over_block();
	SetColor(RED);
	gotoxy(15 + alp, 8);
	cout << "������������������������������";
	gotoxy(15 + alp, 9);
	cout << "��**************************��";
	gotoxy(15 + alp, 10);
	cout << "��*        GAME OVER       *��";
	gotoxy(15 + alp, 11);
	cout << "��**************************��";
	gotoxy(15 + alp, 12);
	cout << "������������������������������";
	fflush(stdin);
	Sleep(1000);
	_getch();
	system("cls");

	return 0;
}
void Action::opening()
{
	Block a;
	show_logo(a);
}
void Action::Play1()
{
	Block block;

	int level;
	int i;
	int is_gameover = 0;
	int finish = 0;

	block.SetMode(0);
	block.Init();

	while (1)
	{
		level = input_data(0);
		block.Set(level, 5);

		block.show_total_block();
		block.block_start();
		block.show_gamestat();
		is_gameover = 0;
		finish = 0;

		for (i = 1; i >= 1; i++)
		{
			if (_kbhit())
			{
				char key = _getch();
				if (key == 27) {
					finish = block.pause();
					if (finish != 0)   // finish == 0 �̸� ����ϱ�
						break;
				}
				else
					is_gameover = block.key(is_gameover, key);      //key�Լ�
			}
			else if (i % (block.GetSpeed()) == 0)
			{
				is_gameover = block.move_block();
				block.show_cur_block();
			}

			if (block.GetCLine() <= block.GetLine())   //Ŭ���� ��������
			{
				level = block.GetLevel();
				block.Init();
				block.Set(level + 1, 5);
				block.show_total_block();
				block.show_gamestat();
				block.block_start();

			}
			if (is_gameover == 1)
			{
				show_gameover(block);
				block.InitScore();
				SetColor(GRAY);
				break;
			}

			gotoxy(77, 23);
			Sleep(15);
			gotoxy(77, 23);
		}
		if (finish == 3)
			break;
		block.Init();
		block.InitScore();
	}
	return;
}
void Action::HardPlay1()
{
	Block block;

	int level;
	int i;
	int is_gameover = 0;
	int finish = 0;

	block.SetMode(3);
	block.Init();

	while (1)
	{
		level = input_data(3);
		block.Set(level, 5);

		block.show_total_block();
		block.block_start();
		block.show_gamestat();
		is_gameover = 0;
		finish = 0;

		for (i = 1; i >= 1; i++)
		{
			if (_kbhit())
			{
				char key = _getch();
				if (key == 27) {
					finish = block.pause();
					if (finish != 0)   // finish == 0 �̸� ����ϱ�
						break;
				}
				else
					is_gameover = block.key(is_gameover, key);      //key�Լ�
			}
			else if (i % (block.GetSpeed()) == 0)
			{
				is_gameover = block.move_block();
				block.show_cur_block();
			}

			if (block.GetCLine() <= block.GetLine())   //Ŭ���� ��������
			{
				level = block.GetLevel();
				block.Init();
				block.Set(level + 1, 5);
				block.show_total_block();
				block.show_gamestat();
				block.block_start();

			}
			if (is_gameover == 1)
			{
				show_gameover(block);
				block.InitScore();
				SetColor(GRAY);
				break;
			}

			gotoxy(77, 23);
			Sleep(15);
			gotoxy(77, 23);
		}
		if (finish == 3)
			break;
		block.Init();
		block.InitScore();
	}
	return;
}
void Action::Play1Play2()            // player1 VS player2
{
	Block block1;
	Block block2;

	int level;
	int i;
	int is_gameover = 0;
	int is_gameover2 = 0;
	int finish = 0;

	block1.SetMode(1);
	block2.SetMode(1);
	block1.Init();      //1p
	block2.Init();      //2p
	block2.SetFlag(1);   //2p, flag = 1�� ����

	while (1)
	{
		for (int u = 0; u < 14; u++)
		{
			gotoxy(28 + (u * 2), 5);
			cout << "��";
			gotoxy(54 - (u * 2), 19);
			cout << "��";
			Sleep(20);
		}
		SetColor(GREEN);
		gotoxy(33, 3);
		cout << "�� 1P vs 2P Mode ��";
		SetColor(WHITE);
		gotoxy(37, 6);
		cout << "< 1P KEY >";
		gotoxy(32, 8);
		cout << "��,��,�� : �̵� ";
		gotoxy(32, 9);
		cout << "      �� : ȸ�� ";
		gotoxy(32, 10);
		cout << "   SPACE : �� �ϰ� ";
		gotoxy(37, 13);
		cout << "< 2P KEY >";
		gotoxy(32, 15);
		cout << "  D,F,G : �̵� ";
		gotoxy(32, 16);
		cout << "      R : ȸ�� ";
		gotoxy(32, 17);
		cout << "      Z : �� �ϰ� ";
		SetColor(GRAY);
		gotoxy(32, 21);
		cout << "Press any key to start";
		_getch();
		system("cls");

		level = 7;
		block1.Set(level, 5);
		block2.Set(level, 5);

		block1.show_total_block();
		block2.show_total_block();
		block1.block_start();
		block2.block_start();
		block1.show_gamestat();
		block2.show_gamestat();

		block1.show_inter();
		block2.show_inter();

		is_gameover = 0;
		is_gameover2 = 0;
		finish = 0;

		for (i = 1; i >= 1; i++)
		{
			if (_kbhit())
			{
				char key = _getch();
				if (key == EXT_KEY || key == 32 || key == '7' || key == '8' || key == '9' || key == '0')
					is_gameover = block1.key(is_gameover, key);      //1p key�Լ�
				else if (key == 27) {
					finish = block1.pause();
					if (finish != 0)
						break;
					block2.show_gamestat();
					block2.show_next_block();
					block2.show_cur_block();
					block2.show_total_block();                  //pause
				}
				else
					is_gameover2 = block2.key2(is_gameover2, key);      //2p key�Լ�

			}

			if (i % (block1.GetSpeed()) == 0 || (i % (block1.GetSpeed()) == block1.GetSpeed() / 2))      //
			{
				if (i % (block1.GetSpeed()) == 0)
				{
					/******		Blind Item		********/
					if (block1.GetBlind() != 0) {			// ����ε� ������ ��� �� �� blind������ ������ m_blind������ �Ѱ���
						block2.Setm_Blind(block1.GetBlind());
						block1.SetBlind(0);				//�� blind ���� 0���� �ٲ�
					}
					if (block2.GetBlind() != 0) {
						block1.Setm_Blind(block2.GetBlind());
						block2.SetBlind(0);
					}

					if (block1.Getm_Blind() != 0)
						block1.Setm_Blind(block1.Getm_Blind() - 1);
					if (block2.Getm_Blind() != 0)
						block2.Setm_Blind(block2.Getm_Blind() - 1);


					/****		3������� 1�پ� ���� �� �þ��		***/
					if (block1.GetAtt_Block() >= 3) {
						block2.attack_block(block1.GetAtt_Block() / 3);
						block1.SetAtt_Block(block1.GetAtt_Block() % 3);
					}
					if (block2.GetAtt_Block() >= 3) {
						block1.attack_block(block2.GetAtt_Block() / 3);
						block2.SetAtt_Block(block2.GetAtt_Block() % 3);
					}

					/******		SpeedUp Item			*********/
					if (block1.GetSpeedup() != 0) {			// ���ǵ�� ������ ��� �� �� speedup������ ������ m_speedup������ �Ѱ���
						block2.Setm_Speedup(block1.GetSpeedup());
						block1.SetSpeedup(0);				//�� speedup ���� 0���� �ٲ�
					}

					if (block2.GetSpeedup() != 0) {
						block1.Setm_Speedup(block2.GetSpeedup());
						block2.SetSpeedup(0);
					}

					if (block1.Getm_Speedup() != 0) {
						block1.Setm_Speedup(block1.Getm_Speedup() - 1);
						is_gameover = block1.move_block();
					}

					if (block2.Getm_Speedup() != 0) {
						block2.Setm_Speedup(block2.Getm_Speedup() - 1);
						is_gameover = block2.move_block();
					}

					/******		Switch Item			*********/
					if (block1.GetSwit() == 1)
					{
						block1.Switch_Block(block2.GetTotalBlock());	//�������迭�� �Ѱܼ� �ٲٱ�
						block1.SetSwit(0);
						block1.show_total_block();			//�ٲ� ��� ���
						block2.show_total_block();
						block1.show_cur_block();
						block2.show_cur_block();
					}
					if (block2.GetSwit() == 1)
					{
						block2.Switch_Block(block1.GetTotalBlock());
						block2.SetSwit(0);
						block1.show_total_block();
						block2.show_total_block();
						block1.show_cur_block();
						block2.show_cur_block();
					}

					/***		�����̱�			***/
					is_gameover = block1.move_block();
					block1.show_cur_block();
					is_gameover2 = block2.move_block();
					block2.show_cur_block();
				}

				if (i % (block1.GetSpeed()) != 0 && block1.Getm_Speedup() != 0) //���ǵ�� ������ ��쿡�� ������
				{

					is_gameover = block1.move_block();
					block1.show_cur_block();

				}

				if (i % (block1.GetSpeed()) != 0 && block2.Getm_Speedup() != 0)
				{
					is_gameover2 = block2.move_block();
					block2.show_cur_block();
				}

			}
			if (is_gameover == 1)            //1p ���ӿ���
			{
				show_gameover(block1);
				block1.InitScore();
				SetColor(GRAY);
				block2.InitScore();   // 2p�� �����ʱ�ȭ
				break;
			}
			if (is_gameover2 == 1)         //2p ���ӿ���
			{
				show_gameover(block2);
				block2.InitScore();
				SetColor(GRAY);
				block1.InitScore();   //1p�� ���� �ʱ�ȭ
				break;
			}

			gotoxy(77, 23);
			Sleep(15);
			gotoxy(77, 23);
		}
		if (finish == 3)
			break;
		block1.Init();
		block2.Init();
	}
	return;
}
void Action::Play1Com2() {           // player1 VS complayer2

	Block block1;
	Block block2;

	int level;
	int i;
	int is_gameover = 0;
	int is_gameover2 = 0;
	int finish = 0;
	int c_speed = 0;

	block1.SetMode(2);
	block2.SetMode(2);
	block1.Init();      //1p
	block2.Init();      //2p
	block2.SetFlag(1);   //2p, flag = 1�� ����

	while (1)
	{
		level = 6;
		block1.Set(level, 5);
		block2.Set(level, 5);

		block1.show_total_block();
		block2.show_total_block();
		block1.block_start();
		block2.block_start();
		block1.show_gamestat();
		block2.show_gamestat();

		block1.show_inter();
		block2.show_inter();

		is_gameover = 0;
		is_gameover2 = 0;
		finish = 0;

		for (i = 1; i >= 1; i++)
		{
			c_speed = 10;
			if (_kbhit())
			{
				char key = _getch();
				if (key == EXT_KEY || key == 32 || key == '7' || key == '8' || key == '9' || key == '0')
					is_gameover = block1.key(is_gameover, key);      //1p key�Լ�
				else if (key == 27) {
					finish = block1.pause();
					if (finish != 0)
						break;
					block2.show_gamestat();
					block2.show_next_block();
					block2.show_cur_block();
					block2.show_total_block();                  //pause
				}
			}

			if (i % (c_speed) == 0) {					// computer���
				is_gameover2 = block2.com(is_gameover);
			}

			if (i % (block1.GetSpeed()) == 0)      //
			{

				/****		3������� 1�پ� ���� �� �þ��		***/
				if (block1.GetAtt_Block() >= 3) {
					block2.attack_block(block1.GetAtt_Block() / 3);
					block1.SetAtt_Block(block1.GetAtt_Block() % 3);
					//block2.c_direction();
				}
				if (block2.GetAtt_Block() >= 3) {
					block1.attack_block(block2.GetAtt_Block() / 3);
					block2.SetAtt_Block(block2.GetAtt_Block() % 3);
				}

				/***		�����̱�			***/
				is_gameover = block1.move_block();
				block1.show_cur_block();

				is_gameover2 = block2.move_block();
				block2.show_cur_block();

			}
			if (is_gameover == 1)            //1p ���ӿ���
			{
				show_gameover(block1);
				block1.InitScore();
				SetColor(GRAY);
				break;
			}
			if (is_gameover2 == 1)         //2p ���ӿ���
			{
				show_gameover(block2);
				block2.InitScore();
				SetColor(GRAY);
				break;
			}

			gotoxy(77, 23);
			Sleep(15);
			gotoxy(77, 23);
		}
		if (finish == 3)
			break;
		block1.Init();
		block2.Init();
	}
	return;
}
