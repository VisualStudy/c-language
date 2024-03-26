#include <stdio.h>

int main(void)
{
    int intArray[3] = { 0, };

    intArray[0] = 10;
    intArray[1] = 20;
    intArray[2] = 30;

    for (int i = 0; i < 3; i++)
    {
        printf("%d, %d\n", i, intArray[i]);
    }
    return 0;
}