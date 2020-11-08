#include "japplet.h"

//函数的定义
void Menu(){
	printf("*****************************\n");
	printf("*******1、play   2、exit ****\n");
	printf("*****************************\n");
	printf("please input your select:");
}

static void PlayerMove(char board[][COL], int row, int col){
	int x = 0;
	int y = 0;
	int quit = 0;
	while (!quit){
		printf("请下棋（输入落子的位置）：");
		scanf("%d %d", &x, &y);
		//验证落子的位置是否不妥
		if (x<1 || x>3 || y<1 || y>3){
			printf("输入位置有误！请重新输入！");
			continue;
		}
		if (board[x - 1][y - 1] != ' '){
			printf("你输入的位置已经有棋子了！请重新输入！");
			continue;
		}
		board[x - 1][y - 1] = PLAYER_CHESS;
		quit = 1;
	}
}
static char Judge(char board[][COL], int row, int col){
	//检测行是否三子连珠
	for (int i = 0; i < row; i++){
		if (board[i][0] == board[i][1] && \
			board[i][1] == board[i][2] && \
			board[i][0] != ' '){
			return board[i][0];
		}
	}
	//检测列是否三子连珠
	for (int i = 0; i < col; i++){
		if (board[0][i] == board[1][i] && \
			board[1][i] == board[2][i] && \
			board[0][i] != ' '){
			return board[0][i];
		}
	}
	//检测正对角线是否三子连珠
	if (board[0][0] == board[1][1] && \
		board[1][1] == board[2][2] && \
		board[0][0] != ' '){
		return board[0][0];
	}
	//检测负对角线是否三子连珠
	if (board[0][2] == board[1][1] && \
		board[1][1] == board[2][0] && \
		board[1][1] != ' '){
		return board[0][2];
	}
	//还在游戏中并没有下满，并且还没有三子连珠，程序能运行到这里说明前面都不符合
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			if (board[i][j] == ' '){
				return PLAYING;
			}
		}
	}
	return DRAW;
}
static void ComputerMove(char board[][COL], int row, int col){
	while (1){
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' '){
			board[x][y] = COMPUTER_CHESS;
			break;
		}
	}
}
void ShowBoard(char board[][COL], int row, int col){
	printf("  | 1 | 2 | 3 |\n");
	printf("---------------\n");
	for (int i = 0; i < row; i++){
		printf("%d |", i + 1);
		for (int j = 0; j < col; j++){
			printf(" %c |", board[i][j]);
		}
		printf("\n---------------\n");
	}
}
//游戏的主要逻辑
void Game(){
	srand((unsigned long)time(NULL));//随机数种子
	 //棋盘的定义和初始化
	char board[ROW][COL];
	memset(board, ' ', sizeof(board));
	char result = 'x';
	do{
		ShowBoard(board,ROW,COL);
		PlayerMove(board,ROW,COL);
		result = Judge(board, ROW, COL);
		if (result != PLAYING){
			//证明此时的结果只有胜负和平局（反正就是已经出结果了）
			break;
		}
		ComputerMove(board, ROW, COL);
		result = Judge(board, ROW, COL);
		if (result != PLAYING){
			//证明此时的结果只有胜负和平局（反正就是已经出结果了）
			break;
		}
	} while (1);
	if (PLAYER_CHESS==result){
		printf("恭喜你，你赢了！\n");
	}
	else if (COMPUTER_CHESS == result){
		printf("很遗憾你输了!\n");
	}
	else{
		printf("平局！\n");
	}
	printf("￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥\n");
	ShowBoard(board, ROW, COL);
}