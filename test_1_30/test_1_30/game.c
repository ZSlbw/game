#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//��ά�����ڴ���ʱ������ʡ���У�������ʡ����
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
	//��ӡ�к�
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
			//��д�� printf("%c ",board);  ��ϵͳ������ô�ӡʲô��
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
			//����������д�� #define count 10 ����countΪ������������count--��
			//������ int count,��countΪ�����������Ǹ�ֵΪ10�� 
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
		printf("����������:> ");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("�Բ����㱻ը����!\n");
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
			printf("���겻�Ϸ������������:>\n");
	}
	if (win == row*col - EASY_COUNT)
	{
		printf("��ϲͨ�أ�\n");
		Displayboard(mine, ROW, COL);
	}
}