#include "Block.h"
#include "Action.h"
#include "global.h"

int main()
{
	setCursorView(0);		//Ŀ�������
	int menu = 0; // ��������
	char command[COMMAND_SIZE] = { '\0', };            //ȭ�� Ȯ��
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
			break;	//��������
	}

	return 0;
}
