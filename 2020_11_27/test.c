#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
#if 0
int main()
{
	FILE* pFile;
	int n = 0;
	pFile = fopen("myfile.txt", "rb");
	if (pFile == NULL){
		printf("Error opening file!\n");
	}
	else
	{
		while (fgetc(pFile) != EOF)
		{
			n++;
		}
		if (feof(pFile))
		{
			puts("End-of-File reached.");//�Դ�����
			printf("Total number of bytes read : %d\n", n);
		}
		else
		{
			puts("End-of-File was not reached");
		}
		fclose(pFile);
	}

	system("pause");
	return 0;
}
#endif
/*�ļ��򿪺͹ر�*/
#if 0
int main()
{
	FILE* pf = fopen("myfile.txt", "a");
	if (pf == NULL)
	{
		printf("File open error!\n");
		system("pause");
		return 1;
	}
	else{
		fputs("���Ǹ��Σ�", pf);
		fclose(pf);
	}
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{   //�ļ�ָ��---���
	//���ļ�������Ҫ�ȴ򿪲���
	//fprintf(stdout, "��־��\n");
	FILE* pf = fopen("czh_1.txt", "w");
	if (pf == NULL){
		printf("File Open Error!\n");
	}
	else{
		printf("File Open Sucess!\n");
		/*int c = 'x';
		while (c!=EOF)
		{
			c = fgetc(pf);
			printf("%c ", c);
		}*/
		//fputs("hello chen!hello hao!", pf);
		/*char str[1024];
		fgets(str, 1024, pf);
		printf("%s\n", str);
		fgets(str, 1024, pf);
		printf("%s\n", str);
		fgets(str, 1024, pf);
		printf("%s\n", str);*/
		fprintf(pf, "��־�� %c %d %s ",'c',12,"nike is sb");
		
		fclose(pf);
	}
	system("pause");
	return 0;
}
#endif
int main()
{
	FILE* pf = fopen("czh.txt", "a");
	if (pf == NULL){
		printf("File open error!\n");
	}
	else{
		/*���ļ����в���*/
		for (int i = 'a'; i <= 'z'; i++){
			int pos = ftell(pf);
			printf("%d\n", pos);
			fputc(i, pf);
		}
		//fseek(pf, 0, SEEK_CUR);
		rewind(pf);
		fputs("czh is a sb ", pf);
		fclose(pf);
	}
	system("pause");
	return 0;
}