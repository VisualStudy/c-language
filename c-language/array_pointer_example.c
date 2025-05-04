#include <stdio.h>

int main(void)
{
    int numbers[5] = {10,};

	for (int i = 0; i < 5; i++)
	{
		printf("이것은 배열: %d\n", numbers[i]);
	}

	return 0;
}