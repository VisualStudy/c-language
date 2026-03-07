#include <stdio.h>

int main(void)
{
	printf("피보나치 수열 구현하기\n");
	printf("초기값: 1\n");
	
	int num1 = 1;
	int num2 = 1;
	int num3;
	num3 = num1 + num2;

	printf("%d + %d = %d\n", num1, num1, num3);

	return 0;
}