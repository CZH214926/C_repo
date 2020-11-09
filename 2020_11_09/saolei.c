#include "saolei.h"
void Menu(){
	printf("************************\n");
	printf("****1、Play  2 Exit*****\n");
	printf("please input your select:");
	
}
static void ShowLine(int nums)
{
	printf("---");
	for (int i = 0; i < nums; i++){
		printf("-");
	}
	printf("\n");
}

void ShowBoard(char show_board[][COL], int row, int col)
{
	printf("   ");
	for (int i = 1; i < row - 1; i++){
		printf(" %d  ", i);
	}
	printf("\n");
	ShowLine(2 * col + col + 4);

	for (int i = 1; i < row - 1; i++){
		printf("%2d|", i);
		for (int j = 1; j < col - 1; j++){
			printf(" %c |", show_board[i][j]);
		}
		printf("\n");
		ShowLine(2 * col + col + 4);
	}
}

void SetMines(char mine_board[][COL], int row, int col){
	int count = NUMS;
	while (count){
		int x = rand() % 5 + 1;
		int y = rand() % 5 + 1;
		if (mine_board[x][y] == '0'){
			mine_board[x][y] = '1';
			count--;
		}
	}
}
int GetMines(char mine_board[][COL], int row, int col, int x, int y){
	return mine_board[x - 1][y - 1] + mine_board[x - 1][y] + mine_board[x - 1][y + 1] + \
		mine_board[x][y - 1] + mine_board[x][y + 1] + mine_board[x + 1][y - 1] + \
		mine_board[x + 1][y] + mine_board[x + 1][y + 1] - 8 * '0';
}
void Game(){
	char show_board[ROW][COL];
	char mine_board[ROW][COL];
	//初始化两个二维数组，* 和 ‘0’
	memset(show_board, '*', sizeof(show_board));
	memset(mine_board, '0', sizeof(mine_board));

	srand((unsigned long)time(NULL));

	SetMines(mine_board,ROW,COL);//随机设置雷到mine_board
	
	
	int count = (ROW - 2)*(COL - 2) - NUMS;
	int x = 0;
	int y = 0;

	do{
		//开始扫雷
		ShowBoard(show_board, ROW, COL);
		printf("请输入位置：");
		scanf("%d %d", &x, &y);
		if (x<1 || x>10 || y<1 || y>10){
			printf("输入越界请重新输入！\n");
			continue;
		}
		if (show_board[x][y] != '*'){
			printf("这个位置已经排过雷了，请重新输入！！\n");
			continue;
		}
		if (mine_board[x][y] == '1'){
			break;//炸死了
		}
		//走到这里说明没有雷
		//需要统计这个位置周围点的坐标
		int num = GetMines(mine_board,ROW,COL,x, y);//获得周围雷的个数
		//修改show_board
		show_board[x][y] = num + '0';
		count--;
		system("cls");
	} while (count > 0);

	//根据count可以判断是否是炸死的
	if (count > 0){
		printf("你被炸死了！\n");
	}
	else {
		printf("你赢了!\n");
	}
	printf("下面是雷区的排布!\n");
	ShowBoard(mine_board, ROW, COL);

}