#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//声明
void Initboard(char board[ROW][COL], int row, int col);
void Displayboard(char borad[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);

//告诉我们四种游戏状态
//玩家赢 - '*'
//电脑赢 - '#'
//平局   - 'Q'
//继续   - 'C'

char Is_win(char board[ROW][COL], int row, int col);
int IsFull(char board[ROW][COL], int row, int col);



