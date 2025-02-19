#include <stdio.h>

int main(void)
{
    int num1 = 4; // 0100
    int num2 = 4; // 0100
    int num3 = 4; // 0100
    int num4 = 4; // 0100
    int num5 = 4; // 0100

    num1 &= 5; // num1 = num1(0100) & 5(0101) => 0100 = 4(0100)
    num2 |= 1; // num2 = num2(0100) | 1(0001) => 0101 = 5(0101)
    num3 ^= 2; // num3 = num3(0100) ^ 2(0010) => 0110 = 6(0110)
    num4 <<= 1; // num4 = num4(0100) left 1 => result: 8(1000)
    num5 >>= 1; // num5 = num5(0100) right 1 => result: 2(0010)

    printf("%d\n", num1);
    printf("%d\n", num2);
    printf("%d\n", num3);
    printf("%d\n", num4);
    printf("%d\n", num5);

    return 0;
}