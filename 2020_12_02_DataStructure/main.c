#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
/*µÝ¹é½×³Ë*/
long long Factorial(size_t n){
	return n < 2 ? n : Factorial(n)*n;
}
/*µÝ¹éì³²¨ÄÇÆõ*/
long long Fibonacc_r(size_t n){
	return n < 2 ? n : Fibonacc_r(n - 1)*Fibonacc_r(n - 2);
}
/*ÓÅ»¯ì³²¨ÄÇÆõ*/
long long*  Fibonacci(size_t N)
{
	long long* fibArray = (long long*)malloc(sizeof(long long)*(N + 1));
	if (NULL == fibArray){
		printf("malloc error");
		exit(1);
	}
	fibArray[0] = 0;
	if (N == 0){
		return fibArray;
	}
	fibArray[1] = 1;
	for (size_t i = 2; i <= N; i++)
	{
		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
	}
	return fibArray;
	
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	long long * fib = Fibonacci(n);
	for (int i = 1; i <= n; i++)
	{
		printf("%lld\n", fib[i]);
	}
	free(fib);
	system("pause");
	return 0;

}