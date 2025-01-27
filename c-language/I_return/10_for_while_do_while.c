#include <stdio.h>

int main(void)
{
    int i, sum = 0;

	// for 반복문: 1부터 10까지 합 구하기
	for ( i = 1; i <= 10; i++)
	{
		sum += i;
	}
	printf("1~10 sum: %d\n", sum);

	// while 반복문: 숫자 맞히기 게임
	int secret = 7, guess = 0;
	while (guess != secret)
	{
		printf("숫자 맞추기 (1부터 10까지): ");
		scanf("%d", &guess);
	}
	printf("success\n");

	// do-while 반복문: 최소 한 번 실행 후 조건 검사
	int num;
	do
	{
		printf("1 이상 숫자 입력: ");
		scanf("%d", &num);
	} while (num < 1); // 빠져나가기 위해
	printf("입력한 숫자: %d\n", num);

	// for: 반복 횟수가 명확할 때, while: 조건이 참인 동안 반복
	// do while: 먼저 실행, 후 검사
	return 0;
}