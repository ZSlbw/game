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
	ret = rand() % 100;//生成一个随机数
	//printf("%d\n",ret);
	printf("请猜数字>:");
	while (1)
	{
		scanf("%d", &guess);
		if (guess>ret)
			printf("猜大了\n");
		else if (guess<ret)
			printf("猜小了\n");
		else
		{
			printf("正确\n");
			break;
		}
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	//** unsigned int 是time前的类型，此时正好符合srand的函数调用格式类型
	//time（）前的真正类型是 time_t ,转到定义后发现根本还是整型，因此可以强制转换
	//time_t time(time_t*timer)
	//NULL -> time_t*timer
	do
	{
		menu();
		printf("请选择>:");
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
			printf("无法识别,请从新输入\n");
			break;
		}
	} while (input);
	return 0;
}