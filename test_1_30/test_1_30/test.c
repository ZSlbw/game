#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void game()
{
	printf("ɨ��\n");
	//����Ϣ�Ĵ洢
	//1.���úõ��׵���Ϣ
	char mine[ROWS][COLS] = { 0 };
	//2.�Ų�����׵���Ϣ
	char show[ROWS][COLS] = { 0 };// show[][]����Ϊ 11*11 ,�����������������Ķ�Ӧ
	//��ʼ��
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');
	//��ӡ����
	/*Displayboard(mine, ROW, COL);*/

	Displayboard(show, ROW, COL);
	//������
	Setmine(mine, ROW, COL);
	/*Displayboard(mine, ROW, COL);
	//���������þ��Ǹı� ���� mine ��״̬��mine����һ�ɲ����
	//��� Displayboard չ�ֵľ����Ѿ��� Setmine �ı���� mine 
	//���ﲻ��д Setmine ����*/

	//ɨ��
	//Displayboard(mine, ROW, COL);
	Findmine(mine, show, ROW, COL);
}

void menu()
{
	printf("********************\n");
	printf("****  1.play    ****\n");
	printf("****  2.exit    ****\n");
	printf("********************\n");
}
void test()
{
	int input = 0;
	do
	{
		menu();
		printf("������:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������������:>\n");
			break;
		}
	} while (input);
}

int main()
{
	srand((unsigned int)time(NULL));
	test();
	return 0;
}