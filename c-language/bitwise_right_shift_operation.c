#include <stdio.h>

main() {
    int num = 1640;
    printf("%d\n", num >> 1); // 1640 / 2^1 = 820
    printf("%d\n", num >> 2); // 1640 * 1 / 2^2 = 410
}