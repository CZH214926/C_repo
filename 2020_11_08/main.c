#include "japplet.h"

//��������Ϸ
int main(){
	int quit = 0;
	int select = 0;
	while (!quit){
		Menu();//�˵�
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			Game();
			printf("Ҫ��Ҫ����һ�ѣ�\n");
			break;
		case 2:
			quit = 1;
			break;
		default:
			printf("�������������������룡");
			break;
		}
	}
	printf("ByeBye!\n");
	system("pause");
	return 0;
}