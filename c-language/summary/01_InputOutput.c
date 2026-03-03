#include <stdio.h>

int main(void)
{
	int a, b;
	int sum;

	printf("두 정수를 입력하세요: ");
	scanf("%d %d", &a, &b);

	sum = a + b;

	printf("합은 %d입니다. \n", sum);

	return 0;
}