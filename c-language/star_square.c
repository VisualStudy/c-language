#include <stdio.h>
#pragma warning (disable:4996)
#define N 501 // N = 501 

int main(void) // ��ǥ �簢�� ( 10 X 50 ) �ۼ�
{
	int i = 0;
	int count = 0;
	int prime[N];

	for (i = 0; i < N; i++) // �迭��ҿ� 1 �Է�(�Ҽ��� ����)
		prime[i] = 1;
	prime[0] = prime[1] = 0; //0~1�� �Ҽ����� ����
	for (i = 2; i < N; i++) // 2���� �����Ѵ�.
		if (prime[i] == 1) // �Ҽ��� ��쿡�� �۵�
			for (int j = 2; j < N; j++)
				if (i * j < N) prime[i * j] = 0;
	for (i = 2; i < N; i++)
	{
		if (prime[i] == 1)  // i�� �Ҽ��̸�?
		{
			printf("%3d ", i);
			count++;
			if (count % 10 == 0) printf("\n");
		}
	}

    return 0;
}