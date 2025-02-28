#include <stdio.h>

int main(void)
{
    int i, a[5], temp;
    for (i = 0; i < 5; i++)
    {
        a[i] = i + 1;
        printf("%d", a[i]);
    }

    printf("\n");
    temp = a[0];
    for (i = 0; i < 4; i++)
    {
        a[i] = a[i + 1];
    }
    a[4] = temp;
    for (i = 0; i < 5; i++)
    {
        printf("%d", a[i]);
    }

    return 0;
}