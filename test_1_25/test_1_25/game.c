#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void Initboard(char board[][COL],int row,int col)
{
	for ( int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}


void Displayboard(char board[ROW][COL],int row,int col)
{
	int j = 0;
	for (int i = 0; i < row; i++)
	{
		//打印数据
		for (j = 0; j < col; j++)
		{
			printf(" %c ",board[i][j]);
			if (j<col-1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			//打印分割线
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}


void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("玩家走:>\n");
	while (1)
	{
		printf("请选择坐标>: ");
		//scanf输入两个数时，中间必须用空格键隔开
		scanf("%d%d", &x, &y);
		//判断输入的合法性 
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("该坐标已占用,请重新出入\n");
		}
		else
		{
			printf("非法输入坐标，请重新输入\n");
		}
	}
}



void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走>:\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}


char Is_win(char board[ROW][COL], int row, int col)
{
	//判断横三行
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//判断竖三行
	for (int i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//两个对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	//判断是否平局
	if (IsFull(board,ROW,COL)== 1)//函数的嵌套
		return 'Q';
	return 'C';
}

//返回1，表示棋盘满了
//返回0，表示棋盘没满
int IsFull(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}