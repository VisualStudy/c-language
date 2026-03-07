#include <stdio.h>

int main(void)
{
	printf("피보나치 수열 C언어로 구현하기\n");
	
	int num1;
	int num2;
	int num3;

	num1 = 1;
	num2 = 1;
	num3 = num1 + num2;
	printf("%d + %d = %d\n", num1, num2, num3);

	while (num1 <= 30)
	{
		int i;
		num1 = num2;
		num2 = num3;
		num3 = num1 + num2;

		printf("%d + %d = %d\n", num1, num2, num3);
	}


	return 0;
}