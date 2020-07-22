#include "Block.h"
#include "Action.h"
#include "global.h"

int main()
{
	setCursorView(0);		//커서지우기
	int menu = 0; // 게임종류
	char command[COMMAND_SIZE] = { '\0', };            //화면 확장
	int lines = 30;
	int cols = 100;
	sprintf_s(command, "mode con: lines=%d cols=%d", lines, cols);
	system(command);

	Action action;   
	while(1)
	{
		action.opening();
		action.ShowMenu(&menu);
		action.GameManager(&menu);
		if(menu == 5)
			break;	//게임종료
	}

	return 0;
}
