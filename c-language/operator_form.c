#include <stdio.h>

int main(void)
{
    int i = 100;
    float j = 123.45678;
    printf("%d %x %o\n", i, i, i);
    printf("%05d %5d\n", i, i);
    printf("%7.1f %f\n", j, j); // float는 실수를 완벽히 표현할 수 없다.
    
    return 0;
}