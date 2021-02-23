#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void game()
{
	printf("扫雷\n");
	//雷信息的存储
	//1.布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };
	//2.排查出的雷的信息
	char show[ROWS][COLS] = { 0 };// show[][]设置为 11*11 ,便于两个数组完美的对应
	//初始化
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');
	//打印棋盘
	/*Displayboard(mine, ROW, COL);*/

	Displayboard(show, ROW, COL);
	//布置雷
	Setmine(mine, ROW, COL);
	/*Displayboard(mine, ROW, COL);
	//函数的作用就是改变 数组 mine 的状态，mine不是一成不变的
	//因此 Displayboard 展现的就是已经被 Setmine 改变过的 mine 
	//这里不能写 Setmine 函数*/

	//扫雷
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
		printf("请输入:>");
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
			printf("选择错误，请重新输入:>\n");
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