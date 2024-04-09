#include <stdio.h>

int main(void)
{
    int x = 0b1010; //  8+0+2+0 = 10
    int y = 0b1100; //  8+4+0+0 = 12

    printf("%d\n", x);

    printf("%d\n", y);

    printf("%d\n", x & y); // 0b1000 => 8+0+0+0 = 8

    return 0;
}