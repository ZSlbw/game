#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//二维数组在传参时，可以省略行，但不能省略列
void Initboard(char board[ROWS][COLS], int rows, int cols, char set)
{               // char board[][COLS], int rows, int cols, char set
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void Displayboard(char board[ROWS][COLS], int row, int col)
{
	//打印列号
	for (int i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
			//若写成 printf("%c ",board);  则系统不清楚该打印什么。
		}
		printf("\n");
	}
}

void Setmine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
			//若在声明出写入 #define count 10 ，则count为常量，不能用count--；
			//但引入 int count,则count为变量，仅仅是赋值为10； 
		}
	}
}


int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}

void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col - EASY_COUNT)
	{
		printf("请输入坐标:> ");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("对不起，你被炸死了!\n");
				Displayboard(mine, row, col);
				break;
			}
			else
			{
				int count = get_mine_count(mine,x,y);
				show[x][y] = count+'0';
				Displayboard(show, row, col);
				win++;
			}
		}
		else
			printf("坐标不合法，请从新输入:>\n");
	}
	if (win == row*col - EASY_COUNT)
	{
		printf("恭喜通关！\n");
		Displayboard(mine, ROW, COL);
	}
}