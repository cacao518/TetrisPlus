#pragma once

class Base {
public:
	Base();
	int   speed;   //���ڰ� �������� �ӵ��� ������
	int stick_rate;      //���밡 ������ Ȯ�� 0~99 , 99�� ����⸸ ����
	int clear_line;
	int level;
	int total_block[21][14];      //ȭ�鿡 ǥ�õǴ� ���� -1:��, 7:�����, 1~6:�������κ�
	static int ghost; // ���ɺ�� on/off ����

	int score;
	int lines;
	bool item[4];
	int game_mode;

};
