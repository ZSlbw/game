#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("*********************\n");
	printf("** 1.play   0.exit **\n");
	printf("*********************\n");
}

//��Ϸ�������㷨
void game()
{
	char ret = 0;
	//����-����߳���������Ϣ
	char board[ROW][COL] = { 0 };
	//��ʼ������
	Initboard(board, ROW, COL);
	//��ӡ����
	Displayboard(board, ROW, COL);
	//����
	while (1)
	{
		//�������
		PlayerMove(board,ROW,COL);
		Displayboard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret = Is_win(board,ROW,COL);
		if (ret != 'C')
			break;
		//��������
		ComputerMove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		ret = Is_win(board,ROW,COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
		printf("���ʤ\n");
	else if (ret == '#')
		printf("����ʤ\n");
	else
		printf("ƽ��\n");
}



void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("������>��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}