#include "contact.h"

int main()
{
	//初始化通讯录
	contact_t* ct = InitContact();
	int quit = 0;
	int select = 0;
	while (!quit){
		Menu();
		printf("please input your select:");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			AddPerson(&ct);
			break;
		case 2:
			DelPerson(ct);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			ShowContact(ct);
			break;
		case 6:
			Clear(ct);
			break;
		case 7:
			break;
		default:
			quit = 1;
			SaveContact(ct);//在通讯录退出的时候保存通讯录到硬盘
			break;
		}
	}
	printf("ByeBye!\n");
	system("pause");
	return 0;
}