#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i,j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void Setmine(char mine[ROWS][COLS], int row, int col)
{
	int count = Easy_Count;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char board[ROWS][COLS], int x, int y)
{
	return  (board[x - 1][y] + board[x - 1][y - 1] + 
			board[x][y - 1] + board[x + 1][y - 1] +
			board[x + 1][y] + board[x + 1][y + 1] + 
			board[x][y + 1] + board[x - 1][y + 1] -
			8 * '0');
}

void Finemine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y;
	int win = 0;
	while (win < row * col - Easy_Count)
	{
		printf("��������Ҫ�Ų������:>");
		scanf("%d%d", &x, &y);
		if (show[x][y] != '*')
		{
			printf("�������ѱ�ռ�ã�����������!\n");
		}
		else
		{
			if (x >= 1 && x <= row && y >= 1 && y <= col)
			{
				if (mine[x][y] == '1')
				{
					printf("���ź����㱻ը����\n");
					DisplayBoard(mine, ROW, COL);
					Sleep(4000);
					system("cls");
					break;
				}
				else
				{
					win++;
					int count = get_mine_count(mine, x, y);
					show[x][y] = count + '0';
					DisplayBoard(show, ROW, COL);
				}
			}
			else
			{
				printf("����Ƿ�������������\n");
			}
		}
	}
	if (win == row * col - Easy_Count)
	{
		printf("��ϲ�㣬�����������꣡\n");
		DisplayBoard(mine, ROW, COL);
		Sleep(4000);
		system("cls");
	}
}