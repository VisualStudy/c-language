#include <stdio.h>

int main(void)
{
	for (int i = 0; i < 5; i += 2)
	{
		printf("%d\n", i); // 0, 2, 4
	}

    return 0;
}