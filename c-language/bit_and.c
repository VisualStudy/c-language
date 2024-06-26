#include <stdio.h>

int main(void)
{
    int x = 0b1010; //  8+0+2+0 = 10
    int y = 0b1100; //  8+4+0+0 = 12

    printf("%d\n", x);

    printf("%d\n", y);

    printf("%d\n", x & y); // 0b1000 => 8+0+0+0 = 8

    printf("%d\n", x | y); // 0b1110 => 8+4+2+0 = 14

    printf("%d\n", x ^ y); // 0b0110 => 0+4+2+0 = 6

    printf("%d\n", ~x); // 0b1111_~~~_1111_0101 => -(10) - 1 

    return 0;
}