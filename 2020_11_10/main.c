#include<stdio.h>
#include<windows.h>
//写一个小程序判断你的机器字节序。
int check_sys(){
	int i = 1;
	return  *(char*)(&i);
}
int main(){
	int ret = check_sys();
	if (ret){
		printf("小端机器\n");
	}
	else{
		printf("大端机器\n");
	}

	char a = -1;
	//默认是有符号数
	signed char b = -1;
	unsigned char c = -1;
	char d = -1;
	char e = 'e';
	printf("a = %d,b = %d,c = %d,d= %u,e=%c,e=%d\n", a, b, c,d,e,e);//有符号整型打印

	char f = 128;
	printf("f= %u\n", f);//1000 0000===>不用进行原码，反码，补码的操作
	printf("f= %d", f);//要进行原码反码补码的操作
	printf("\nf= %c\n", f);
	

	int i = -20;
	unsigned int j = 10;
	printf("i+j = %d\n", i + j);


	unsigned int g;
	for (g = 9; g >= 0; g--){
		printf("%u\n", g);
		Sleep(1000);
	}//无符号符号整型2的32次方-1

	unsigned char i = 0;
	for (i = 0; i <= 255; i++){
		printf("hello chenzhihao,%d\n",i);
		Sleep(100);
	}

	char a = -128;//1000 0000
	printf("%d\n", a);
	printf("%u\n", a);

	char b = 128;
	printf("有符号整型,b= %d\n", b);
	printf("无符号整型，b= %u\n", b);
	/*
	   浮点数在内存中的存储
	*/
	int n = 9;
	//0000 0000 0000 0000 0000 0000 0000 1001
	float *pf = (float *)&n;
	//0 0000000 00000000000000000001001 ====>E为全0则浮点数无限接近0，是一个范围，但是计算机
	//认为是零
	printf("%d\n", n);
	printf("%f\n", *pf);

	*pf = 9.0;
	//（-1）^S*M*2^E
	//9.0=>1001.0==>(-1)^0*1.001*2^3
	//S=0;E=3+127=130;M=001
	//则9.0在内存中的存储为
	//0 10000010 00100000000000000000000

	printf("n= %d\n", n);
	//所以按照按照整型解读是
	//0100 0001 0001 0000 0000 0000 0000 0000 --->符号位位0，正数，1091567616
	printf("*pf = %f\n", *pf);
	//按照flaot 解读必然是9.0
	system("pause");
	return 0;
}