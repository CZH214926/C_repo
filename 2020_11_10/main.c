#include<stdio.h>
#include<windows.h>
//дһ��С�����ж���Ļ����ֽ���
int check_sys(){
	int i = 1;
	return  *(char*)(&i);
}
int main(){
	int ret = check_sys();
	if (ret){
		printf("С�˻���\n");
	}
	else{
		printf("��˻���\n");
	}

	char a = -1;
	//Ĭ�����з�����
	signed char b = -1;
	unsigned char c = -1;
	char d = -1;
	char e = 'e';
	printf("a = %d,b = %d,c = %d,d= %u,e=%c,e=%d\n", a, b, c,d,e,e);//�з������ʹ�ӡ

	char f = 128;
	printf("f= %u\n", f);//1000 0000===>���ý���ԭ�룬���룬����Ĳ���
	printf("f= %d", f);//Ҫ����ԭ�뷴�벹��Ĳ���
	printf("\nf= %c\n", f);
	

	int i = -20;
	unsigned int j = 10;
	printf("i+j = %d\n", i + j);


	unsigned int g;
	for (g = 9; g >= 0; g--){
		printf("%u\n", g);
		Sleep(1000);
	}//�޷��ŷ�������2��32�η�-1

	unsigned char i = 0;
	for (i = 0; i <= 255; i++){
		printf("hello chenzhihao,%d\n",i);
		Sleep(100);
	}

	char a = -128;//1000 0000
	printf("%d\n", a);
	printf("%u\n", a);

	char b = 128;
	printf("�з�������,b= %d\n", b);
	printf("�޷������ͣ�b= %u\n", b);
	/*
	   ���������ڴ��еĴ洢
	*/
	int n = 9;
	//0000 0000 0000 0000 0000 0000 0000 1001
	float *pf = (float *)&n;
	//0 0000000 00000000000000000001001 ====>EΪȫ0�򸡵������޽ӽ�0����һ����Χ�����Ǽ����
	//��Ϊ����
	printf("%d\n", n);
	printf("%f\n", *pf);

	*pf = 9.0;
	//��-1��^S*M*2^E
	//9.0=>1001.0==>(-1)^0*1.001*2^3
	//S=0;E=3+127=130;M=001
	//��9.0���ڴ��еĴ洢Ϊ
	//0 10000010 00100000000000000000000

	printf("n= %d\n", n);
	//���԰��հ������ͽ����
	//0100 0001 0001 0000 0000 0000 0000 0000 --->����λλ0��������1091567616
	printf("*pf = %f\n", *pf);
	//����flaot �����Ȼ��9.0
	system("pause");
	return 0;
}