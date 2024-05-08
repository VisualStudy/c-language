#include <stdio.h>

int main(void)
{
    int x =5;
    {
        int y = 10;
        printf("x = %d, y = %d\n", x, y);
    }
    // y는 블록 밖에서 유효하지 않음
    printf("x = %d\n", x);
    return 0;
}