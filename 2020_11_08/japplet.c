#include "japplet.h"

//�����Ķ���
void Menu(){
	printf("*****************************\n");
	printf("*******1��play   2��exit ****\n");
	printf("*****************************\n");
	printf("please input your select:");
}

static void PlayerMove(char board[][COL], int row, int col){
	int x = 0;
	int y = 0;
	int quit = 0;
	while (!quit){
		printf("�����壨�������ӵ�λ�ã���");
		scanf("%d %d", &x, &y);
		//��֤���ӵ�λ���Ƿ���
		if (x<1 || x>3 || y<1 || y>3){
			printf("����λ���������������룡");
			continue;
		}
		if (board[x - 1][y - 1] != ' '){
			printf("�������λ���Ѿ��������ˣ����������룡");
			continue;
		}
		board[x - 1][y - 1] = PLAYER_CHESS;
		quit = 1;
	}
}
static char Judge(char board[][COL], int row, int col){
	//������Ƿ���������
	for (int i = 0; i < row; i++){
		if (board[i][0] == board[i][1] && \
			board[i][1] == board[i][2] && \
			board[i][0] != ' '){
			return board[i][0];
		}
	}
	//������Ƿ���������
	for (int i = 0; i < col; i++){
		if (board[0][i] == board[1][i] && \
			board[1][i] == board[2][i] && \
			board[0][i] != ' '){
			return board[0][i];
		}
	}
	//������Խ����Ƿ���������
	if (board[0][0] == board[1][1] && \
		board[1][1] == board[2][2] && \
		board[0][0] != ' '){
		return board[0][0];
	}
	//��⸺�Խ����Ƿ���������
	if (board[0][2] == board[1][1] && \
		board[1][1] == board[2][0] && \
		board[1][1] != ' '){
		return board[0][2];
	}
	//������Ϸ�в�û�����������һ�û���������飬���������е�����˵��ǰ�涼������
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
//��Ϸ����Ҫ�߼�
void Game(){
	srand((unsigned long)time(NULL));//���������
	 //���̵Ķ���ͳ�ʼ��
	char board[ROW][COL];
	memset(board, ' ', sizeof(board));
	char result = 'x';
	do{
		ShowBoard(board,ROW,COL);
		PlayerMove(board,ROW,COL);
		result = Judge(board, ROW, COL);
		if (result != PLAYING){
			//֤����ʱ�Ľ��ֻ��ʤ����ƽ�֣����������Ѿ�������ˣ�
			break;
		}
		ComputerMove(board, ROW, COL);
		result = Judge(board, ROW, COL);
		if (result != PLAYING){
			//֤����ʱ�Ľ��ֻ��ʤ����ƽ�֣����������Ѿ�������ˣ�
			break;
		}
	} while (1);
	if (PLAYER_CHESS==result){
		printf("��ϲ�㣬��Ӯ�ˣ�\n");
	}
	else if (COMPUTER_CHESS == result){
		printf("���ź�������!\n");
	}
	else{
		printf("ƽ�֣�\n");
	}
	printf("������������������������������������������������������������������������\n");
	ShowBoard(board, ROW, COL);
}