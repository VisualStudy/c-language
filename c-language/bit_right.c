#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num = 1640;
    printf("%d\n", num >> 1); // 1640 / (2^1) = 820
    printf("%d\n", num >> 2); // 1640 * (1 / 2^2) = 410
    printf("%d\n", num >> 3); // 1640 * (1 / 2^3) = 205

    return EXIT_SUCCESS; // return 0;�� ���� �ǹ�;
};