#include <stdio.h>
#pragma warning (disable:4996)

int main(void) // 정수 2개 입력 받아서 최대공약수 찾기
{
    int _ = 0;
    int x = 0;
    int y = 0;
    int r = 0;

    printf("\n 정수 2개 입력 ( 큰 값 / 작은 값) :  ");
    _ = scanf("%d%d", &x, &y);
    
    while (y != 0)
    {
        r = x % y;
        x = y;
        y = r;
    } 
    // 최대공약수 = x
    
    printf("\n\n 최대공약수 = %d", x);

    return 0;
}