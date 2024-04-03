#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int goal = 0;
    int r = 0;
    printf("10~100:   ");
    r = scanf("%d", &goal);

    for (int i = 1; i <= goal; i++)
    {
        if (i % 3 != 0)
        {
            continue;
        }
        printf("%d\n", i);
    }

    return 0;
}