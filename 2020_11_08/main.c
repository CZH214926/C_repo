#include "japplet.h"

//三子棋游戏
int main(){
	int quit = 0;
	int select = 0;
	while (!quit){
		Menu();//菜单
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			Game();
			printf("要不要再来一把！\n");
			break;
		case 2:
			quit = 1;
			break;
		default:
			printf("你输入有误！请重新输入！");
			break;
		}
	}
	printf("ByeBye!\n");
	system("pause");
	return 0;
}