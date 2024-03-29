#include <stdio.h>

int main(void)
{
    int x = 3;

	switch (x)
	{
		case 1:
			printf("This is 1.\n");
			break;
		case 2:
			printf("This is 2.\n");
			break;
		default:
			printf("not 1 or 2.\n");
			break;
	}

    return 0;
}