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
		//��ӡ����
		for (j = 0; j < col; j++)
		{
			printf(" %c ",board[i][j]);
			if (j<col-1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			//��ӡ�ָ���
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
	printf("�����:>\n");
	while (1)
	{
		printf("��ѡ������>: ");
		//scanf����������ʱ���м�����ÿո������
		scanf("%d%d", &x, &y);
		//�ж�����ĺϷ��� 
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("��������ռ��,�����³���\n");
		}
		else
		{
			printf("�Ƿ��������꣬����������\n");
		}
	}
}



void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������>:\n");
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
	//�жϺ�����
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//�ж�������
	for (int i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//�����Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	//�ж��Ƿ�ƽ��
	if (IsFull(board,ROW,COL)== 1)//������Ƕ��
		return 'Q';
	return 'C';
}

//����1����ʾ��������
//����0����ʾ����û��
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