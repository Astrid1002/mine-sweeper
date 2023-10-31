#include "game.h"

void menu()
{
	printf("******************************\n");
	printf("******* 1.play  0.exit *******\n");
	printf("******************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	Setmine(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	/*DisplayBoard(mine, ROW, COL);*/
	Finemine(mine, show, ROW, COL);
}

	void test()
	{
		int input = 0;
		srand((unsigned int)time(NULL));
		do
		{
			menu();
			printf("请输入选项:>");
			scanf("%d", &input);
			switch (input)
			{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("选择错误，请重新选择\n");
				break;
			}
			if (input != 1)
			{
				Sleep(1000);
				system("cls");
			}
		} while (input);
	}

int main()
{
	test();
	return 0;
}