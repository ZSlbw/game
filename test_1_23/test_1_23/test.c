#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h> 
#include<stdlib.h>
#include<time.h>

void menu()
{
	printf("1.play   0.exit\n");
}

void game()
{
	int ret = 0;
	int guess = 0;
	ret = rand() % 100;//����һ�������
	//printf("%d\n",ret);
	printf("�������>:");
	while (1)
	{
		scanf("%d", &guess);
		if (guess>ret)
			printf("�´���\n");
		else if (guess<ret)
			printf("��С��\n");
		else
		{
			printf("��ȷ\n");
			break;
		}
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	//** unsigned int ��timeǰ�����ͣ���ʱ���÷���srand�ĺ������ø�ʽ����
	//time����ǰ������������ time_t ,ת��������ָ����������ͣ���˿���ǿ��ת��
	//time_t time(time_t*timer)
	//NULL -> time_t*timer
	do
	{
		menu();
		printf("��ѡ��>:");
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
			printf("�޷�ʶ��,���������\n");
			break;
		}
	} while (input);
	return 0;
}