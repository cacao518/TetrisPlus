#pragma once

#include "Block.h"

class Action {
public:

	int show_logo(Block block);
	void ShowMenu(int* menu);
	void GameManager(int* menu);
	int input_data(int mode);
	int show_gameover(Block block);


	void opening();
	void Play1();
	void Play1Play2();
	void Play1Com2();
	void HardPlay1();
	void Option();
};