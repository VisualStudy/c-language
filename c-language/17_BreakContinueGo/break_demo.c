#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 100; i++)
    {
        if (i == 5)
        {
            break;
        }
        printf("%d\t", (i + 1));
    }
    printf("\n");

    return 0;
}