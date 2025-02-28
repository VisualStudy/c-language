#include <stdio.h>

int main(void)
{
    int intArray[3];

    intArray[0] = 1;
    intArray[1] = 2;
    intArray[2] = 3;

    for (size_t i = 0; i < 3; i++)
    {
        printf("%d, %d\n", i, intArray[i]);
    }

    return 0;
}