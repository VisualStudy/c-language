#include <stdio.h>

int main(void)
{
    int i, sum = 0;

	for ( i = 1; i <= 10; i++)
	{
		sum += i;
	}
	printf("1~10 sum: %d\n", sum);

	int secret = 7, guess = 0;
	while (guess != secret)
	{
		printf("숫자 맞추기 (1부터 10까지): ");
		scanf("%d", &guess);
	}
	printf("success\n");

	int num;
	do
	{
		printf("1 이상 숫자 입력: ");
		scanf("%d", &num);
	} while (num < 1);
	printf("입력한 숫자: %d\n", num);

	return 0;
}