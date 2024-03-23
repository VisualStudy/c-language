#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main(void)
{
    int i = 100;
    int j = 200;
    int temp;

    printf("first: %d, %d\n", i, j);

    temp = i;
    i = j;
    j = temp;

    printf("change: %d, %d\n", i, j);

    return 0;
}