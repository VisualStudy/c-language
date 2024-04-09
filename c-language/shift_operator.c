#include <stdio.h>

int main(void)
{
    int num = 2; // 0010

    int left = num << 1; // 0010 -> 0100: 4
    int right = num >> 1; // 0010 -> 0001: 1 

    printf("%d\n", left); // 4
    printf("%d\n", right); // 1

    return 0;
}