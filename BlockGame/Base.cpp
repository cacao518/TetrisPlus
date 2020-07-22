#pragma once

#include "Base.h"

int Base::ghost = 1; // 1:on 0:off

Base::Base()
{
	speed = 0;
	stick_rate = 0;
	clear_line = 0;
	level = 0;
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 14; j++)
			total_block[i][j] = 7;
	}
	for (int i = 0; i < 4; i++) {
		item[i] = 0;
	}
	score = 0;
	lines = 0;

}