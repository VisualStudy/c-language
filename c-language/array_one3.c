#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int intArray[3] = { 100, 200, 300 };

    for (int i = 0; i < 3; i++)
    {
        printf("%d: %d\n", i, intArray[i]);
    }

    return EXIT_SUCCESS;
}