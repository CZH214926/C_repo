#include "contact.h"

int main()
{
	//��ʼ��ͨѶ¼
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
			SaveContact(ct);//��ͨѶ¼�˳���ʱ�򱣴�ͨѶ¼��Ӳ��
			break;
		}
	}
	printf("ByeBye!\n");
	system("pause");
	return 0;
}