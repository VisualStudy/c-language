#include <stdio.h>

int main(void)
{
    float a = 123.45;
    printf("%08.3f\n", a); // 소수점도 자릿수 포함
    float b;
    int c;
    c = a;
    b = c;
    printf("%6.2f", b);

    return 0;
}