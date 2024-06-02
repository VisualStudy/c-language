#include <stdio.h>
#pragma warning (disable:4996)
#define N 501 // N = 501 

int main(void) // 별표 사각형 ( 10 X 50 ) 작성
{
	int count = 0;
	int prime[N];

	for (int i = 0; i < N; i++) // 배열요소에 1 입력 (소수로 가정)
	{
		prime[i] = 1;
	}

	prime[0] = prime[1] = 0; // 0~1은 소수에서 제외
	for (int i = 2; i < N; i++) // 2부터 시작
	{
		if (prime[i] == 1) // 소수인 경우에만 작동
		{
			for (int j = 2; j < N; j++)
			{
				if (i * j < N)
				{
					prime[i * j] = 0;
				}
			}
		}
	}
	for (int i = 2; i < N; i++)
	{
		if (prime[i] == 1) // i가 소수라면?
		{
			printf("%3d", i);
			count++;
			if (count % 10 == 0)
			{
				printf("\n");
			}
		}
	}

    return 0;
}